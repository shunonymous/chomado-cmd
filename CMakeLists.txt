cmake_minimum_required(VERSION 2.8)
project(chomado)

# Version
set(VERSION_MAJOR "0")
set(VERSION_MINOR "0")
set(VERSION_PATCH "1")
set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

# Boost
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREAD ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost 1.32 COMPONENTS program_options)

add_subdirectory(src)
