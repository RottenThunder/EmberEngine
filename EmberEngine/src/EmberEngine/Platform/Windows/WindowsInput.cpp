#include "EmberEnginePCH.h"
#include "WindowsInput.h"
#include "EmberEngine/Core/Application.h"
#include <GLFW/glfw3.h>

namespace EmberEngine
{
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

	float WindowsInput::GetMouseXImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos;
		glfwGetCursorPos(window, &xPos, NULL);
		return (float)xPos;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double yPos;
		glfwGetCursorPos(window, NULL, &yPos);
		return (float)yPos;
	}
}