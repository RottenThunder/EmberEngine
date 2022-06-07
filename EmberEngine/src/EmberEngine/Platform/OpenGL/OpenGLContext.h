#pragma once
#include "EmberEngine/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace EmberEngine
{
	class OpenGLContext : public GraphicsContext
	{
	private:
		GLFWwindow* WindowHandle;
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	};
}