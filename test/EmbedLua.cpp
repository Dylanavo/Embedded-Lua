// EmbedLua.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <lua.hpp>

using namespace std;

int sum(int a, int b)
{
	return a + b;
}

int cpp_Sum(lua_State* luaVM)
{
	//determine number of parameters on the stack
	int numParams = lua_gettop(luaVM);
	if (numParams<2)
	{
		cout << "not enough params" << endl;
		return 0;
	}
	// check parameter types
	if (!lua_isnumber(luaVM, -1) || !lua_isnumber(luaVM, -2))
	{
		cout << "bad parameters" << endl;
		return 0;
	}
	//retrieve the parameters from the stack
	int num2 = (int)lua_tonumber(luaVM, -1);
	int num1 = (int)lua_tonumber(luaVM, -2);
	//call the real function
	int result = sum(num1, num2);
	//push the result onto the stack
	lua_pushnumber(luaVM, result);
	//return the number of values returned
	return 1;
}

int main()
{
	int i;

	lua_State * L = luaL_newstate();

	if (L == NULL) {
		cout << "Error Initializing lua" << endl;;
		return -1;
	}

	//register our wrapper
	lua_register(L, "cpp_Sum", cpp_Sum);

	// load standard lua library functions
	luaL_openlibs(L);

	// load and run Lua script
	cout << "Running script2.lua\n";
	if (luaL_dofile(L, "scripts/script2.lua")) {
		cout << "error opening file\n";
		getchar(); return 1;
	}
	cout << "script3.lua ran successfully, return to C++\n\n";

	cout << "Running script3.lua\n";
	if (luaL_dofile(L, "scripts/script3.lua")) {
		cout << "error opening file\n";
		getchar(); return 1;
	}
	cout << "script3.lua ran successfully, return to C++\n\n";

	cout << "clearing stack and pushing lua globals on to stack\n";
	lua_settop(L, 0);
	lua_getglobal(L, "levelName");
	lua_getglobal(L, "numSectors");
	lua_getglobal(L, "numRooms");

	cout << "reading variables from stack into C++ variables\n";
	string levelName = (string)lua_tostring(L, 1);
	int numSectors = (int)lua_tonumber(L, 2);
	int numRooms = (int)lua_tonumber(L, 3);

	cout << "Data read from stack, output below:\n"
		<< "Level Name: " << levelName << endl
		<< "Number of Sectors: " << numSectors << endl
		<< "Number of Rooms: " << numRooms << endl;

	//register c++ function and clear stack
	lua_settop(L, 0);
	cout << "\nRunning script4.lua\n";
	if (luaL_dofile(L, "scripts/script4.lua")) {
		cout << "error opening file\n";
		getchar(); return 1;
	}
	cout << "script4.lua ran successfully, return to C++\n\n";

	cout << "closing lua state\n\n";
	lua_close(L);

	cout << "Press enter to exit\n";
	getchar();

    return 0;
}
