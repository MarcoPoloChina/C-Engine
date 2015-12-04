#include "RenderSystem.h"
RenderSystem::RenderSystem(AssetManager* assetManager){
	assetManagerPtr = assetManager;
	init();
}
void RenderSystem::init(){
	_sprites = assetManagerPtr->getSprites();
}
int RenderSystem::addSprite(int index){
	 _currentSprites.push_back(_sprites[index]);
	 return _currentSprites.size()-1;
}
int RenderSystem::addSprite(std::string identifier){
	 _currentSprites.push_back(_sprites[assetManagerPtr->lookUpSprite(identifier)]);
	 return _currentSprites.size()-1;
}
void RenderSystem::update(){
	std::cout << "updating renderSystem" << std::endl;
	for(unsigned int i=0;i<_currentSprites.size();i++){
		//draw each sprites	
		_currentSprites[i].getCurrentAnimation()->draw();
	}
}


