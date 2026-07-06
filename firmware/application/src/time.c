#include "drivers.h"

#define UNIX_OFFSET 123456789   // Write correct unix offset.

static uint32_t ConverDateToTimestamp(sDateHex_t *date)
{
    // Convert date to timestamp ...
    return 123456789;
}

uint32_t GetCurrentTimestamp(void)
{
    sDateHex_t currentDate = {0};
    RtcGetCurrentDate(&currentDate);
    return ConverDateToTimestamp(&currentDate) + UNIX_OFFSET;
}