// EmbedLua.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
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
	if (luaL_dofile(L, "scripts/script1.lua")) {
		cout << "error opening file\n";
		getchar(); return 1;
	}

	cout << "Type anything and press enter to exit\n";
	cin >> i;

    return 0;
}

