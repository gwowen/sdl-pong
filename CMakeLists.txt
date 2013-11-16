cmake_minimum_required( VERSION 2.8 )

project(pongv3)
add_definitions( `sdl-config --cflags` -g )
add_executable( pongv3 gameengine.cpp introstate.cpp main.cpp playstate.cpp Timer.cpp Surface.cpp Bat.cpp Ball.cpp GameObject.cpp playstateai.cpp)
target_link_libraries( pongv3 -lSDL -lSDL_image )