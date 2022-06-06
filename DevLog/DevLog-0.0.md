# DevLog - 0.0

## Version 0.0.0 (29/05/2022)
- Ember's beginning as a standalone engine!!!
    - This project came from [Project-Ember](https://github.com/RottenThunder/Project-Ember) where the aim of that project was to make a 2D game with a handbuilt 2D engine
    - Ember has been set to be a static library for many reasons
        - The main reason is that static libraries are generally faster than dynamic libraries
        - Another reason is that you don't have to make a module definition file, since all definitions are stored regardless of whether it is used or not
    - A sandbox project was also created, the main purpose of the sandbox project is to test random code to make sure the engine does its job

## Version 0.0.1 (31/05/2022)
- Ember's precompiled header
    - Ember has been set up with a precompiled header
    - This is for decreasing compile time when the project becomes large enough to include an STL file more than once in one file

## Version 0.0.2 (01/06/2022)
- Ember's event system
    - Ember now has it's own event system, where it can create events for when any sort of input happens
    - The events were split up into 3 categories (each with their own header file):
        - Application
        - Key
        - Mouse
    - Application events are dedicated to just window events but it can be expanded in the future

## Version 0.0.3 (02/06/2022)
- Ember now uses GLFW to create a window
    - Ember now has it's own Window class which contains basic information about the window
        - It is also responsible for the creation of the window
    - The window has not been hooked up to the Ember Event System, so it can not close (this will be the next step in development)
    - The engine uses the glfw3_mt.lib file to statically link to the engine
    - The glfw binaries can be found [here](https://www.glfw.org/download.html)

## Version 0.0.4 (03/06/2022)
- The Window now uses the Ember Event System
    - All GLFW Callbacks have now been set to create an Ember Event
    - The Window also closes now because a WindowCloseEvent terminates the "Running" loop and procedes to destroy the window

## Version 0.0.5 (04/06/2022)
- Ember Engine has a Layer System!
    - Layers are "Rendering Surfaces" more or less
    - Every Layer can render something different but you can only see 1 Layer at a time
        - This can be good for Loading screens for example
    - Some changes were done to the Window class
        - The WindowMoved Events were not being created because the callback was not set up - this has been fixed
        - There's a way of accessing the window's initial position and size through a EmberEngine::Application

## Version 0.0.6 (05/06/2022)
- Ember now has an Input System
    - The user can now query the engine to see the state of any key
    - This also can happen to mouse buttons
    - Ember also has it's own key codes and mouse button codes
        - They are currently the same as the GLFW ones, with some minor differences with naming

## Version 0.0.7 (06/06/2022)
- Ember now uses Glad for OpenGL Initialisation
    - Glad is used for managing function pointers for OpenGL
    - It is useful because OpenGL is only really a standard/specification, it is up to the driver manufacturer to implement the specification to a driver that the specific graphics card supports
        - It can optimise OpenGL for different OpenGL Versions etc.
    - Glad can be configured [here](https://glad.dav1d.de/)
    - A few changes had to be made for intergration with the engine:
        - The previously named "glad.c" file had to changed to "glad.cpp"
        - Inside the "glad.c" file, Ember's precompiled header had to included in the file