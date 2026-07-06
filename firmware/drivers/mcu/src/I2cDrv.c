#include "CommonTypes.h"

void I2cInit(void)
{
    // Do the initialization...
}

eResult_t I2cRW(uint8_t address, uint8_t* buffer, uint8_t length)
{
    // Read or write specified amount of bytes from provided register and put them to the buffer
    uint32_t temp = 5;
    memcpy(buffer, (uint8_t*)&temp, sizeof(temp)); 
    return res_OK;
}
