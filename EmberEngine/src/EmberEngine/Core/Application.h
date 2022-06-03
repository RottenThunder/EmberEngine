#pragma once
#include "Base.h"
#include "Window.h"
#include "EmberEngine/Events/ApplicationEvent.h"

namespace EmberEngine
{
	class Application
	{
	private:
		bool Running = true;
		std::unique_ptr<Window> MainWindow;
		bool OnWindowClose(WindowCloseEvent& e);
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	};

	//Will be defined in client-side code
	//e.g The Sandbox project
	Application* CreateApplication();
}