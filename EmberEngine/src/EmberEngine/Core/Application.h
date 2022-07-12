#pragma once
#include "Base.h"
#include "Window.h"
#include "LayerStack.h"
#include "EmberEngine/Events/ApplicationEvent.h"
#include "EmberEngine/Renderer/Buffer.h"
#include "EmberEngine/Renderer/Shader.h"

namespace EmberEngine
{
	class Application
	{
	private:
		static Application* Instance;

		bool Running = true;
		std::unique_ptr<Window> MainWindow;
		LayerStack layerStack;

		uint32_t VertexArray;
		std::unique_ptr<VertexBuffer> vertexBuffer;
		std::unique_ptr<IndexBuffer> indexBuffer;
		std::unique_ptr<Shader> shader;

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