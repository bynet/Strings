cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 11)
set(PROJECT "QuickSample")
set(USE_BOOST 1)
set(OUTPUT ${PROJECT})


project(${PROJECT})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Common)

if(USE_BOOST)
  find_package(Boost REQUIRED COMPONENTS system log)
  set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
  set(Boost_USE_MULTITHREADED      ON)
endif()

add_subdirectory(launch_thread)
