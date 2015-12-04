CC = g++
CFLAGS = -Wall -std=c++14 -g
LIBRARIES = -lSDL2 -lSDL2_image
OBJECTS = main.o Engine.o RenderSystem.o AssetManager.o Sprite.o SDLManager.o Tools.o Status.o
PROGRAM = test
all: $(OBJECTS)
	$(CC) -o $(PROGRAM)  $(OBJECTS) $(LIBRARIES)
main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp
Engine.o : Engine.cpp Engine.h
	$(CC) $(CFLAGS) -c Engine.cpp
RenderSystem.o: Systems/RenderSystem.cpp Systems/RenderSystem.h
	$(CC) $(CFLAGS) -c  Systems/RenderSystem.cpp
AssetManager.o: AssetManager/AssetManager.cpp AssetManager/AssetManager.h
	$(CC) $(CFLAGS) -c  AssetManager/AssetManager.cpp
Sprite.o: Components/Sprite.cpp Components/Sprite.h Components/Transform.h 
	$(CC) $(CFLAGS) -c  Components/Sprite.cpp
SDLManager.o: SDLManager/SDLManager.cpp SDLManager/SDLManager.h
	$(CC) $(CFLAGS) -c SDLManager/SDLManager.cpp  
Tools.o: Tools.cpp Tools.h
	$(CC) $(CFLAGS) -c Tools.cpp
Status.o: Status.cpp Status.h
	$(CC) $(CFLAGS) -c Status.cpp
clean :
	rm *.o 
