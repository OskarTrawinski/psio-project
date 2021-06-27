cmake_minimum_required(VERSION 3.19)
project(Project_PSiO)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_PSiO main.cpp Player_car.cpp Player_car.h bad_car.cpp bad_car.h Car.cpp Car.h Background.cpp Background.h)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Project_PSiO sfml-window sfml-graphics)
