#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H
#include "Tools.h"
enum class ComponentType{
	Sprite,
	Logic,
	Physics,
	Input
};
struct Component {
	Component(int index,ComponentType type,std::string componentName=""): index(index), type(type),componentName(componentName){}
	int index;	
	ComponentType type;
	std::string componentName;
};
struct ComponentPrefab {
	ComponentPrefab(ComponentType type,std::string componentName=""):type(type),componentName(componentName){}
	ComponentType type;
	std::string componentName;
};
class Object {	
	public:
		Object(std::vector<Component> components,std::string prefabName):_components(components), _prefabName(prefabName){}
		std::string getName(){return _prefabName;}
		Component getComponent(int index){return _components[index];}
	private:
		std::vector<Component> _components;
		std::string _prefabName;	
};
class Prefab {
	public:
		Prefab(std::string name,std::vector<ComponentPrefab> componentPrefabs):_name(name),_componentPrefabs(componentPrefabs){}
		Object generateObject();
	private:
		std::string _name;
		std::vector<ComponentPrefab> _componentPrefabs;
};
class ObjectManager{
	public:
		ObjectManager();
		Object* getObject(int index){return &_objects[index];}
		int genObject(std::string name);
	private:
		void init();
		std::vector<Object> _objects;
		std::unordered_map<std::string,Prefab> _prefabs;
};
#endif
