#ifndef SDL_MANAGER_H
#define SDL_MANAGER_H
#include "../Tools.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
struct Settings{
	Settings(int screenWidth=480,int screenHeight=640,int windowPosX=SDL_WINDOWPOS_UNDEFINED, int windowPosY=SDL_WINDOWPOS_UNDEFINED,std::string windowName=""):screenWidth(screenWidth),screenHeight(screenHeight),windowPosX(windowPosX),windowPosY(windowPosY),windowName(windowName){}
	int screenWidth;
	int screenHeight;
	int windowPosX;
	int windowPosY;
	std::string windowName;
};
class SDLManager{
	public:
		SDLManager(Settings windowSettings=Settings()):_windowSettings(windowSettings){init();}
		~SDLManager();
		SDL_Window* getWindow(){return _window;}
		int getWidth(){return _windowSettings.screenWidth;}
		int getHeight(){return _windowSettings.screenHeight;}
		int getWindowPosX(){return _windowSettings.windowPosX;}
		int getWindowPosY(){return _windowSettings.windowPosY;}
		std::string getWIndowName(){return _windowSettings.windowName;}
		void setWindowDimension(int width=-1, int height=-1);
		void setWindowPos(int x=-1,int y=-1);
		void setWidth(int width);
		void setHeight(int height);
		void setWindowPosX(int x);
		void setWIndowPosY(int y);
		void setWindowName(std::string name);
		void update();
	private:
		void init();		
		void destroy();
		SDL_Window* _window;
		SDL_Surface* _screenSurface;
		Settings _windowSettings;
		bool _reloaded;
		

};
#endif
