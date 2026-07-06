#include "scheduler.h"
#include "drivers.h"
#include "trice.h"
#include "modemControl.h"
#include "temperatureSensor.h"

void HwInit(void)
{
    GpioInit();
    RtcInit();
    UartInit();
    I2cInit();
    SpiInit();
}

int main(void)
{
    HwInit();
    TriceInit();
    ModemControlInit();
    TemperatureAndHumiditySensorInit();

    SchedulerRun();

    return 0;
}
