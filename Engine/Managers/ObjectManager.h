#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H
#include "../Tools.h"
#include "../Messanger.h"
#include "Manager.h"
enum class ComponentType{
	Sprite,
	Logic,
	Physics,
	Input
};
struct ComponentPrefab {
	ComponentPrefab(ComponentType type,std::string componentName=""):type(type),componentName(componentName){}
	ComponentType type;
	std::string componentName;
};
class Object {	
	public:
		Object(std::vector<ID> ids,std::string prefabName):_objectId(_objectCounter++),_ids(ids), _prefabName(prefabName){}
		std::string getName(){return _prefabName;}
		ID getComponent(int index){return _ids[index];}
	private:
		int _objectId;
		static int _objectCounter;
		std::vector<ID> _ids;
		std::string _prefabName;	
};
struct Prefab {
	public:
		Prefab(std::string name,std::vector<ComponentPrefab> componentPrefabs):_name(name),_componentPrefabs(componentPrefabs){}
		std::string _name;
		std::vector<ComponentPrefab> _componentPrefabs;
};
class ObjectManager: public Manager{
	public:
		ObjectManager(AssetManager* assetManagerPtr,RenderSystem* renderSystemPtr):Manager(assetManagerPtr,renderSystemPtr){}
		Prefab getPrefab(std::string name);
	private:
		void init();
		std::unordered_map<std::string,Prefab> _prefabs;
};
#endif
