#include "SceneManager.h"
SceneManager::SceneManager(AssetManager* assetManagerPtr,RenderSystem* renderSystemPtr):Manager(assetManagerPtr,renderSystemPtr),_indexOfCurrentScene(0){
	_scenePrefabs = assetManagerPtr->getScenePrefabs();
	setScene(_indexOfCurrentScene);
}
void SceneManager::setScene(int index){
	ScenePrefab* temp_scene_prefab = &_scenePrefabs[index];
	std::vector<Object> objects;
	for(int i=0;i<temp_scene_prefab->prefabs.size();i++){
		Prefab temp_prefab = _assetManagerPtr->getPrefab(_assetManagerPtr->lookUpPrefab(temp_scene_prefab->prefabs[i]));
		objects.push_back(genObject(temp_prefab));
	}
	_currentScene = Scene(objects);
}
Object SceneManager::genObject(Prefab prefab){
	std::vector<ID> temp_ids;
	for(int i=0;i<prefab.componentPrefabs.size();i++){
		temp_ids.push_back(genComponent(prefab.componentPrefabs[i]));
	}
	return Object(temp_ids,prefab.name);
}
ID SceneManager::genComponent(ComponentPrefab componentPrefab){
	ComponentType type = componentPrefab.type;
	switch(type){
		case ComponentType::Input:{
			return ID();
		}
		case ComponentType::Sprite:{
			return _renderSystemPtr->add(componentPrefab.componentName);
		}
		case ComponentType::Logic:{
			return ID();
		}
		case ComponentType::Physics:{
			return ID();		
		}
	}

}


