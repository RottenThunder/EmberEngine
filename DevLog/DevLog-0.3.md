# DevLog - 0.3

## Version 0.3.0 (22/07/2022)
- Textures and bug fixes
    - The engine can now load textures and render them
        - RGB and RGBA is supported
        - The engine will look for textures in the "Assets/Textures/" directory
        - stb_image is being used for now but i hope that i can remove it at some point
    - Other minor bug fixes have been implemented

## Version 0.3.1 (23/07/2022)
- Shader Files
    - The engine can now read from files to compile shaders
    - The files have the file extension of ".eesl" which stands for "Ember Engine Shading Language"

## Version 0.3.2 (24/07/2022)
- Renderer API
    - The renderer API has been changed to be "DrawQuad()"
        - you can specify the position, size, colour and texture as arguements
        - This is a lot easier since you do not need to manage all the different graphics classes by your self