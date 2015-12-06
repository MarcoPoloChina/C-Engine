#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H
#include "../Tools.h"
#include "../Components/Sprite.h"
#include "../AssetManager/AssetManager.h"
#include "../Messanger.h"
#include "System.h"
class RenderSystem: public System {
	public:
		RenderSystem(AssetManager* assetManager):System(assetManager){init();}
		virtual void internalUpdate(double dt);
		void init();
		virtual void internalAdd(int indexOfRefrence,int index);
		virtual void internalAdd(std::string name,int index);
		virtual void internalRemove(int intdex);
	private:
		std::vector<Sprite> _sprites;
		std::vector<Sprite> _currentSprites;
};
#endif
