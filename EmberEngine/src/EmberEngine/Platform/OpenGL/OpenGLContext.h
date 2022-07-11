#pragma once
#include "EmberEngine/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace EmberEngine
{
	class OpenGLContext : public GraphicsContext
	{
	private:
		GLFWwindow* WindowHandle;
		std::string Version;
		std::string GPU;
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
		virtual std::string GetVersion() override;
		virtual std::string GetGPU() override;
	};
}