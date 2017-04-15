# GameObject
Very simple dummy class to represent what a game object might look like in our engine, this is included for demonstration purposes

# GameObjectScriptingLoader
Another simple dummy class that acts as a go-between to avoid coupling GameObject and ScriptingInterface/Lua, also helps to demonstrate how the scripting engine might be used. Provides a simple example of how a level designer might define objects in lua without having to resort to C++ programming and hardcoded values

By modifying ini.lua and adding extra obj[num].lua files a level programmer can easily add in more objects, this is obviously a very simple example and would be extended to include physics bodies and behaviours in the 2nd assignment submission

It's important to note that GameObjetScriptingLoader is just a simple example and isn't necessarily the right way (or even a good way) to do it. We'll have to think further about how we want the different engine modules to talk to the scripts that hold their relevant data