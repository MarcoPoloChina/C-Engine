#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include "Manager.h"
#include "Object.h"
#include "Scene.h"
struct Scene{
	Scene(){}
	Scene(std::vector<Object> objects):objects(objects){}
	std::vector<Object> objects;		
};
class SceneManager: public Manager{
	public:
		SceneManager(AssetManager* assetManagerPtr,RenderSystem* renderSystemPtr);
		void nextScene();
		void setScene(int index);
		void setScene(std::string identifer);
		Object genObject(Prefab prefab);
		ID genComponent(ComponentPrefab componentPrefab);
	private:
		std::vector<ScenePrefab> _scenePrefabs;
		int _indexOfCurrentScene;	
		Scene _currentScene;
};
#endif
