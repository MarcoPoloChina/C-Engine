#include "Sprite.h"
void Sprite::setCurrentAnimation(std::string animation){
	if(animation == ""){
		_currentAnimation = "";	
	}
	std::unordered_map<std::string,Animation>::const_iterator animation_itr = _animations.find(animation);
	if(animation_itr == _animations.end()){
		std::cout << "Error animation:"	<< animation << " not found" << std::endl;
	}else{
		_currentAnimation = animation;
	}
}
