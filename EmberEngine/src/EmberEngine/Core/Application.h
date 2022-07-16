#pragma once
#include "Base.h"
#include "Window.h"
#include "LayerStack.h"
#include "EmberEngine/Events/ApplicationEvent.h"
#include "EmberEngine/Renderer/Colour.h"
#include "EmberEngine/Renderer/Buffer.h"
#include "EmberEngine/Renderer/VertexArray.h"
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

		Colour clearColour;

		std::shared_ptr<Shader> shader;
		std::shared_ptr<VertexArray> vertexArray;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<IndexBuffer> indexBuffer;

		std::shared_ptr<VertexArray> squareVertexArray;
		std::shared_ptr<Shader> shaderSquare;

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