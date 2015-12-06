#ifndef MANAGER_H
#define MANAGER_H
#include "../AssetManager/AssetManager.h"
#include "../Systems/RenderSystem.h"
class Manager{
	public:
		Manager(AssetManager* assetManagerPtr,RenderSystem* renderSystemPtr):_assetManagerPtr(assetManagerPtr),_renderSystemPtr(renderSystemPtr){}
	protected:
		AssetManager* _assetManagerPtr;
		RenderSystem* _renderSystemPtr;
};
#endif

