#include <iostream>
#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

using namespace std;

int main()
{
	//cout << "Hello, Twitch" << endl;
	
	Engine engine;
	engine.Initialize("GameWindow");

	Sprite testSprite = Sprite("Assets/Image/rocket.png", 20, 200);
	testSprite.SetScale(1.25f);
	testSprite.SpeedBy(10);

	while (true) {
		engine.Update();
		testSprite.Update();

		//testSprite.MoveTo((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());

		if (Mouse::Button(GLFW_MOUSE_BUTTON_LEFT)) {
			testSprite.RotateBy(100);
		}
		if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT)) {
			testSprite.RotateBy(-100);
		}

		if (Keyboard::Key(GLFW_KEY_W)) {
			testSprite.MoveUp();
		}
		if (Keyboard::Key(GLFW_KEY_S)) {
			testSprite.MoveDown();
		}
		if (Keyboard::Key(GLFW_KEY_A)) {
			testSprite.MoveLeft();
		}
		if (Keyboard::Key(GLFW_KEY_D)) {
			testSprite.MoveRight();
		}
		if (Keyboard::Key(GLFW_KEY_SPACE)) {
			testSprite.RotateBy(0.5);
		}

		engine.BeginRender();
		testSprite.Render();
		engine.EndRender();
	}


	return 0;
}