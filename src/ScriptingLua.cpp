#include "stdafx.h"
#include "ScriptingLua.h"

bool ScriptingLua::runScript(std::string p_scriptName)
{
	if (luaL_dofile(m_state, p_scriptName.c_str()))
	{
		return false;
	}
	return true;
}

bool ScriptingLua::callScriptFunction(int p_numArgs, int p_numResults)
{
	return false;
}

bool ScriptingLua::checkScriptFunction(std::string p_funcName)
{
	return false;
}

void ScriptingLua::registerFunction(std::string p_funcName, void(*p_func)(void))
{
}

void ScriptingLua::getGlobal(std::string p_name)
{
	lua_getglobal(m_state, p_name.c_str());
}

void ScriptingLua::setGlobal(std::string p_name)
{
	lua_setglobal(m_state, p_name.c_str());
}

void ScriptingLua::clearStack()
{
	lua_settop(m_state, 0);
}

void ScriptingLua::pushInt(int p_int)
{
	lua_pushinteger(m_state, p_int);
}

void ScriptingLua::pushFloat(float p_float)
{
	lua_pushnumber(m_state, p_float);
}

void ScriptingLua::pushString(std::string p_string)
{
	lua_pushstring(m_state, p_string.c_str());
}

void ScriptingLua::pushEmpty()
{
	lua_pushnil(m_state);
}

void ScriptingLua::pop()
{
	lua_pop(m_state, 1);
}

int ScriptingLua::popInt()
{
	int l_num = 0;

	if (!lua_isinteger(m_state, -1))
	{
		luaL_error(m_state, "Error: int was expected at top of stack");
	}
	else
	{
		l_num = lua_tointeger(m_state, -1);
		lua_pop(m_state, 1);
	}

	return l_num;
}

float ScriptingLua::popFloat()
{
	int l_num = 0.0f;

	if (!lua_isnumber(m_state, -1))
	{
		luaL_error(m_state, "Error: float was expected at top of stack");
	}
	else
	{
		l_num = lua_tonumber(m_state, -1);
		lua_pop(m_state, 1);
	}

	return l_num;
}

std::string ScriptingLua::popString()
{
	return std::string();
}

bool ScriptingLua::isEmpty(int p_ind)
{
	return false;
}

bool ScriptingLua::isInt(int p_ind)
{
	return false;
}

bool ScriptingLua::isFloat(int p_ind)
{
	return false;
}

bool ScriptingLua::isString(int p_ind)
{
	return false;
}

std::string ScriptingLua::dumpStack()
{
	return std::string();
}
