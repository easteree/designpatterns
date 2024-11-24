cmake_minimum_required(VERSION 3.20)

project(Observer)

set(INCLUDE_FILES
  stockmanager_observer.hpp
  stockmanger_withoutObserver.hpp
  stockmanager_products_with_observer.hpp
  streaming_platform/Video.hpp
  streaming_platform/Channel.hpp
  streaming_platform/ChannelNotification.hpp
  streaming_platform/SubScriber.hpp
  streaming_platform/StreamingPlatform.hpp
)
list(TRANSFORM INCLUDE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

set(SOURCE_FILES
  stockmanager_observer.cpp
  stockmanager_products_with_observer.cpp
  stockmanger_withoutObserver.cpp
  streaming_platform/Channel.cpp
  streaming_platform/SubScriber.cpp
  streaming_platform/StreamingPlatform.cpp
)
list(TRANSFORM SOURCE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
)

set(TARGET_NAME observer_demo)
add_executable(${TARGET_NAME}
  main.cpp
)

target_include_directories(${TARGET_NAME}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(${TARGET_NAME}
  PRIVATE
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
)

target_compile_features(${TARGET_NAME}
  PRIVATE
    cxx_std_20
)

set_target_properties(${TARGET_NAME} PROPERTIES
  WIN32_EXECUTABLE OFF
)