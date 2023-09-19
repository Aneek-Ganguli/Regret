cmake_minimum_required(VERSION 3.22.1)
project(Sup)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Sup src/main.cpp
                           src/entity.cpp
                           src/building.cpp
                           src/player.cpp
                           src/renderwindow.cpp

                           include/Entity.hpp
                           include/Building.hpp
                           include/Player.hpp
                           include/RenderWindow.hpp
)

target_link_libraries(Sup SDL2 SDL2_image SDL2_ttf)
target_include_directories(Sup PRIVATE include)