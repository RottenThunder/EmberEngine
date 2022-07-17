#include "EmberEnginePCH.h"
#include "Application.h"
#include "ProcessorAnalyser.h"
#include "EmberEngine/Renderer/Renderer.h"

namespace EmberEngine
{
	Application* Application::Instance = nullptr;

	Application::Application()
	{
		EMBER_REVERSE_ASSERT(Instance, "Application already exists");
		Instance = this;

		MainWindow = std::unique_ptr<Window>(Window::Create({ "Ember Engine", 1280, 720 }));
		MainWindow->SetEventCallback(EMBER_BIND_EVENT_FUNCTION(OnEvent));

		std::cout << "CPU: " << ProcessorAnalyser::Brand << std::endl;
		std::cout << "GPU: " << MainWindow->GetGraphicsContext()->GetGPU() << std::endl;
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
		eventDispatcher.Dispatch<WindowCloseEvent>(EMBER_BIND_EVENT_FUNCTION(OnWindowClose));

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

	int32_t Application::GetWindowPosX()
	{
		return Instance->GetWindow().GetPosX();
	}

	int32_t Application::GetWindowPosY()
	{
		return Instance->GetWindow().GetPosY();
	}

	Vector2i Application::GetWindowPos()
	{
		return Instance->GetWindow().GetPos();
	}

	int32_t Application::GetWindowWidth()
	{
		return Instance->GetWindow().GetWidth();
	}

	int32_t Application::GetWindowHeight()
	{
		return Instance->GetWindow().GetHeight();
	}
}