#pragma once

#include "ScriptingInterface.h"
#include <lua.hpp>

// implementing the interface defined in ScriptingInterface.h
// using embedded Lua. Ideally we could replace this entire
// class with ScriptingPython and as long as we implement all
// the functions defined in ScriptingInterface it shouldn't
// affect any other parts of the engine

class ScriptingLua : public ScriptingInterface
{
public:
	ScriptingLua() { m_state = luaL_newstate(); }
	~ScriptingLua() { lua_close(m_state); }

	//script manipulation
	bool runScript(std::string p_scriptName);
	bool callScriptFunction(int p_numArgs, int p_numResults);
	bool checkScriptFunction(std::string p_funcName);
	void registerFunction(std::string p_funcName, void(*p_func)(void));

	//stack manipulation
	void getGlobal(std::string p_name);
	void setGlobal(std::string p_name);
	void clearStack();
	void pushInt(int p_int);
	void pushFloat(float p_float);
	void pushString(std::string p_string);
	void pushEmpty();  //might be handy for seperating groups of elements on stack
	void pop();
	int popInt();
	float popFloat();
	std::string popString();
	bool isEmpty(int p_ind);
	bool isInt(int p_ind);
	bool isFloat(int p_ind);
	bool isString(int p_ind);

	//helpful stuff
	std::string dumpStack();

private:
	lua_State * m_state;
};
