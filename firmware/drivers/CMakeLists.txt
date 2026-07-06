add_library(drivers STATIC
    mcu/src/GpioDrv.c
    mcu/src/I2cDrv.c
    mcu/src/PwrDrv.c
    mcu/src/RtcDrv.c
    mcu/src/SpiDrv.c
    mcu/src/UartDrv.c
)

target_include_directories(drivers
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/mcu/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../scheduler/inc
)

target_compile_options(drivers
    PRIVATE
        -Wall
        -Wextra
)
