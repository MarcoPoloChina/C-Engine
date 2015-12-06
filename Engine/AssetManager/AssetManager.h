#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H
#include "../Components/Sprite.h"
#include "../Tools.h"
#include "../Map.h"
#include "../rapidxml-1.13/rapidxml.hpp"
#include "../Managers/ObjectManager.h"
#include <stdlib.h>
#include <string.h>
enum  AssetTypes{	
	AssetType_SPRITE_SHEET,
	AssetType_SETTINGS,
	AssetType_SPRITE_LIST,
	AssetType_PREFAB_LIST,
	AssetType_TOP
};
struct Asset{
	char* path;
};
class AssetManager{ 
	public:	
		AssetManager();
		void loadSpriteSheets();
		void loadSprites();
		void addLogic();
		void loadPrefabs();
		std::vector<Sprite> getSprites(){return _spriteMap.getObjectVector();}
		int lookUpSprite(std::string identifier){return _spriteMap.checkObject(identifier);}
	private:
		void init();
		void loadAssetsDirectory();
		std::vector<char*> _assets[AssetType_TOP];
		Map<std::string> _textureMap;
		Map<Animation> _animationMap;
		Map<Sprite> _spriteMap;
		Map<Prefab> _prefabMap;
};
#endif
