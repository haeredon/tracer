


add_executable("${PROJECT_NAME}Test")

target_sources("${PROJECT_NAME}Test"
    PUBLIC 
        main.cpp
)

target_link_libraries("${PROJECT_NAME}Test" 
    Tracer
    -lNodeEmulator)


install(TARGETS Tracer FILE_SET HEADERS)
