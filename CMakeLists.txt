cmake_minimum_required(VERSION 3.25)

# set the project name and version
project(Tracer VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(config.h.in config.h)

find_package(PcapPlusPlus REQUIRED)

# add the executable
add_executable(Tracer 
    main.cpp
    src/Event.cpp
    src/Tracer.cpp
    src/EventDistributer.cpp
    src/storage/StorageCreator.cpp
    src/storage/memory/MemStorage.cpp
    src/storage/memory/MemStorageCreator.cpp
    src/parser/ParserCreator.cpp
    src/parser/http/HttpParser.cpp
    src/parser/http/HttpParserCreator.cpp
    src/digester/MonitorDigester.cpp
    src/monitor/network/NetworkMonitor.cpp
    src/monitor/network/NetworkMonitorCreator.cpp
    src/monitor/MonitorCreator.h    
    
)

target_include_directories("${PROJECT_NAME}" PUBLIC "${PROJECT_BINARY_DIR}")

target_link_libraries("${PROJECT_NAME}" PUBLIC PcapPlusPlus::Pcap++)