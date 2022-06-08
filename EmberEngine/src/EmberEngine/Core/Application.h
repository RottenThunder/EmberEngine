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
		std::unique_ptr<Window> MainWindow;
		LayerStack layerStack;

		uint32_t VertexArray, VertexBuffer, IndexBuffer;

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
		uint16_t GetWindowPosX();
		uint16_t GetWindowPosY();
		uint16_t GetWindowWidth();
		uint16_t GetWindowHeight();
	};

	//Will be defined in client-side code
	//e.g The Sandbox project
	Application* CreateApplication();
}