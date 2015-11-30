#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H
#include "../Tools.h"
#include "../Components/Sprite.h"
#include "../AssetManager/AssetManager.h"
class RenderSystem{
	public:
		RenderSystem(AssetManager* assetManager);
		void update();
		void init();
		int addSprite(std::string name);
	private:
		AssetManager* assetManagerPtr;
		std::unordered_map<std::string,Sprite> _sprites;
		std::vector<Sprite> _currentSprites;
		std::vector<Animation> _animations;
};
#endif
