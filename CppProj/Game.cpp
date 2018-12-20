#include <iostream>
#include <ctime>
#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

#include "Flappy/Flapper.h"
#include "Flappy/InputManager.h"
#include "Flappy/Rock.h"

using namespace std;

int main()
{
	//cout << "Hello, Twitch" << endl;
	srand(time(NULL));

	Engine engine;
	engine.Initialize("GameWindow");

	Sprite testSprite = Sprite("Assets/Image/rocket.png", Vector3(Engine::SCREEN_WIDTH/2, Engine::SCREEN_HEIGHT/2, 0));
	testSprite.SetScale(0.8f);
	
	Flapper player(testSprite);

	Rock::Initialize();
	Rock rock(Vector3(0, 0, 0));

	InputManager im(&player, &rock);

	while (true) {
		engine.Update();
		player.Update();
		rock.Update();
		bool isColliding = Rigidbody::IsColliding(player.GetRB(), rock.GetTopRB()) || Rigidbody::IsColliding(player.GetRB(), rock.GetBotRB());
		cout << (isColliding ? "COLLIDING" : "....") << endl;
		im.Update();

		engine.BeginRender();
		player.Render();
		rock.Render();
		engine.EndRender();
	}


	return 0;
}