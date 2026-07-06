add_library(scheduler STATIC
    src/scheduler.c
)

target_include_directories(scheduler
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_link_libraries(scheduler
    PUBLIC
        drivers
)

target_compile_options(scheduler
    PRIVATE
        -Wall
        -Wextra
)
