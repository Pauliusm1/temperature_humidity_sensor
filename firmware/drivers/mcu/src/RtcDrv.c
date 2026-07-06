#include "CommonTypes.h"
#include "scheduler.h"

void RtcInit(void)
{
    // Do the initialization...
    // Read date from the external flash
    // If it is not valid, put to default value
    // Set up rtc irq that fires every minute
}

eResult_t RtcGetCurrentDate(sDateHex_t* date)
{
    // Read date from RTC registers...
    date->seconds = 1;
    date->minutes = 2;
    date->hours = 3;
    date->days = 4;
    date->years = 5;
    return res_OK;
}

// eResult_t RtcAddLister(void)
// {

// }

void RTC_IRQ(void) // Fires every minute
{
    EventSend(task_lteM, lteMEvt_newMinute);
    EventSend(task_sensor, lteMEvt_newMinute);
}