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
	float l_num = 0.0f;

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
	std::string l_string = "";

	if (!lua_isstring(m_state, -1))
	{
		luaL_error(m_state, "Error: string was expected at top of stack");
	}
	else
	{
		l_string += lua_tostring(m_state, -1);
		lua_pop(m_state, 1);
	}

	return l_string;
}

bool ScriptingLua::isEmpty(int p_ind)
{
	return lua_isnil(m_state, p_ind);
}

bool ScriptingLua::isInt(int p_ind)
{
	return lua_isinteger(m_state, p_ind);
}

bool ScriptingLua::isFloat(int p_ind)
{
	return lua_isnumber(m_state, p_ind);
}

bool ScriptingLua::isString(int p_ind)
{
	return lua_isstring(m_state, p_ind);
}

std::string ScriptingLua::dumpStack()
{
	int l_top = lua_gettop(m_state);
	std::string l_return = "Number of elements on stack: ";
	l_return += std::to_string(l_top);
	l_return += "\n";

	for (int i = 1; i <= l_top; i++)
	{
		l_return += "Element ";
		l_return += std::to_string(i);
		l_return += ": ";
		l_return += lua_tostring(m_state, -(i));
		l_return += "\n";
	}

	return l_return;
}
