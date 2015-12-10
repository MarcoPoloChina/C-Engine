#ifndef LOGIC_SYSTEM_H
#define LOGIC_SYSTEM_H
#include "System.h"
#include "Logic.h"
class LogicSystem : public System{
	public:
		LogicSystem(AssetManager* assetManagerPtr):System(assetManagerPtr){}
		void init(){_logicPointers = _assetManagerPtr->getLogicPointers();}
		virtual void internalAdd(int indexOfRefrence, int index);
		virtual void internalAdd(std::string identifier, int index);
		virtual void internalUpdate(double dt);
		virtual void internalRemove(int index);
		virtual void internalClear();
	private:
		std::vector<Logic*> _logicPointers;
		std::vector<Logic*> _currentLogicPointers;
};
#endif
