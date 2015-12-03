#include "RenderSystem.h"
RenderSystem::RenderSystem(AssetManager* assetManager){
	assetManagerPtr = assetManager;
	init();
}
void RenderSystem::init(){
}
int RenderSystem::addSprite(std::string name){
	 _currentSprites.push_back(_sprites.at(name));
	 return _currentSprites.size()-1;
}
void RenderSystem::update(){
	for(unsigned int i=0;i<_currentSprites.size();i++){
		//draw each sprites	
	}
}


