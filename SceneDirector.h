#pragma once

#include "includes.h"
#include "Scene.h"

class SceneDirector {
	public:
		enum SceneEnum {
			MAIN_MENU, GAME, /*GAME_OVER, WIN, ETC*/
			LAST_NO_USE
		};
		const SceneEnum FIRST_SCENE = SceneDirector::MAIN_MENU;

		SceneDirector();
		~SceneDirector();

		void changeScene(SceneEnum next_scene, bool load_on_return = true, bool history = true);
		void goBack(bool load_on_return = true);
		Scene* getCurrentScene() { return mCurrentScene; };

		static SceneDirector* getInstance();

	private:
		void initScenes();
		static SceneDirector* instance;

		Scene*				mCurrentScene; //Escena actual
		std::vector<Scene*> mScenes; //Todas las escenas del juego
		std::stack<Scene*>	mSceneHistory; //Historial para poder volver atr�s
};