#include "Engine.h"
Engine::Engine():_renderSystem(RenderSystem(&_assetManager)),_logicSystem(LogicSystem(&_assetManager)),_SDLManager(Settings()),_sceneManager(&_assetManager,&_renderSystem){
}
void Engine::gameLoop(){
	
	_renderSystem.add(0);
	_logicSystem.add(0);
	int frame_counter = 0;
	while (Status::running){
		frame_counter++;
		_renderSystem.update(0.0f);	
		_logicSystem.update(0.0f);
		_SDLManager.update();
		if(frame_counter == 30){
			_renderSystem.remove(0);	
		}
	}
}
void Engine::init(){
	Status::running = true;
	_logicSystem.init();
	gameLoop();
}
void Engine::addLogic(Logic* logicptr){
	_assetManager.addLogic(logicptr);
}

