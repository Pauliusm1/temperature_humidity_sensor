#ifndef DRIVERS_H
#define DRIVERS_H

#include "CommonTypes.h"

//---------------------- GPIO ---------------------------------
void GpioInit(void);
eResult_t GpioSetState(ePin_t pin, ePinState_t state);
ePinState_t GpioGetState(ePin_t pin);

//---------------------- RTC ---------------------------------
void RtcInit(void);
eResult_t RtcGetCurrentDate(sDateHex_t* date);

//---------------------- UART --------------------------------
void UartInit(void);

//---------------------- I2C ----------------------------------
void I2cInit(void);
eResult_t I2cRW(uint8_t address, uint8_t* buffer, uint8_t length);

//---------------------- SPI ----------------------------------
void SpiInit(void);

//---------------------- PWR ----------------------------------
void PwrAddActiveMode(void);
void PwrRemoveActiveMode(void);
void PwrAddHaltMode(void);
void PwrRemoveHaltMode(void);
void PwrManageSleep(void);

#endif /* DRIVERS_H */
