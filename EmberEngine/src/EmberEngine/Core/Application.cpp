#include "EmberEnginePCH.h"
#include "Application.h"

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
			for (Layer* layer : layerStack)
				layer->OnUpdate();

			MainWindow->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		layerStack.PushLayer(layer);
	}

	void Application::PopLayer(Layer* layer)
	{
		layerStack.PopLayer(layer);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher eventDispatcher(e);
		eventDispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(OnWindowClose));

		for (auto it = layerStack.end(); it != layerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.handled)
				break;
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		Running = false;
		return true;
	}

	uint16_t Application::GetWindowPosX()
	{
		return MainWindow->GetPosX();
	}

	uint16_t Application::GetWindowPosY()
	{
		return MainWindow->GetPosY();
	}

	uint16_t Application::GetWindowWidth()
	{
		return MainWindow->GetWidth();
	}

	uint16_t Application::GetWindowHeight()
	{
		return MainWindow->GetHeight();
	}
}