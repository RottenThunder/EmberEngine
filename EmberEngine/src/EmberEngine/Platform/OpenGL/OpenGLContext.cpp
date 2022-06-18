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
		EMBER_ASSERT(WindowHandle, "WindowHandle == NULL!!!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(WindowHandle);
		int32_t gladInitStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EMBER_ASSERT(gladInitStatus, "Failed to initialise Glad!!!");

		GPU = (const char*)glGetString(GL_RENDERER);
		Version = (const char*)glGetString(GL_VERSION);
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(WindowHandle);
	}

	std::string OpenGLContext::GetGPU()
	{
		return GPU;
	}
}