add_subdirectory(drivers)
add_subdirectory(external_chip_drivers)
add_subdirectory(libraries/trice)
add_subdirectory(application)
add_subdirectory(scheduler)

add_executable(${PROJECT_NAME}
    main.c
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        application
        trice
)

if(EMBEDDED_BUILD)
    target_compile_definitions(${PROJECT_NAME}
        PRIVATE
            EMBEDDED_BUILD=1
    )
endif()
