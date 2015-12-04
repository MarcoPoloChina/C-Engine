#include "Sprite.h"
void Animation::draw(){
	std::cout << "Current Frame: frame number =" << currentFrame << " x=" << frames[currentFrame].x << " y=" << frames[currentFrame].y << " width=" << frames[currentFrame].width << " height=" << frames[currentFrame].height << std::endl;
	if(currentFrame < frames.size()){
		currentFrame++;	
	}else{
		currentFrame = 0;	
	}
}
void Sprite::setCurrentAnimation(unsigned int animation){
	if(animation > _animations.size()){
		std::cout << "Error animation:"	<< animation << " not found" << std::endl;
	}else{
		_currentAnimation = animation;
	}
}
