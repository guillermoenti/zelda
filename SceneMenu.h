#ifndef SCENEMENU_H
#define SCENEMENU_H

#include "Scene.h"

class SceneMenu : public Scene {

public:
	SceneMenu();
	~SceneMenu();
	
	virtual void preLoad();
	void unload();
	enum Menu {CONTINUE, NEW_GAME, EXIT};

protected:
	virtual void init();
	virtual void enterScene();
	virtual void updateBegin();
	virtual void update();
	virtual void updateEnd();

	virtual void renderBegin();
	virtual void render();
	virtual void renderEnd();

	virtual void renderGUI();

private:
	int  menu_img_id;
	C_Rectangle menu_img_rect;

	int n_menu_option;
	C_Rectangle optionSelector;
};

#endif
