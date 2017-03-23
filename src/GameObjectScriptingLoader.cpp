#include "stdafx.h"
#include "GameObjectScriptingLoader.h"
#include <iostream>
#include <string>

GameObjectScriptingLoader::GameObjectScriptingLoader()
{

}


GameObjectScriptingLoader::~GameObjectScriptingLoader()
{
}

void GameObjectScriptingLoader::loadObjects()
{
	ScriptingInterface * scrint = new ScriptingLua();
	int l_numObjs;
	std::string l_tmpS;
	GameObject l_tmpO;

	scrint->runScript("scripts/ini.lua");
	scrint->clearStack();
	scrint->getGlobal("numObjects");
	l_numObjs = scrint->popInt();

	std::cout << l_numObjs << " objects to scan\n\n";

	for (int i = 1; i <= l_numObjs; i++)
	{
		//build the file name and run the script
		l_tmpS = "scripts/obj";
		l_tmpS += std::to_string(i);
		l_tmpS += ".lua";
		scrint->runScript(l_tmpS);

		//clear the stack and push all lua global
		//variables to the stack
		scrint->clearStack();
		scrint->getGlobal("name");
		scrint->getGlobal("id");
		scrint->getGlobal("x");
		scrint->getGlobal("y");
		scrint->getGlobal("z");

		//pop the values off the stack in to C++
		//and assign them to temp game object
		l_tmpO.setZ(scrint->popFloat());
		l_tmpO.setY(scrint->popFloat());
		l_tmpO.setX(scrint->popFloat());
		l_tmpO.setID(scrint->popInt());
		l_tmpO.setName(scrint->popString());

		//push the object to the back of the vector
		m_objs.push_back(l_tmpO);
	}
}

void GameObjectScriptingLoader::printObjects()
{
	int l_count = 0;
	for(std::vector<GameObject>::iterator it = m_objs.begin(); it != m_objs.end(); ++it) 
	{
		l_count++;
		std::cout << "Object " << l_count << ":\nName: " << it->getName() << "\nID: " << it->getID() << "\nX: " << it->getX() << "\nY: " << it->getY() << "\nZ: " << it->getZ() << "\n\n";
	}
}
