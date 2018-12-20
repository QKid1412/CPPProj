#include "InputManager.h"

InputManager::InputManager() {

}

InputManager::InputManager(Flapper* _flapper) {
	flapper = _flapper;
}

/*InputManager::InputManager(Flapper* _flapper, Rock* _rock) {
	flapper = _flapper;
	rock = _rock;
}*/

void InputManager::Update() {

	if (Keyboard::Key(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
		flapper->Flap();
	}

}