#include "SceneMenu.h"
#include "Singletons.h"


SceneMenu::SceneMenu() : Scene()
{
}

SceneMenu::~SceneMenu()
{
}

void SceneMenu::preLoad()
{

}

void SceneMenu::unload()
{
}

void SceneMenu::init()
{
	//menu_img_rect = C_Rectangle{ 0, 0,
		//sResManager->getSpriteWidth(menu_img_id),
		//sResManager->getSpriteHeight(menu_img_id) };
		n_menu_option = CONTINUE;
		optionSelector = C_Rectangle{ 700, 250, 190, 30 };
}

void SceneMenu::enterScene()
{
}

void SceneMenu::updateBegin()
{
}

void SceneMenu::update()
{
	int prevOption = n_menu_option;

	if (sInput->isKeyPressed(Input::KeyboardKeys::ARROW_DOWN)) {
		n_menu_option++;
		if (n_menu_option > EXIT) {
			n_menu_option = EXIT;
		}
	}

	if (sInput->isKeyPressed(Input::KeyboardKeys::ARROW_UP)){
		n_menu_option--;
		if (n_menu_option < CONTINUE) {
			n_menu_option = CONTINUE;
		}
	}

	if (prevOption != n_menu_option) {
		optionSelector.y = 250 + n_menu_option * 50;
	}

	if(sInput->isKeyPressed(Input::KeyboardKeys::ENTER)) 
	{
		sSndManager->playSound("assets/coin.wav", true);
		switch (n_menu_option) {
		default:break;
		case NEW_GAME:
			sDirector->changeScene(SceneDirector::GAME, false);
			break;
		case EXIT:
			//sInput->closeWindow();
			break;
		}
		sDirector->changeScene(SceneDirector::GAME);
	}
	
}

void SceneMenu::updateEnd()
{
}

void SceneMenu::renderBegin()
{
}

void SceneMenu::render()
{
	sRenderer->drawRectangle(optionSelector, Color{255,255,255}, true);
	//sRenderer->drawSprite(menu_img_id, 0, 0, menu_img_rect);
}

void SceneMenu::renderEnd()
{
}

void SceneMenu::renderGUI()
{
}
