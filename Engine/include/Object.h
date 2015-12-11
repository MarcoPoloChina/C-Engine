#ifndef OBJECT_H
#define OBJECT_H
#include "Messanger.h"
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
		std::vector<ID> getIDs(){return _ids;}
	private:
		int _objectId;
		static int _objectCounter;
		std::vector<ID> _ids;
		std::string _prefabName;	
};
struct Prefab {
	public:
		Prefab(std::string name,std::vector<ComponentPrefab> componentPrefabs):name(name),componentPrefabs(componentPrefabs){}
		std::string name;
		std::vector<ComponentPrefab> componentPrefabs;
};
#endif
