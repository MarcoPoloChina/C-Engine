CC = g++
CFLAGS = -Wall -std=c++14 -g
OBJECTS = main.o RenderSystem.o AssetManager.o Sprite.o Tools.o
PROGRAM = test
all: $(OBJECTS)
	$(CC) -o $(PROGRAM) $(OBJECTS)
main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp
RenderSystem.o: Systems/RenderSystem.cpp Systems/RenderSystem.h
	$(CC) $(CFLAGS) -c  Systems/RenderSystem.cpp
AssetManager.o: AssetManager/AssetManager.cpp AssetManager/AssetManager.h
	$(CC) $(CFLAGS) -c  AssetManager/AssetManager.cpp
Sprite.o: Components/Sprite.cpp Components/Sprite.h Components/Transform.h 
	$(CC) $(CFLAGS) -c  Components/Sprite.cpp
Tools.o: Tools.cpp Tools.h
	$(CC) $(CFLAGS) -c Tools.cpp
clean :
	rm *.o 
