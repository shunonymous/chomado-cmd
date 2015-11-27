cmake_minimum_required(VERSION 2.8)
project(chomado)

# Version
set(VERSION_MAJOR "0")
set(VERSION_MINOR "0")
set(VERSION_PATCH "1")
set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

# C++14
add_definitions(" -Wall -std=c++14") 

add_library(chomadoAA STATIC src/chomadoAA.cpp)

# Boost
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREAD ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost 1.32 COMPONENTS program_options)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(chomado src/chomado.cpp)
  target_link_libraries(chomado ${Boost_LIBRARIES})
  target_link_libraries(chomado chomadoAA)
endif()


