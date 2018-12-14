#include <iostream>
#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"

using namespace std;

int main()
{
	//cout << "Hello, Twitch" << endl;
	
	Engine engine;
	engine.Initialize("GameWindow");

	Sprite testSprite = Sprite("Assets/Image/rocket.png", 20, 200);

	while (true) {
		engine.Update();
		testSprite.Update();

		engine.BeginRender();
		testSprite.Render();
		engine.EndRender();
	}


	return 0;
}