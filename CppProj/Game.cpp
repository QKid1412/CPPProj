#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <iostream>
#include <ctime>

#include "Flappy/GameManager.h"

using namespace std;

int main()
{
	//system("dir");

	srand(time(NULL));

	GameManager gameManager;	
	gameManager.Start();
	
	return 0;
}