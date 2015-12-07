#ifndef SCENE_H
#define SCENE_H
struct ScenePrefab{
	ScenePrefab(std::string name,std::vector<std::string> prefabs): name(name),prefabs(prefabs){}
	std::string name;
	std::vector<std::string> prefabs;
};
#endif
