cmake_minimum_required(VERSION 3.20)

project(day_1)

set(INCLUDE_FILES
  Calculator.hpp
  Operation.hpp
  Stack.hpp
  Addtion.hpp
  Power.hpp
)
list(TRANSFORM INCLUDE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/include/)

set(SOURCE_FILES
  Calculator.cpp
  Addtion.cpp
  GPS.cpp
  Power.cpp
  Stack.cpp
  main.cpp
)
list(TRANSFORM SOURCE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/src/)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
)

set(TAGET_NAME exercises)
add_executable(${TAGET_NAME})

target_include_directories(${TAGET_NAME}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(${TAGET_NAME}
  PRIVATE
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
)

target_compile_features(${TAGET_NAME}
  PRIVATE
    cxx_std_20
)

set_target_properties(${TAGET_NAME} PROPERTIES
  WIN32_EXECUTABLE OFF
)

set(TAGET_NAME adapter_demo)
add_executable(${TAGET_NAME})
target_sources(${TAGET_NAME}
  PRIVATE
    src/adapter_demo.cpp
)
target_compile_features(${TAGET_NAME}
  PRIVATE
    cxx_std_20
)
set_target_properties(${TAGET_NAME} PROPERTIES
  WIN32_EXECUTABLE OFF
)


set(TAGET_NAME builder_demo)
add_executable(${TAGET_NAME})
target_sources(${TAGET_NAME}
  PRIVATE
    src/car_builder.cpp
)
target_compile_features(${TAGET_NAME}
  PRIVATE
    cxx_std_20
)
set_target_properties(${TAGET_NAME} PROPERTIES
  WIN32_EXECUTABLE OFF
)


set(TAGET_NAME decorator_demo)
add_executable(${TAGET_NAME})
target_sources(${TAGET_NAME}
  PRIVATE
    src/decorator.cpp
)
target_compile_features(${TAGET_NAME}
  PRIVATE
    cxx_std_20
)
set_target_properties(${TAGET_NAME} PROPERTIES
  WIN32_EXECUTABLE OFF
)