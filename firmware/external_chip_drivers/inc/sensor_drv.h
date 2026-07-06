#ifndef SENSOR_DRV_H
#define SENSOR_DRV_H

#include "CommonTypes.h"

typedef enum
{
    sensor_temperature,
    sensor_humidity,
    sensor_someOtherRegister,
    sensor_last,
} eSensorData_t;

eResult_t SensorInit(void);

eResult_t SensorReadTemperature(uint32_t* temperature);
eResult_t SensorReadHumidity(uint32_t* humidity);

#endif /* SENSOR_DRV_H */
