#ifndef SPRITE__H
#define SPRITE__H
#include "Transform.h"
#include "Tools.h"
struct Frame{
	Frame(int x=0, int y=0, int width=0, int height=0): x(x), y(x), width(width), height(height){}
	int x;
	int y;
	int width;
	int height;
};
struct Animation{
	Animation(std::vector<Frame> frames, int speed=0, bool repeating=false, std::string name=""): frames(frames), speed(speed), repeating(repeating), name(name),currentFrame(0) {}
	std::vector<Frame> frames;
	int speed;
	bool repeating;
	std::string name;
	int currentFrame;
};
class Sprite{ 
	public:
		Sprite(std::unordered_map<std::string,Animation> animations,std::string name="",Transform transform=Transform(),std::string defaultAnimation=""): _animations(animations), _name(name), _transform(transform),_defaultAnimation(defaultAnimation){setCurrentAnimation(defaultAnimation);}
		std::string getName() {return _name;}
		std::string getCurrentAnimation() {return _currentAnimation;}
		void setCurrentAnimation(std::string);
	private:
		std::unordered_map<std::string,Animation> _animations;
		std::string _name;
		Transform _transform;
		std::string _defaultAnimation;
		std::string _currentAnimation;
};
#endif
