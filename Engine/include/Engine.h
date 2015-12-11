#ifndef ENGINE_H
#define ENGINE_H
#include "AssetManager.h"
#include "RenderSystem.h"
#include "InputSystem.h"
#include "SDLManager.h"
#include "Status.h"
#include "SceneManager.h"
class Engine{
	public:
		Engine();
		void init();
		void gameLoop();
		void addLogic(Logic* logicptr);
		void makeSystemMap();
	private:
		AssetManager _assetManager;
		RenderSystem _renderSystem;
		LogicSystem _logicSystem;
		SDLManager _SDLManager;
		SceneManager _sceneManager;
};
#endif
