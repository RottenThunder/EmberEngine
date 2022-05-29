#pragma once
#include "Base.h"

namespace EmberEngine
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//Will be defined in client-side code
	//e.g The Sandbox project
	Application* CreateApplication();
}