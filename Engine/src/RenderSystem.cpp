#include "RenderSystem.h"
void RenderSystem::init(){
	_sprites = _assetManagerPtr->getSprites();
}
void RenderSystem::internalAdd(int indexOfRefrence,int index){
	Tools::PrintDebug("adding sprite");
	if(index >= _currentSprites.size() || index < 0){
		_currentSprites.push_back(_sprites[indexOfRefrence]);
	}else{
		_currentSprites[index] = _sprites[indexOfRefrence];
	}
}
void  RenderSystem::internalAdd(std::string identifier,int index){
	Tools::PrintDebug("adding sprite");
	if(index >= _currentSprites.size() || index < 0){
		_currentSprites.push_back(_sprites[_assetManagerPtr->lookUpSprite(identifier)]);
	}else{
		_currentSprites[index] = _sprites[_assetManagerPtr->lookUpSprite(identifier)];
	}
}
void RenderSystem::internalUpdate(double dt){
	std::cout << "updating renderSystem" << std::endl;
	for(unsigned int i=0;i<_currentSprites.size();i++){
		//draw each sprites	
		if(_currentSprites[i].active){
			_currentSprites[i].getCurrentAnimation()->draw();
		}
	}
}
void RenderSystem::internalRemove(int index){
	_currentSprites[index].active = false;	
}
void RenderSystem::internalClear(){
	_currentSprites.clear();
}


