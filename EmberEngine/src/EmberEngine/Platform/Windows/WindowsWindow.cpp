#include "EmberEnginePCH.h"
#include "WindowsWindow.h"
#include "EmberEngine/Events/ApplicationEvent.h"
#include "EmberEngine/Events/KeyEvent.h"
#include "EmberEngine/Events/MouseEvent.h"
#include "EmberEngine/Platform/OpenGL/OpenGLContext.h"

namespace EmberEngine
{
	static bool glfwInitialised = false;

	static void GLFWerrorCallback(int32_t error, const char* description)
	{
		std::cout << "[EMBER] [GLFW_ERROR(" << error << ")] " << description << std::endl;
	}

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
			int32_t glfwInitStatus = glfwInit();
			EMBER_ASSERT(glfwInitStatus, "Failed to initialise glfw!!!");

			glfwSetErrorCallback(GLFWerrorCallback);
			glfwInitialised = true;
		}

		WindowObject = glfwCreateWindow(windowData.Width, windowData.Height, windowData.Title.c_str(), NULL, NULL);
		EMBER_ASSERT(WindowObject, "Window Object == NULL!!!");

		Context = new OpenGLContext(WindowObject);
		Context->Init();

		glfwSetWindowUserPointer(WindowObject, &windowData);
		SetVSync(true);
		int xPos, yPos;
		glfwGetWindowPos(WindowObject, &xPos, &yPos);
		windowData.XPosition = static_cast<uint16_t>(xPos);
		windowData.YPosition = static_cast<uint16_t>(yPos);

		//Setting GLFW Event Callbacks
		glfwSetWindowPosCallback(WindowObject, [](GLFWwindow* window, int32_t xPosition, int32_t yPosition)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.XPosition = static_cast<uint16_t>(xPosition);
				data.YPosition = static_cast<uint16_t>(yPosition);
				WindowMovedEvent e(data.XPosition, data.YPosition);
				data.EventCallback(e);
			});

		glfwSetWindowSizeCallback(WindowObject, [](GLFWwindow* window, int32_t width, int32_t height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = static_cast<uint16_t>(width);
				data.Height = static_cast<uint16_t>(height);
				WindowResizeEvent e(data.Width, data.Height);
				data.EventCallback(e);
			});

		glfwSetWindowCloseCallback(WindowObject, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent e;
				data.EventCallback(e);
			});

		glfwSetKeyCallback(WindowObject, [](GLFWwindow* window, int32_t key, int32_t scanCode, int32_t action, int32_t mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent e(static_cast<uint16_t>(key), 0);
					data.EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent e(static_cast<uint16_t>(key));
					data.EventCallback(e);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent e(static_cast<uint16_t>(key), 1); //GLFW does not keep track of the repeat count
					data.EventCallback(e);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(WindowObject, [](GLFWwindow* window, int32_t button, int32_t action, int32_t mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent e(static_cast<uint8_t>(button));
					data.EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent e(static_cast<uint8_t>(button));
					data.EventCallback(e);
					break;
				}
				}
			});

		glfwSetScrollCallback(WindowObject, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent e(static_cast<float>(xOffset), static_cast<float>(yOffset));
				data.EventCallback(e);
			});

		glfwSetCursorPosCallback(WindowObject, [](GLFWwindow* window, double xPosition, double yPosition)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent e(static_cast<float>(xPosition), static_cast<float>(yPosition));
				data.EventCallback(e);
			});
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
		Context->SwapBuffers();
	}
}