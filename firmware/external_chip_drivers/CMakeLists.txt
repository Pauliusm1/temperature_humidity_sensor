add_library(external_chip_drivers STATIC
    src/sensor_drv.c
)

target_include_directories(external_chip_drivers
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_link_libraries(external_chip_drivers
    PUBLIC
        drivers
)

target_compile_options(external_chip_drivers
    PRIVATE
        -Wall
        -Wextra
)
