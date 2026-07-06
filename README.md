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

## Build

Native (host):

```powershell
cmake -S . -B build
cmake --build build
```

Or simply by pressing "Build" button on vs code.

## Known limitations

Most parts are unfinnished. Since I have minimal experience with RTOS, I decided to make my own scheduler.
Unfinished parts:
    - Sensor read failure.
    - Data upload to the server part
    - Full buffer handling.
    - Buffer high-water mark. handling.
    - Modem error simulation and handling.
    - Logging module.
    - CRA stuff.