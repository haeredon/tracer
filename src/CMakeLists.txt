# configure a header file to pass some of the CMake settings
# to the source code
configure_file(config.h.in config.h)

find_package(PcapPlusPlus REQUIRED)


add_library(${PROJECT_NAME} STATIC)


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
        TraceTag.cpp
    PUBLIC FILE_SET HEADERS FILES 
        Tracer.h
        TraceTag.h
        Event.h
        EventDistributer.h
        monitor/AbstractMonitor.h
        storage/AbstractStorage.h
)

target_include_directories("${PROJECT_NAME}" PUBLIC "${PROJECT_BINARY_DIR}")

target_link_libraries("${PROJECT_NAME}" PUBLIC PcapPlusPlus::Pcap++)


install(TARGETS Tracer FILE_SET HEADERS)
