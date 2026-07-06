# Temperature Humidity Sensor

Embedded firmware project for a temperature and humidity sensor.

## Project structure

```
temperature_humidity_sensor/
├── build/                  # CMake build output (generated)
├── cmake/                  # Toolchain files
├── firmware/
│   ├── main.c              # Application entry point
│   ├── drivers/
│   │   ├── drivers.h       # Public MCU driver interface
│   │   ├── CommonTypes.h
│   │   └── mcu/src/        # MCU-specific driver sources
│   ├── external_chip_drivers/
│   │   ├── inc/
│   │   └── src/            # Off-MCU chip drivers (e.g. sensor)
│   ├── libraries/
│   │   └── trice/          # Logging library
│   ├── application/
│   │   ├── src/
│   │   └── inc/
│   └── scheduler/
│       ├── src/
│       └── inc/
└── CMakeLists.txt
```
