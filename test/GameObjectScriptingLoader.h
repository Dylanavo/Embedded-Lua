#pragma once

#include <vector>
#include "GameObject.h"
#include "ScriptingLua.h"

//this is just to demo a simple (but useful) use-case we might encounter
//game object positions can be defined in simple scripts which are
//read in by the scripting engine then assigned to game objects
//
//no hard-coded values required, simple edit the ini.lua to tell the
//scripting engine how many objects there are to load in, then it will
//iterate through obj1.lua obj2.lua and so on scanning in all the values
//
//keep in mind this isn't necessarily the right way (or even a good way) 
//to do it, but it will hopefully help get us thinking about how we are 
//going to let various modules hook in to the scripting engine

class GameObjectScriptingLoader
{
public:
	GameObjectScriptingLoader();
	~GameObjectScriptingLoader();
	void loadObjects();
	void printObjects();

	//just for demonstration purposes, you'd never expose a member variable like this
	std::vector<GameObject> m_objs;
};

