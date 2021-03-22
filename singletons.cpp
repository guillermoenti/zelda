#include "singletons.h"

Renderer* sRenderer = NULL;
Input* sInput = NULL;
ResourceManager* sResManager;
SceneDirector* sDirector = NULL;
SoundManager* sSndManager;

void initSingletons() {
	sRenderer = Renderer::getInstance();
	sInput = Input::getInstance();
	sResManager = ResourceManager::getInstance();
	sDirector = SceneDirector::getInstance();

	sRenderer->setFramerate(30);
	sInput->setWindow(sRenderer->getWindow());
}