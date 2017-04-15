// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "GameObjectScriptingLoader.h"

int main()
{
	GameObjectScriptingLoader loader;
	loader.loadObjects();
	loader.printObjects();

	std::cout << "Press enter to exit\n";
	getchar();

    return 0;
}
