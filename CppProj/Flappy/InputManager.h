#ifndef GAME_INPUTMANAGER
#define GAME_INPUTMANAGER

#include "../Engine/Engine.h"
#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"
#include "Flapper.h"
#include "Rock.h"

class InputManager {
public:
	InputManager();
	InputManager(Flapper* _flapper);
	//InputManager(Flapper* _flapper, Rock* _rock);  // testing purposes

	void Update();
private:
	Flapper* flapper;
	Rock * rock;

};

#endif // !GAME_INPUTMANAGER

