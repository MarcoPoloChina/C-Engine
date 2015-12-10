#ifndef MANAGER_H
#define MANAGER_H
#include "AssetManager.h"
#include "RenderSystem.h"
#include "LogicSystem.h"
class Manager{
	public:
		Manager(AssetManager* assetManagerPtr,RenderSystem* renderSystemPtr):_assetManagerPtr(assetManagerPtr),_renderSystemPtr(renderSystemPtr){}
	protected:
		AssetManager* _assetManagerPtr;
		RenderSystem* _renderSystemPtr;
};
#endif

