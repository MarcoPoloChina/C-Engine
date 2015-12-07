#ifndef MAP_H
#define MAP_H
#include "Tools.h"
template<class t>
class Map{
	public:
		std::vector<t> getObjectVector(){
			return _objects;
		}
		t getObject(int index){
			if(index >= _objects.size()){
				std::cout << "Error out of range" << std::endl;
			}
			return _objects[index];
		}
		int addObject(std::string identifier,t object){
			std::unordered_map<std::string, int>::const_iterator index_itr = _indexes.find(identifier);
			if(index_itr == _indexes.end()){
				int index = _objects.size();	
				_indexes.insert({identifier,index});
				_objects.push_back(object);
				return index;
			}
			return index_itr->second;
		}
		int checkObject(std::string identifier){
			std::unordered_map<std::string, int>::const_iterator index_itr = _indexes.find(identifier);
			if(index_itr == _indexes.end()){
				return -1;		
			}
			return index_itr->second;
		}
	private:
		std::unordered_map<std::string,int> _indexes;
		std::vector<t> _objects;
};
#endif
