#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include "Manager.h"
#include "Object.h"
struct Scene{
	Scene();
	Scene(std::vector<Object> objects):objects(objects){}
	std::vector<Object> objects;		
};
class SceneManager: public Manager{
	public:
		SceneManager(AssetManager* assetManagerPtr,RenderSystem* renderSystemPtr,std::vector<ScenePrefab> scenePrefabs):Manager(assetManagerPtr,renderSystemPtr),_scenePrefabs(scenePrefabs){}
		void nextScene();
		void setScene(int index);
		void setScene(std::string identifer);
	private:

		std::vector<ScenePrefab> _scenePrefabs;
		Scene _currentScene;


};
#endif
