# Implementation source files
This directory contains the source files for the C++ classes that implement the scripting engine

# ScriptingInterface
This defines the interface that unrelated modules in our engine will use to handle use of scripts (getting data from, sending data to, etc)

# ScriptingLua
This is the class that will implement the functions defined in the scripting interface (ScriptingInterface.h)

This class also serves as a C++ wrapper for the lower level C API that Lua uses to communicate with our application

Technically we should be able to replace this class with something like ScriptingPython, and as long as we implement all the functions defined in the interface, the engine shouldn't be affected by the change

# GameObject
Very simple dummy class to represent what a game object might look like in our engine, this is included for demonstration purposes

# GameObjectScriptingLoader
Another simple dummy class that acts as a go-between to avoid coupling GameObject and ScriptingInterface/Lua, also helps to demonstrate how the scripting engine might be used. Provides a simple example of how a level designer might define objects in lua without having to resort to C++ programming and hardcoded values

By modifying ini.lua and adding extra obj[num].lua files a level programmer can easily add in more objects, this is obviously a very simple example and would be extended to include physics bodies and behaviours in the 2nd assignment submission

It's important to note that GameObjetScriptingLoader is just a simple example and isn't necessarily the right way (or even a good way) to do it. We'll have to think further about how we want the different engine modules to talk to the scripts that hold their relevant data
