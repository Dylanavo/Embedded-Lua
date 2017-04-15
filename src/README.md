# Implementation source files
This directory contains the source files for the C++ classes that implement the scripting engine

# ScriptingInterface
This defines the interface that unrelated modules in our engine will use to handle use of scripts (getting data from, sending data to, etc)

# ScriptingLua
This is the class that will implement the functions defined in the scripting interface (ScriptingInterface.h)

This class also serves as a C++ wrapper for the lower level C API that Lua uses to communicate with our application

Technically we should be able to replace this class with something like ScriptingPython, and as long as we implement all the functions defined in the interface, the engine shouldn't be affected by the change

Still need to implement calling functions between C++ and Lua, as well as classes. May use the Selene Lua wrapper to implement instead of trying to write my own wrappers for binding functions/classes
