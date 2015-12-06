#include "System.h"
ID System::add(int indexOfRefrence){
	int index_of_added = determineNextIndex();
	internalAdd(indexOfRefrence,index_of_added);
	return genID(index_of_added);
}
ID System::add(std::string identifier){
	int index_of_added = determineNextIndex();
	internalAdd(identifier,index_of_added);
	return genID(index_of_added);
}
void System::update(double dt){
	internalUpdate(dt);
}
void System::remove(int index){
	if(index >= _top){
		std::cout << "error cant remove component because this index is out of range" << std::endl;
		return;
	}
	if(_deleted[index]){
		std::cout << "error cant remove component because this index has already been deleted" << std::endl;
		return;
	}
	_deleted[index] = true;
	_freeIndexes.push_back(index);
	internalRemove(index);
}
int System::determineNextIndex(){
	int next_index;
	if(_freeIndexes.empty()){
		next_index = _top++;
		_deleted.push_back(false);		
	}else{
		next_index = _freeIndexes.front();
		_freeIndexes.pop_front();
		_deleted[next_index] = false;
	}
	return next_index;
}
int System::_systemCount = 0;
