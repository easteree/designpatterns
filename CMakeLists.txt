cmake_minimum_required(VERSION 3.20)

project(design_pattern
  VERSION 1.1
  LANGUAGES CXX
)

set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)

add_subdirectory(day_1)
set_target_properties(exercises adapter_demo builder_demo decorator_demo
    PROPERTIES
        FOLDER day_1
)

add_subdirectory(day_2)
set_target_properties(strategy_demo pizza_factory_demo state_counterexample state_musicplayer_demo
    PROPERTIES
        FOLDER day_2
)

add_subdirectory(day_3)
set_target_properties(observer_demo
    PROPERTIES
        FOLDER day_3
)
