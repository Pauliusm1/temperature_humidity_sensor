#include "sensor_drv.h"
#include "drivers.h"

#define SENSOR_I2C_ADDRESS 0x55
#define READ_BIT 1

//#define TEMPERATURE_SIZE 4
//#define HUMIDITY_SIZE 4

static eResult_t SensorWakeUp(void)
{
    // wake up ...
    return res_OK;
}

static void SensorPutToSleep(void)
{
    // put to sleep ...
}

eResult_t SensorInit(void)
{
    // Set up pins or something else. Depends on the sensor.
    SensorPutToSleep();
    return res_OK;
}



eResult_t SensorReadTemperature(uint32_t* temperature)
{
    if(temperature == NULL) return res_nullPointer;

    eResult_t wakeUpResult = SensorWakeUp();
    if(wakeUpResult != res_OK)
    {
        return wakeUpResult;
    }

    uint32_t temp = 0;
    eResult_t readResult = I2cRW(SENSOR_I2C_ADDRESS + READ_BIT, (uint8_t*)temp, sizeof(temp));

    *temperature = temp;

    SensorPutToSleep();

    return readResult;
}

eResult_t SensorReadHumidity(uint32_t* humidity)
{
    if(humidity == NULL) return res_nullPointer;

    eResult_t wakeUpResult = SensorWakeUp();
    if(wakeUpResult != res_OK)
    {
        return wakeUpResult;
    }

    uint32_t temp = 0;
    eResult_t readResult = I2cRW(SENSOR_I2C_ADDRESS + READ_BIT, (uint8_t*)temp, sizeof(temp));

    *humidity = temp;

    SensorPutToSleep();

    return readResult;
}

// eResult_t SensorReadData(eSensorData_t whichData, uint8_t* buffer, uint8_t bufferLength)
// {
//     if(temperature == NULL) return res_nullPointer;

//     eResult_t wakeUpResult = SensorWakeUp();
//     if(wakeUpResult != res_OK)
//     {
//         return wakeUpResult;
//     }

//     eResult_t readResult = res_noActionTaken;

//     switch(whichData)
//     {
//         case sensor_temperature:
//             if 
//             readResult = I2cRW(SENSOR_I2C_ADDRESS + READ_BIT, buffer, bufferLength);
//             break;
//     sensor_humidity,
//     sensor_someOtherRegister,
//     }

//     uint32_t temp = 0;
//     eResult_t readResult = I2cRW(SENSOR_I2C_ADDRESS + READ_BIT, (uint8_t*)temp, sizeof(temp));

//     *temperature = temp;

//     return readResult;
// }
