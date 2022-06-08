#include "EmberEnginePCH.h"
#include "OpenGLContext.h"
#include "EmberEngine/Core/Base.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace EmberEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: WindowHandle(windowHandle)
	{
		EMBER_ASSERT(WindowHandle, "[EMBER] WindowHandle == NULL!!!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(WindowHandle);
		int32_t gladInitStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EMBER_ASSERT(gladInitStatus, "[EMBER] Failed to initialise Glad!!!");

		std::cout << "GPU: " << glGetString(GL_RENDERER) << std::endl;
		std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(WindowHandle);
	}
}