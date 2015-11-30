#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H
#include "Sprite.h"
#include "Tools.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include <stdlib.h>
enum  AssetTypes{	
	AssetType_SPRITE_SHEET,
	AssetType_SETTINGS,
	AssetType_SPRITE_LIST,
	AssetType_TOP
};
struct Asset{
	char* path;
};
class AssetManager{ 
	public:	
		AssetManager();
		std::unordered_map<std::string, Sprite> loadSprites(std::unordered_map<std::string, Animation> animations);
		std::unordered_map<std::string, Animation> loadSpriteSheets();
	private:
		void init();
		void loadAssetsDirectory();
		std::vector<char*> _assets[AssetType_TOP];
		
};
#endif
