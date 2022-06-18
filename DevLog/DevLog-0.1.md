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

## Version 0.1.2 (12/06/2022)
- Add, Subtract, Multiply and Divide Vectors
    - The MathF Instance has been changed to initialise to nullptr
        - This is to reduce unneccessary usage of memory
    - MathF now has the ability to add, subtract, multiply and divide vectors together
    - The vector classes has been given the functions to do these operations on itself
    - There are vector operators that can compute statements like this:
    ```
    Vector4f vec1;
    Vector4f vec2;
    Vector4f vec3;
    vec1 = vec2 + vec3;
    ```
    - There is now SSE2 instructions for all the MathF functions that have been added so far

## Version 0.1.3 (16/06/2022)
- Magnitudes of Vectors + bug fixes
    - There are now magnitude functions for the vector classes
        - These calculate the magnitude (length) of the vector
        - For the integer vectors, the magnitude can be obtained as a float or as a double
    - There are also square magnitude functions
        - These calculate the squared magnitude of the vector
        - These are much faster than the normal magnitude functions and are recommended to be used instead of them
    - For the vectors that do not perfectly fit into 128 or 256 bit registers have been changed
        - Private variables are used to fill up the space required for a SIMD register
        - All vectors now have a singular constructor which sets all the components to 0 (including the private ones which are not used)
    - There are now SSE3 instructions for all the MathF functions that have been added so far

## Version 0.1.4 (18/06/2022)
- Processor Analysing
    - The Engine now analyses the host's processor to see which level of SIMD, the processor can support
    - It can also extract the the name of the processor
    - Other miscellaneous bug fixes were added