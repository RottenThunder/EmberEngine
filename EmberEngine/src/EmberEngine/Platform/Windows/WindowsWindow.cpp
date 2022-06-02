#include "EmberEnginePCH.h"
#include "WindowsWindow.h"

namespace EmberEngine
{
	static bool glfwInitialised = false;

	WindowsWindow::WindowsWindow(const WindowProperties& props)
		: WindowObject(nullptr)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Terminate();
	}

	Window* Window::Create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}

	void WindowsWindow::Init(const WindowProperties& props)
	{
		windowData.Title = props.Title;
		windowData.Width = props.Width;
		windowData.Height = props.Height;

		if (!glfwInitialised)
		{
			int init = glfwInit();
			EMBER_ASSERT(init, "Could not initialise glfw!!!");

			glfwInitialised = true;
		}

		WindowObject = glfwCreateWindow(windowData.Width, windowData.Height, windowData.Title.c_str(), NULL, NULL);
		EMBER_ASSERT(WindowObject, "Window Object == NULL!!!");

		glfwMakeContextCurrent(WindowObject);
		glfwSetWindowUserPointer(WindowObject, &windowData);
		SetVSync(true);
	}

	void WindowsWindow::Terminate()
	{
		glfwDestroyWindow(WindowObject);
		glfwTerminate();
	}

	void WindowsWindow::SetVSync(bool vSync)
	{
		if (vSync)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		windowData.VSync = vSync;
	}

	bool WindowsWindow::IsVSync() const
	{
		return windowData.VSync;
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(WindowObject);
	}
}