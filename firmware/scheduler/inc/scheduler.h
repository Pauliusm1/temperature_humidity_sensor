#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "CommonTypes.h"

typedef enum
{
    task_lteM,
    task_sensor,
    task_last
} eTask_t;

typedef void (*taskHandler_t)(void);

eResult_t TaskCreate(eTask_t taskId, taskHandler_t handler);
eResult_t EventSend(eTask_t taskId, uint8_t event);
eResult_t EventRead(eTask_t taskId, uint8_t* event);

void SchedulerRun(void);

#endif /* SCHEDULER_H */
