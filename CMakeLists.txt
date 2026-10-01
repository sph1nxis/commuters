cmake_minimum_required(VERSION 3.16)

project(commuters CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)

add_library(commuters_engine STATIC
    src/engine/entity/entity.cpp
    src/engine/entity/entity_id.cpp
    src/engine/entity/entity_id_hash.cpp

    src/engine/world/world.cpp
)

target_include_directories(commuters_engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_executable(commuters src/main.cpp)
target_link_libraries(commuters PRIVATE commuters_engine)

enable_testing()
add_subdirectory(tests)

