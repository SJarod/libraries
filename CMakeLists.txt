cmake_minimum_required(VERSION 3.21)

project(libraries)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE ${PROJECT_SOURCE_DIR}/include)
set(SOURCE ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES
	${INCLUDE}/*.h
	${INCLUDE}/*.hpp
	${INCLUDE}/*.inl
	${SOURCE}/*.c
	${SOURCE}/*.cpp
)

add_library(libraries STATIC ${SOURCES})
target_include_directories(libraries PUBLIC ${INCLUDE})

install(TARGETS libraries)
install(
	DIRECTORY ${INCLUDE}/
	DESTINATION include
	FILES_MATCHING
	PATTERN *.h
	PATTERN *.hpp
	PATTERN *.inl
)