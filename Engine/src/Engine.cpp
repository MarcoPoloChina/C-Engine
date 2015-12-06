#include "Engine.h"
Engine::Engine():_renderSystem(RenderSystem(&_assetManager)),_SDLManager(Settings()){
	init();
}
void Engine::gameLoop(){
	_renderSystem.add(0);
	while (Status::running){
		_renderSystem.update(0.0f);	
		_SDLManager.update();
	}
}
void Engine::init(){
	Status::running = true;
	gameLoop();
}


