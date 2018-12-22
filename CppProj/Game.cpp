#include <iostream>
#include <ctime>

#include "Flappy/GameManager.h"

using namespace std;

int main()
{
	//cout << "Hello, Twitch" << endl;
	srand(time(NULL));

	GameManager gameManager;
	
	gameManager.Start();


	return 0;
}