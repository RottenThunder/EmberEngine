#include "EmberEnginePCH.h"
#include "Application.h"

namespace EmberEngine
{
	Application* Application::Instance = nullptr;

	Application::Application()
	{
		EMBER_REVERSE_ASSERT(Instance, "Application already exists");
		Instance = this;

		MainWindow = Scope<Window>(Window::Create({ "Ember Engine", 1280, 720 }));
		MainWindow->SetEventCallback(EMBER_BIND_EVENT_FUNCTION(OnEvent));

		Init();

		std::cout << "CPU: " << ProcessorAnalyser::Brand << std::endl;
		std::cout << "GPU: " << MainWindow->GetGraphicsContext()->GetGPU() << std::endl;
	}

	Application::~Application()
	{
	}

	void Application::Init()
	{
		EmberEngine::ProcessorAnalyser::Analyse();
		EmberEngine::MathFInit();
		EmberEngine::Time::Init();
		EmberEngine::Renderer::Init();
	}

	void Application::Run()
	{
		while (Running)
		{
			Time::Measure();

			if (!Minimised)
			{
				for (Layer* layer : layerStack)
					layer->OnUpdate();
			}

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
		eventDispatcher.Dispatch<WindowResizeEvent>(EMBER_BIND_EVENT_FUNCTION(OnWindowResize));

		for (auto it = layerStack.end(); it != layerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.handled)
				break;
		}
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			Minimised = true;
			return false;
		}

		Minimised = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
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