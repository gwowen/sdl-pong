#compiler
CC=clang++

#objects
OBJECTS=main.o introstate.o playstate.o gameengine.o Timer.o Surface.o Bat.o Ball.o GameObject.o

#compiler flags
CPPFLAGS=-Wall -g `sdl-config --cflags`

#linker flags
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image

main: main.cpp
	$(CC) $(CPPFLAGS) -c gameengine.cpp introstate.cpp main.cpp playstate.cpp Timer.cpp Surface.cpp Bat.cpp Ball.cpp GameObject.cpp
	$(CC) $(OBJECTS) $(CPPFLAGS) $(LDFLAGS) -o stateman

#cleanup
clean:
	rm -rf $(OBJECTS)

#EOF
