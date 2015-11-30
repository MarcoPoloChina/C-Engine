#include "SDLManager.h"
SDLManager::~SDLManager(){
	destroy();
}
void SDLManager::init(){
	_window = SDL_CreateWindow(_windowSettings.windowName.c_str(),_windowSettings.windowPosX,_windowSettings.windowPosY,_windowSettings.screenWidth,_windowSettings.screenWidth,SDL_WINDOW_SHOWN);
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "Error could not init SDL_VIDEO" << std::endl;
		return;
	}
	if(_window == NULL){
		std::cout << "Error could not create window" << std::endl;
		return;
	}
}
void SDLManager::destroy(){
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
void SDLManager::setWindowDimension(int width, int height){
	if(width != -1){	
		_windowSettings.screenWidth = width;
	}
	if(height != -1){
		_windowSettings.screenHeight = height;	
	}
	SDL_SetWindowSize(_window,_windowSettings.screenWidth,_windowSettings.screenHeight);
}
void SDLManager::setWindowPos(int x, int y){
	if(x != -1){	
		_windowSettings.windowPosX = x;
	}
	if(y != -1){
		_windowSettings.windowPosY = y;	
	}
	SDL_SetWindowPosition(_window,_windowSettings.windowPosX,_windowSettings.windowPosY);
}
void SDLManager::setWidth(int width){
	setWindowDimension(width);
}
void SDLManager::setHeight(int height){
	setWindowDimension(-1,height);
}
void SDLManager::setWindowPosX(int x){
	setWindowPos(x);
}
void SDLManager::setWIndowPosY(int y){
	setWindowPos(-1,y);
}
void SDLManager::setWindowName(std::string name){
	_windowSettings.windowName = name;	
	SDL_SetWindowTitle(_window,name.c_str());
}
