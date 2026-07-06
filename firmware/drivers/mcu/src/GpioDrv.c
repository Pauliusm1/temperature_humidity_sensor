#include "CommonTypes.h"

void GpioInit(void)
{
    // Do the initialization...
}

eResult_t GpioSetState(ePin_t pin, ePinState_t state)
{
    if(pin >= pin_last) return res_invalidParam;
    if(state >= io_last) return res_invalidParam;

    // Set gpio register...

    return res_OK;

}

ePinState_t GpioGetState(ePin_t pin)
{
    if(pin >= pin_last) return res_invalidParam;
    
    ePinState_t pinLevel = io_high;

    //pinLevel = read the register...

    return pinLevel;
}