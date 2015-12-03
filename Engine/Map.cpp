#include "Map.h"
template<class t>
std::vector<t> Map<t>::getObjectVector(){
	return _objects;
}
template<class t>
int Map<t>::addObject(std::string identifier,t object){
	std::unordered_map<std::string, int>::const_iterator index_itr = _indexes.find(identifier);
	if(index_itr == _indexes.end()){
		int index = _objects.size();	
		_indexes.insert({identifier,index});
		_objects.push_back(object);
		return index;
	}
	return index_itr->second;
}
template<class t>
int Map<t>::checkObject(std::string identifier){
	std::unordered_map<std::string, int>::const_iterator index_itr = _indexes.find(identifier);
	if(index_itr == _indexes.end()){
		return -1;		
	}
	return index_itr->second;
}
