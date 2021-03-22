#pragma once

#include "Scene.h"

class SceneGame : public Scene {
	public:
		SceneGame();
		~SceneGame();

		virtual void preLoad();

	protected:
		virtual void init();

		virtual void updateBegin();
		virtual void update();
		virtual void updateEnd();

		virtual void renderBegin();
		virtual void render();
		virtual void renderEnd();

		virtual void renderGUI();

	private: 
		C_Rectangle rect1;
		C_Rectangle rect2;
		int			sprite_id;
		C_Rectangle sprite_rect;
		int			sprite_frame;
		int			sprite_frame_time;

};
