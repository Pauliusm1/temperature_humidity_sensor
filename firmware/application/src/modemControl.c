#include "scheduler.h"

static void ModemEventHandler(void)
{
    // No time to finish...
}

void ModemControlInit(void)
{
    //ModemInit();
    TaskCreate(task_lteM, ModemEventHandler);
}