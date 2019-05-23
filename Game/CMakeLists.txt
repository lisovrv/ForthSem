cmake_minimum_required(VERSION 3.13)
project(My_Game)

set(EXECUTABLE_NAME "My_Game")
add_executable(${EXECUTABLE_NAME} main.cpp Engine.cpp Object.cpp Hero.cpp Zombie.cpp Zombie.h Health_bar.cpp Health_bar.h Menu.cpp Menu.h)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()