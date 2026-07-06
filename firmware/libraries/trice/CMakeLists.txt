add_library(trice STATIC
    src/trice.c
)

target_include_directories(trice
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_compile_options(trice
    PRIVATE
        -Wall
        -Wextra
)
