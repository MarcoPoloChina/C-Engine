#ifndef ENGINE_H
#define ENGINE_H
#include "AssetManager/AssetManager.h"
#include "Systems/RenderSystem.h"
#include "SDLManager/SDLManager.h"
#include "Status.h"
class Engine{
	public:
		Engine();
		void init();
		void gameLoop();
	private:
		AssetManager _assetManager;
		RenderSystem _renderSystem;
		SDLManager _SDLManager;
};
#endif
