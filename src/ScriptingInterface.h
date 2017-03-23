#pragma once
#include <string>

// This is just the interface for the scripting engine,
// functionality/usage should be relatively self-explanatory.
// A derived class will implement all the virtual functions
// listed here in order to seperate the implementation from
// the other parts of the engine that use it (hopefully allowing
// different scripting languages to be used without breaking other
// systems within the engine)
//
// Needs to be properly commented, not sure on what style we're going
// with so I've left it for now.
//
// Possibly needs to handle tables and a few other stack
// manipulation features

class ScriptingInterface
{
public:
	virtual ~ScriptingInterface() {}

	//script manipulation
	virtual bool runScript(std::string p_scriptName) = 0;
	virtual bool callScriptFunction(int p_numArgs, int p_numResults) = 0;
	virtual bool checkScriptFunction(std::string p_funcName) = 0;
	virtual void registerFunction(std::string p_funcName, void(*p_func)(void)) = 0;

	//stack manipulation
	virtual void getGlobal(std::string p_name) = 0;
	virtual void setGlobal(std::string p_name) = 0;
	virtual void clearStack() = 0;
	virtual void pushInt(int p_int) = 0;
	virtual void pushFloat(float p_float) = 0;
	virtual void pushString(std::string p_string) = 0;
	virtual void pushEmpty() = 0;
	virtual void pop() = 0;
	virtual int popInt() = 0;
	virtual float popFloat() = 0;
	virtual std::string popString() = 0;
	virtual bool isEmpty(int p_ind) = 0;
	virtual bool isInt(int p_ind) = 0;
	virtual bool isFloat(int p_ind) = 0;
	virtual bool isString(int p_ind) = 0;

	//helpful stuff
	virtual std::string dumpStack() = 0;
};
