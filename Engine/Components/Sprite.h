#ifndef SPRITE__H
#define SPRITE__H
#include "Transform.h"
#include "../Tools.h"
struct Texture{
	Texture(int index,std::string path):index(index),path(path){}
	int index;
	std::string path;
};
struct Frame{
	Frame(int x=0, int y=0, int width=0, int height=0): x(x), y(x), width(width), height(height){}
	int x;
	int y;
	int width;
	int height;
};
struct Animation{
	Animation(std::vector<Frame> frames, int source=0,int speed=0, bool repeating=false, int index=0,std::string name=""): frames(frames), source(source),speed(speed), repeating(repeating), index(index),currentFrame(0),name(name) {}
	void draw();
	std::vector<Frame> frames;
	int source;
	int speed;
	bool repeating;
	int index;
	int currentFrame;
	std::string name;
};
class Sprite{ 
	public:
		Sprite(std::vector<Animation> animations,std::string name="",Transform transform=Transform(),int defaultAnimation=0,int layer=0):active(true),_animations(animations), _name(name), _transform(transform),_defaultAnimation(defaultAnimation),_layer(layer){setCurrentAnimation(defaultAnimation);}
		std::string getName() {return _name;}
		Animation* getCurrentAnimation() {return &_animations[_currentAnimation];}
		void setCurrentAnimation(unsigned int index);
		bool active;
	private:
		std::vector<Animation> _animations;
		std::string _name;
		Transform _transform;
		int _defaultAnimation;
		int _currentAnimation;
		int _layer;
};
#endif
