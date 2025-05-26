cmake_minimum_required(VERSION 3.5)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} MAIN_SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/systems SYSTEMS_SRC)

set(SOURCES ${SOURCES} ${MAIN_SRC} ${SYSTEMS_SRC} PARENT_SCOPE) 
