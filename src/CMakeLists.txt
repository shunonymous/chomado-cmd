cmake_minimum_required(VERSION 2.8)

# C++14
add_definitions(" -Wall -std=c++14") 

add_library(chomadoAA STATIC chomadoAA.cpp)

# Boost
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREAD ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost 1.32 COMPONENTS program_options)


if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(chomado chomado.cpp)
  target_link_libraries(chomado ${Boost_LIBRARIES})
  target_link_libraries(chomado chomadoAA)
endif()

