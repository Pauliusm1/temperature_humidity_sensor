add_library(application STATIC
    src/modemControl.c
    src/temperatureSensor.c
    src/time.c
)

target_include_directories(application
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_link_libraries(application
    PUBLIC
        scheduler
        external_chip_drivers
        drivers
)

target_compile_options(application
    PRIVATE
        -Wall
        -Wextra
)
