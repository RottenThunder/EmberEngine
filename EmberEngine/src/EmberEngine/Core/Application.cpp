#include "EmberEnginePCH.h"
#include "Application.h"

namespace EmberEngine
{
	Application* Application::Instance = nullptr;

	Application::Application()
		: MainWindow(std::unique_ptr<Window>(Window::Create({ "Ember Engine", 1280ui16, 720ui16 })))
	{
		EMBER_REVERSE_ASSERT(Instance, "Application already exists");
		Instance = this;

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
		return Instance->GetWindow().GetPosX();
	}

	uint16_t Application::GetWindowPosY()
	{
		return Instance->GetWindow().GetPosY();
	}

	uint16_t Application::GetWindowWidth()
	{
		return Instance->GetWindow().GetWidth();
	}

	uint16_t Application::GetWindowHeight()
	{
		return Instance->GetWindow().GetHeight();
	}
}