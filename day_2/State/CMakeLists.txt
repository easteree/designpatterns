cmake_minimum_required(VERSION 3.20)

project(State)

set(TARGET_NAME state_musicplayer_demo)

set(INCLUDE_FILES
  MusicPlayer.hpp
  state/State.hpp
  state/On.hpp
  state/Inactive.hpp
  state/Playing.hpp
  state/Paused.hpp
)
list(TRANSFORM INCLUDE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

set(SOURCE_FILES
  MusicPlayer.cpp
  #state_counterexample.cpp
  state_incomplete.cpp
  state/On.cpp
  state/Inactive.cpp
  state/Playing.cpp
  state/Paused.cpp
)
list(TRANSFORM SOURCE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
)

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



set(TARGET_NAME state_counterexample)

set(INCLUDE_FILES
)
list(TRANSFORM INCLUDE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

set(SOURCE_FILES
  state_counterexample.cpp
)
list(TRANSFORM SOURCE_FILES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
)

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