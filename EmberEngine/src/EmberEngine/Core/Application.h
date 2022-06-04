#pragma once
#include "Base.h"
#include "Window.h"
#include "LayerStack.h"
#include "EmberEngine/Events/ApplicationEvent.h"

namespace EmberEngine
{
	class Application
	{
	private:
		bool Running = true;
		std::unique_ptr<Window> MainWindow;
		LayerStack layerStack;

		bool OnWindowClose(WindowCloseEvent& e);
	public:
		Application();
		virtual ~Application();

		void Run();
		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void OnEvent(Event& e);

		uint16_t GetWindowPosX();
		uint16_t GetWindowPosY();
		uint16_t GetWindowWidth();
		uint16_t GetWindowHeight();
	};

	//Will be defined in client-side code
	//e.g The Sandbox project
	Application* CreateApplication();
}