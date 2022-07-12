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