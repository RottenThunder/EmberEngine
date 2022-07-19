#include "EmberEnginePCH.h"
#include "WindowsInput.h"
#include "EmberEngine/Core/Application.h"
#include <GLFW/glfw3.h>

namespace EmberEngine
{
#if defined EMBER_PLATFORM_WINDOWS
	Input* Input::Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(uint16_t keyCode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(uint8_t mouseButton)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, mouseButton);
		return state == GLFW_PRESS;
	}

	float WindowsInput::GetMouseX32Impl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos;
		glfwGetCursorPos(window, &xPos, NULL);
		return (float)xPos;
	}

	float WindowsInput::GetMouseY32Impl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double yPos;
		glfwGetCursorPos(window, NULL, &yPos);
		return (float)yPos;
	}

	double WindowsInput::GetMouseX64Impl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos;
		glfwGetCursorPos(window, &xPos, NULL);
		return xPos;
	}

	double WindowsInput::GetMouseY64Impl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double yPos;
		glfwGetCursorPos(window, NULL, &yPos);
		return yPos;
	}

	Vector2 WindowsInput::GetMousePos32Impl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		Vector2 input;
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		input.x = (float)xPos;
		input.y = (float)yPos;
		return input;
	}

	Vector2d WindowsInput::GetMousePos64Impl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		Vector2d input;
		glfwGetCursorPos(window, &input.x, &input.y);
		return input;
	}
#endif
}