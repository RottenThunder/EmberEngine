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