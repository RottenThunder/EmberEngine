# DevLog - 0.1

## Version 0.1.0 (10/06/2022)
- Beginning of the A-Level Documentation
    - So far there is a project brief describing what i'm going to do
        - This isn't neccassary by the A-level standard but i'm still going to do it because it is helpful when looking back and seeing what i said i would do
    - Fixed the Ember Asserts not showing up the "[EMBER]" text before the message

## Version 0.1.1 (11/06/2022)
- Ember and Mathematics
    - Ember now has Vector classes:
        - Vector2 (float, double & int)
        - Vector3 (float, double & int)
        - Vector4 (float, double & int)
    - The Overall class with all the maths functions have been called "MathF"
    - MathF can be configured to use different SIMD instructions or none at all (which is what it is initialised to)
        - So far there is only a ResetVector() function which sets all the vector's componenets to 0
        - There is only "NULL" and "SSE" instructions as of now
            - "NULL" means that the functions do not use SIMD instructions
            - "SSE" means that it will use the SSE instruction set, when it can