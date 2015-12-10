#include "SceneManager.h"
SceneManager::SceneManager(AssetManager* assetManagerPtr,RenderSystem* renderSystemPtr):Manager(assetManagerPtr,renderSystemPtr),_indexOfCurrentScene(0){
	_scenePrefabs = assetManagerPtr->getScenePrefabs();
	setScene(_indexOfCurrentScene);
}
void SceneManager::setScene(int index){
	int scene_index = index;
	if(index >= _scenePrefabs.size()){
		scene_index = 0;	
	}
	_renderSystemPtr->clear();
	ScenePrefab* temp_scene_prefab = &_scenePrefabs[scene_index];
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
void SceneManager::setScene(std::string identifier){
	int test_index = _assetManagerPtr->lookUpScenePrefab(identifier);
	if(test_index == -1){
		std::cout << "Error scene not found" << std::endl;
		return;
	}
	setScene(test_index);
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
void SceneManager::nextScene(){
	setScene(_indexOfCurrentScene+1);
}

