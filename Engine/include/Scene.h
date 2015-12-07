#ifndef SCENE_H
#define SCENE_H
struct ScenePrefab{
	ScenePrefab(std::string name,std::vector<Prefab> objects): name(name),objects(objects){}
	std::string name;
	std::vector<Prefab> objects;
};
#endif
