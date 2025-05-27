cmake_minimum_required(VERSION 3.5)

project(2dgame_client)

add_subdirectory(src)
add_subdirectory(deps)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(Boost COMPONENTS system regex thread)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} EnTT::EnTT sfml-graphics sfml-audio)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
