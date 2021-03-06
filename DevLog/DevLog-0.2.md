# DevLog - 0.2

## Version 0.2.0 (11/07/2022)
- Analysis, Research and Basic Shaders
    - There is a new doc named "Analysis"
        - So far, this contains the research section of the a-level documentation
        - Some parts are not yet completed, but the majority is
    - Shaders can be used now
        - This is only a test and definitely will not be the final code
    - The Input class has been changed
        - So instead of just having the functions that return a given position of the mouse as a float, there are now functions that return it as a double
        - Also you can retrieve the mouse position as a Vector2

## Version 0.2.1 (12/07/2022)
- Buffer Abstraction
    - Vertex and Index Buffers have been abstracted to write generic code that will work on all platforms
    - A base renderer class has been added
        - So far it contains the RendererAPI that is being used

## Version 0.2.2 (14/07/2022)
- Buffer Layout Abstraction and bug fixes
    - Buffer Layouts have been abstracted to contain Vertex attributes
    - The bug fixes were:
        - changed the events to hold there data as a 32-bit signed integer to avoid unneccassary casting
        - changed the key and mouse button codes to be 32-bit signed integers
        - changed the window class to hold it's position as a Vector2i

## Version 0.2.3 (15/07/2022)
- Vertex Array Abstraction
    - Vertex Arrays have been abstracted to contain multiple vertex buffers and an index buffer
    - A square is now being rendered with a triangle on top of it

## Version 0.2.4 (16/07/2022)
- Draw Call Abstraction
    - Draw calls have been abstracted, the renderer now calls the drawing functions
    - The renderer also clears the screen with a new class called "Colour"
        - The class contains 4 floats corresponding to the RGBA colour scheme

## Version 0.2.5 (17/07/2022)
- Transferring of code to Sandbox
    - The testing code for the renderer has been moved from the start of the application class into the sandbox project
    - Other bug fixes have been investigated and some were dealt with

## Version 0.2.6 (18/07/2022)
- Shader Abstraction
    - Shaders have been abstracted properly with the ability to upload uniforms
    - Other bug fixes have been implemented

## Version 0.2.7 (19/07/2022)
- Delta Time
    - Delta Time is the time taken to complete one frame
        - It is very useful for making things move in accordance to how long each frame takes
        - Delta Time is measured in seconds
    - The implementation will be platform based as not all graphics APIs have the ability to track time
        - There is only the windows implementation as of now

## Version 0.2.8 (20/07/2022)
- Orthographic Cameras
    - An orthographic camera class has been made
        - It contains the view and the projection matrix
        - It can also rotate itself and move position
    - The Vector classes have been changed so that upon construction it does not set all of it's components to 0
        - It only sets the unused components to 0

## Version 0.2.9 (21/07/2022)
- Window Resizing
    - The window can be resized and the viewport will automatically change according to how big the new window size is