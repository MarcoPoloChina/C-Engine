#include "Sprite.h"
void Sprite::setCurrentAnimation(unsigned int animation){
	if(animation > _animations.size()){
		std::cout << "Error animation:"	<< animation << " not found" << std::endl;
	}else{
		_currentAnimation = animation;
	}
}
