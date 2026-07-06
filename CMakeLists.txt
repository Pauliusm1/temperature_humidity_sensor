cmake_minimum_required(VERSION 3.20)

project(temperature_humidity_sensor
    VERSION 0.1.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(EMBEDDED_BUILD "Cross-compile for embedded target" OFF)

if(EMBEDDED_BUILD)
    if(NOT CMAKE_TOOLCHAIN_FILE)
        set(CMAKE_TOOLCHAIN_FILE
            "${CMAKE_SOURCE_DIR}/cmake/arm-none-eabi-gcc.cmake"
            CACHE FILEPATH "Toolchain file" FORCE
        )
    endif()
endif()

add_subdirectory(firmware)
