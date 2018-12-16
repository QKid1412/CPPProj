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

	while (true) {
		engine.Update();
		testSprite.Update();

		testSprite.SetPos((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());

		if (Mouse::Button(GLFW_MOUSE_BUTTON_LEFT)) {
			testSprite.SetRotBy(10);
		}
		if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT)) {
			testSprite.SetRotBy(-10);
		}

		if (Keyboard::)

		engine.BeginRender();
		testSprite.Render();
		engine.EndRender();
	}


	return 0;
}