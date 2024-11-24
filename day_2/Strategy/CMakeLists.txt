cmake_minimum_required(VERSION 3.20)

project(Strategy)

set(INCLUDE_FILES
  Context.h
  MergeSort.h
  Policy.h
  QuickSort.h
  StdSort.h
  SortStrategy.h
)
list(TRANSFORM INCLUDE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

set(SOURCE_FILES
  Client.cpp
)
list(TRANSFORM SOURCE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
)

set(TARGET_NAME strategy_demo)
add_executable(${TARGET_NAME})

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