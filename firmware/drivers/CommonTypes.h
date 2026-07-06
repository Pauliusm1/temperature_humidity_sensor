#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <stdint.h>
#include <stddef.h>

typedef enum
{
    res_OK,
    res_error,
    res_busy,
    res_nullPointer,
    res_invalidParam,
    res_noActionTaken,
    res_overflow,
    re_last
} eResult_t;

typedef enum
{
    io_low,
    io_high,
    io_last
} ePinState_t;

typedef enum
{
    pin_spiMiso,
    pin_spiMosi,
    pin_spiClk,
    pin_uartTx,
    pin_uartRx,
    pin_i2cSda,
    pin_i2cClk,
    // etc...
    pin_last
} ePin_t;

typedef enum
{
    lteMEvt_newMinute,
    lteMEvt_last,
} eLteMEvt_t;

typedef enum
{
    sensorEvt_newMinute,
    sensorEvt_last,
} eSensorEvt_t;

typedef struct
{
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t days;
    uint8_t years;
} sDateHex_t;

#endif /* COMMON_TYPES_H */
