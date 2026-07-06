#include "scheduler.h"
#include "sensor_drv.h"
#include "time.h"

typedef struct
{
    uint32_t temperature;
    uint32_t humidity;
    uint32_t timestamp;
} sSensorData_t;

static sSensorData_t sensorData = {0};

static void TempSensorEventHandler(void)
{
    eSensorEvt_t event = sensorEvt_last;
    sDateHex_t currentDate = {0};
    while(EventRead(task_sensor, (uint8_t*)&event) == res_OK)
    {
        switch(event)
        {
            case sensorEvt_newMinute:
                RtcGetCurrentDate(&currentDate);
                if((currentDate.minutes == 0) || (currentDate.minutes == 30))
                {
                    SensorReadTemperature(&sensorData.temperature);
                    SensorReadHumidity(&sensorData.humidity);
                    sensorData.timestamp = GetCurrentTimestamp();
                }
                break;
        }
    }
}

void TemperatureAndHumiditySensorInit(void)
{
    SensorInit();
    TaskCreate(task_sensor, TempSensorEventHandler);
}
