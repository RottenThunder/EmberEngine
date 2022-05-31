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