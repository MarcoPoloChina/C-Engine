#include "Engine.h"
Engine::Engine():_renderSystem(RenderSystem(&_assetManager)),_SDLManager(Settings()){
	init();
}
void Engine::gameLoop(){
	_renderSystem.addSprite(0);
	while (Status::running){
		_renderSystem.update();	
		_SDLManager.update();
	}
}
void Engine::init(){
	Status::running = true;
	gameLoop();
}


