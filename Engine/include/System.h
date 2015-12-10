#ifndef SYSTEM_H
#define SYSTEM_H
#include "Messanger.h"
#include "AssetManager.h"
#include <list>
class System {
	public:
		System(AssetManager* assetManagerPtr):_assetManagerPtr(assetManagerPtr),_systemIndex(_systemCount++),_top(0){}
		ID add(int index);
		ID add(std::string identifier);
		ID genID(int index){return ID(_systemCount,index);}
		void update(double dt);
		void remove(int index);
		void clear();
		virtual void internalAdd(int indexOfRefrence, int index) =0;
		virtual void internalAdd(std::string identifier, int index) =0;
		virtual void internalUpdate(double dt) =0;
		virtual void internalRemove(int index) =0;
		virtual void internalClear() =0;
	private:
		int determineNextIndex();
		static int _systemCount;
		int _systemIndex;
		int _top;
		std::list<int> _freeIndexes;
		std::vector<bool> _deleted;
	protected:
		AssetManager* _assetManagerPtr;

};
#endif
