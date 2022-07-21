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
		static Application* Instance;

		bool Running = true;
		bool Minimised = false;
		Scope<Window> MainWindow;
		LayerStack layerStack;

		bool OnWindowResize(WindowResizeEvent& e);
		bool OnWindowClose(WindowCloseEvent& e);
	public:
		Application();
		virtual ~Application();

		inline static Application& Get() { return *Instance; }

		void Run();
		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void OnEvent(Event& e);

		inline Window& GetWindow() { return *MainWindow; }
		int32_t GetWindowPosX();
		int32_t GetWindowPosY();
		Vector2i GetWindowPos();
		int32_t GetWindowWidth();
		int32_t GetWindowHeight();
	};

	//Will be defined in client-side code
	//e.g The Sandbox project
	Application* CreateApplication();
}