// EmbedLua.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <lua.hpp>

using namespace std;

int main()
{
	int i;

	lua_State * L = luaL_newstate();

	if (L == NULL) {
		cout << "Error Initializing lua" << endl;;
		return -1;
	}

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

	cout << "closing lua state\n\n";
	lua_close(L);

	cout << "Press enter to exit\n";
	getchar();

    return 0;
}

