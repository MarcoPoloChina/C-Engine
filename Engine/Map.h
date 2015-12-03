#ifndef MAP_H
#define MAP_H
#include "Tools.h"
template<class t>
class Map{
	public:
		std::vector<t> getObjectVector();
		int addObject(std::string identifier,t object);
		int checkObject(std::string identifier);
		std::unordered_map<std::string,int> _indexes;
		std::vector<t> _objects;
};
#include "Map.cpp"
#endif
