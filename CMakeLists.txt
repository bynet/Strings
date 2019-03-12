cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 11)
set(OUTPUT "QuickSample")
set(USE_BOOST 0)

project(${OUTPUT})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(${CMAKE_SOURCE_DIR})

add_executable(${OUTPUT} main.cpp)

if(USE_BOOST)

  set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
  set(Boost_USE_MULTITHREADED      ON)

  find_package(Boost REQUIRED COMPONENTS system log)
  if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${OUTPUT} ${Boost_LIBRARIES})
  endif()

endif()





