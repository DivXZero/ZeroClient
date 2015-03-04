cmake_minimum_required(VERSION 2.8.0)

set(PROJECT_NAME "ZeroClient")
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} main.cpp)

set(ZERO_INCLUDE_DIR "Dependencies/Zero/Include")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})

find_package(ZERO REQUIRED)
if(ZERO_FOUND)
	message(STATUS "Zero Lib Found")
	include_directories(${ZERO_INCLUDE_DIR})
	
	include_directories("Dependencies/Zero/Dependencies/glm")
	include_directories("Dependencies/Zero/Dependencies/rapidjson/include")
	#include_directories("Dependencies/Zero/Dependencies/ruby/usr/include/ruby-2.3.0")
	include_directories("C:/ruby/include/ruby-2.3.0")
	
	target_link_libraries(${PROJECT_NAME} ${ZERO_LIBRARIES})
endif()

file(COPY ${CMAKE_SOURCE_DIR}/hello.rb DESTINATION /)
file(COPY ${CMAKE_SOURCE_DIR}/main.cfg DESTINATION /)