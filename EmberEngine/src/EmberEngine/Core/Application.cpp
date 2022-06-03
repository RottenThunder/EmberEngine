#include "EmberEnginePCH.h"
#include "Application.h"
#include <GLFW/glfw3.h> //for the clear colour

namespace EmberEngine
{
	Application::Application()
		: MainWindow(std::unique_ptr<Window>(Window::Create({ "Ember Engine", 1280ui16, 720ui16 })))
	{
		MainWindow->SetEventCallback(BIND_EVENT_FUNCTION(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (Running)
		{
			MainWindow->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher eventDispatcher(e);
		eventDispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(OnWindowClose));
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		Running = false;
		std::cout << e.GetName() << std::endl;
		return true;
	}
}