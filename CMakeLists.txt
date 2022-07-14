cmake_minimum_required(VERSION 3.21)

project(libraries_project)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES
	include/*.h
	include/*.hpp
	include/*.inl
	src/*.c
	src/*.cpp
)

add_library(libraries STATIC ${SOURCES})
target_include_directories(libraries PUBLIC include)

#installing the lib
install(TARGETS libraries)
#installing the include files
install(DIRECTORY include/
	DESTINATION include
	FILES_MATCHING
	PATTERN *.h
	PATTERN *.hpp
	PATTERN *.inl
)