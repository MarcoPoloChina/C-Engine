#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H
#include "Sprite.h"
#include "Object.h"
#include "Tools.h"
#include "Map.h"
#include "Scene.h"
#include "Logic.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include <stdlib.h>
#include <string.h>
enum  AssetTypes{	
	AssetType_SPRITE_SHEET,
	AssetType_SETTINGS,
	AssetType_SPRITE_LIST,
	AssetType_PREFAB_LIST,
	AssetType_SCENE_PREFAB_LIST,
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
		void addLogic(Logic* logicPointer);
		void loadPrefabs();
		void loadScenePrefabs();
		std::vector<Sprite> getSprites(){return _spriteMap.getObjectVector();}
		std::vector<Prefab> getPrefabs(){return _prefabs.getObjectVector();}
		std::vector<ScenePrefab> getScenePrefabs(){return _scenePrefabs.getObjectVector();}
		std::vector<Logic*> getLogicPointers(){return _logicPointers.getObjectVector();}
		int lookUpSprite(std::string identifier){return _spriteMap.checkObject(identifier);}
		int lookUpPrefab(std::string identifier){return _prefabs.checkObject(identifier);}
		int lookUpScenePrefab(std::string identifier){return _scenePrefabs.checkObject(identifier);}
		int lookUpLogicPointer(std::string identifier){return _scenePrefabs.checkObject(identifier);}
		Sprite getSprite(int index){return _spriteMap.getObject(index);}
		Prefab getPrefab(int index){return _prefabs.getObject(index);}
		ScenePrefab getScenePrefab(int index){return _scenePrefabs.getObject(index);}
		Logic* getLogicPointer(int index){return _logicPointers.getObject(index);}
	private:
		void init();
		void loadAssetsDirectory();
		std::vector<char*> _assets[AssetType_TOP];
		Map<std::string> _textureMap;
		Map<Animation> _animationMap;
		Map<Sprite> _spriteMap;
		Map<Prefab> _prefabs;
		Map<ScenePrefab> _scenePrefabs;
		Map<Logic*> _logicPointers;
};
#endif
