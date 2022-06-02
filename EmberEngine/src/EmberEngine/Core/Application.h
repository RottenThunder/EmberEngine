#pragma once
#include "Base.h"
#include "Window.h"

namespace EmberEngine
{
	class Application
	{
	private:
		bool Running = true;
		std::unique_ptr<Window> MainWindow;
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//Will be defined in client-side code
	//e.g The Sandbox project
	Application* CreateApplication();
}