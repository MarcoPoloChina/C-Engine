CC = g++
CFLAGS = -Wall -std=c++14 -g
OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
PROGRAM = test
all: $(OBJECTS)
	$(CC) -o $(PROGRAM) $(OBJECTS)
main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp
RenderSystem.o: RenderSystem.cpp RenderSystem.h
	$(CC) $(CFLAGS) -c RenderSystem.cpp
AssetManager.o: AssetManager.cpp AssetManager.h
	$(CC) $(CFLAGS) -c AssetManager.cpp
Sprite.o: Sprite.cpp Sprite.h Transform.h 
	$(CC) $(CFLAGS) -c Sprite.cpp
Tools.o: Tools.cpp Tools.h
	$(CC) $(CFLAGS) -c Tools.cpp
clean :
	rm *.o 
