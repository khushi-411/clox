cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(clox.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CLOXCPP_ROOT ${PROJECT_SOURCE_DIR})
set(CLOXCPP_SRCS_DIR "${CLOXCPP_ROOT}/src/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(CLOXCPP_SRCS)
list(APPEND CLOXCPP_SRCS
    ${CLOXCPP_SRCS_DIR}/chunk.cpp
    ${CLOXCPP_SRCS_DIR}/debug.cpp
    ${CLOXCPP_SRCS_DIR}/memory.cpp
    ${CLOXCPP_SRCS_DIR}/value.cpp
)

set(CLOXCPP_MAIN_SRC "${CLOXCPP_SRCS_DIR}/main.cpp")

add_library(${PROJECT_NAME} SHARED ${CLOXCPP_SRCS})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wno-unused-function)

target_include_directories(${PROJECT_NAME} PUBLIC ${CLOXCPP_SRCS_DIR})

add_executable(main ${CLOXCPP_MAIN_SRC})
target_link_libraries(main ${PROJECT_NAME})
