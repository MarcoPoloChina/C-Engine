#include "LogicSystem.h"
void LogicSystem::internalAdd(int indexOfRefrence,int index){
	if(index >= _currentLogicPointers.size() || index < 0){
		_currentLogicPointers.push_back(_logicPointers[indexOfRefrence]->clone());
	}else{
		_currentLogicPointers[index] = _logicPointers[indexOfRefrence]->clone();
	}
}
void  LogicSystem::internalAdd(std::string identifier,int index){
	internalAdd(_assetManagerPtr->lookUpLogicPointer(identifier),index);
}
void LogicSystem::internalUpdate(double dt){
	std::cout << "updating logicSystem" << std::endl;
	for(unsigned int i=0;i<_currentLogicPointers.size();i++){
		if(_currentLogicPointers[i]){
			_currentLogicPointers[i]->update(dt);
		}
	}
}
void LogicSystem::internalRemove(int index){
	delete(_currentLogicPointers[index]);
	_currentLogicPointers[index]->destroy();
	_currentLogicPointers[index] = NULL;
}
void LogicSystem::internalClear(){
	_currentLogicPointers.clear();
}


