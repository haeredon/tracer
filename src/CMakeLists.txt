# configure a header file to pass some of the CMake settings
# to the source code
configure_file(config.h.in config.h)

find_package(PcapPlusPlus REQUIRED)


add_library(${PROJECT_NAME} STATIC)


target_sources(${PROJECT_NAME} 
    PUBLIC
        events/Event.cpp
        events/HttpTraceEvent.cpp
        storage/StorageCreator.cpp
        storage/memory/MemStorage.cpp
        utility/ProdConsQueue.h
        monitor/MonitorCreator.h        
        TraceTag.cpp
    PUBLIC FILE_SET HEADERS FILES 
        Agent.h
        Tracer.h
        TraceTag.h
        events/Event.h
        EventDistributer.h
        monitor/AbstractMonitor.h
        storage/AbstractStorage.h
)

target_include_directories("${PROJECT_NAME}" PUBLIC "${PROJECT_BINARY_DIR}")

target_link_libraries("${PROJECT_NAME}" PUBLIC PcapPlusPlus::Pcap++)


install(TARGETS Tracer FILE_SET HEADERS)
