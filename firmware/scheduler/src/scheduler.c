#include "scheduler.h"
#include "drivers.h"
#include <stdbool.h>

#define EVENT_LIST_SIZE 5

typedef struct
{
    uint8_t list[EVENT_LIST_SIZE];
    uint8_t head;
    uint8_t tail;
} sEvtData_t;

typedef struct
{
    bool isCreated;
    taskHandler_t handler;
    sEvtData_t eventList;
} sTaskCtx_t;

static sTaskCtx_t tasksCtx[task_last] = {0};

static uint8_t currentActiveTasks = 0;

eResult_t TaskCreate(eTask_t taskId, taskHandler_t handler)
{
    if(handler == NULL) return res_nullPointer;
    if(taskId >= task_last) return res_invalidParam;

    if(tasksCtx[taskId].isCreated == true) return res_noActionTaken;

    tasksCtx[taskId].isCreated = true;
    tasksCtx[taskId].handler = handler;
    tasksCtx[taskId].eventList.head++;
    currentActiveTasks++;
    
    return res_OK;
}

eResult_t EventSend(eTask_t taskId, uint8_t event)
{
    if(taskId >= task_last) return res_invalidParam;
    tasksCtx[taskId].eventList.list[tasksCtx[taskId].eventList.head] = event;
    tasksCtx[taskId].eventList.head++;

    if(tasksCtx[taskId].eventList.head >= EVENT_LIST_SIZE)
    {
        tasksCtx[taskId].eventList.head = 0;
    }
    return res_OK;
}

eResult_t EventRead(eTask_t taskId, uint8_t* event)
{
    if(taskId >= task_last) return res_invalidParam;
    if(event == NULL) return res_nullPointer;
    if(tasksCtx[taskId].eventList.head != tasksCtx[taskId].eventList.tail)
    {
        *event = tasksCtx[taskId].eventList.tail;
        tasksCtx[taskId].eventList.tail++;
        if(tasksCtx[taskId].eventList.tail >= EVENT_LIST_SIZE)
        {
            tasksCtx[taskId].eventList.tail = 0;
        }
        return res_OK;
    }
    else
    {
        return res_error;
    }
}

void SchedulerRun(void)
{
    while(1)
    {
        for(uint8_t i = 0; i < currentActiveTasks; i++)
        {
            if((tasksCtx[currentActiveTasks].isCreated == true) && 
            (tasksCtx[currentActiveTasks].eventList.tail !=  tasksCtx[currentActiveTasks].eventList.head))
            {
                tasksCtx[currentActiveTasks].handler();
            }
            
        }
        PwrManageSleep();
    }
}
