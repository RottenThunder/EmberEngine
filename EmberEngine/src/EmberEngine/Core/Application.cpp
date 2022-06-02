#include "EmberEnginePCH.h"
#include "Application.h"
#include <GLFW/glfw3.h> //for the clear colour

namespace EmberEngine
{
	Application::Application()
	{
		MainWindow = std::unique_ptr<Window>(Window::Create({ "Ember Engine", 1280ui16, 720ui16 }));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (Running)
		{
			glClearColor(1.0f, 0.25f, 0.125f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			MainWindow->OnUpdate();
		}
	}
}