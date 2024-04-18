cmake_minimum_required(VERSION 3.7)

project(PxParser)

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

if(POLICY CMP0077)
  cmake_policy(SET CMP0077 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)

include(CMake/src.cmake)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/Src" FILES ${PX_HEADERS} ${PX_SOURCES})
add_library(PxParser ${PX_HEADERS} ${PX_SOURCES})
target_include_directories(PxParser PUBLIC Src)
target_link_libraries(PxParser PUBLIC)
