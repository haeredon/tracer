cmake_minimum_required(VERSION 3.25)

# set the project name and version
project(Tracer VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_BUILD_TYPE Debug)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(config.h.in config.h)

find_package(PcapPlusPlus REQUIRED)


add_library(${PROJECT_NAME} SHARED)


target_sources(${PROJECT_NAME} 
    PUBLIC
        Event.cpp
        Tracer.cpp
        EventDistributer.cpp
        storage/StorageCreator.cpp
        storage/memory/MemStorage.cpp
        storage/memory/MemStorageCreator.cpp
        monitor/network/NetworkMonitor.cpp
        monitor/network/NetworkMonitorCreator.cpp
        monitor/MonitorCreator.h        
    PUBLIC FILE_SET HEADERS FILES 
        Tracer.h
        Event.h
        EventDistributer.h
        monitor/AbstractMonitor.h
        storage/AbstractStorage.h
)

target_include_directories("${PROJECT_NAME}" PUBLIC "${PROJECT_BINARY_DIR}")

target_link_libraries("${PROJECT_NAME}" PUBLIC PcapPlusPlus::Pcap++)


install(TARGETS Tracer FILE_SET HEADERS)
