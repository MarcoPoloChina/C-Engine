#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H
#include "../Components/Sprite.h"
#include "../Tools.h"
#include "../rapidxml-1.13/rapidxml.hpp"
#include <stdlib.h>
#include <string.h>
enum  AssetTypes{	
	AssetType_SPRITE_SHEET,
	AssetType_SETTINGS,
	AssetType_SPRITE_LIST,
	AssetType_TOP
};
struct TextureMap{
	std::unordered_map<std::string, int> indexes;
	std::vector<std::string> texturesSources;
};
struct AnimationMap{
	std::unordered_map<std::string, int> indexes;
	std::vector<Animation> animations;
};
struct SpriteMap{
	std::unordered_map<std::string, int> indexes;
	std::vector<Sprite> sprites;
};
struct Asset{
	char* path;
};
class AssetManager{ 
	public:	
		AssetManager();
		std::vector<Animation> loadSpriteSheets();
		std::vector<Sprite> loadSprites(std::vector<Animation> animations);
	private:
		void init();
		void loadAssetsDirectory();
		std::vector<char*> _assets[AssetType_TOP];
		TextureMap _textureMap;
		AnimationMap _animationMap;
		SpriteMap _spriteMap;
};
#endif
