#include "EmberEnginePCH.h"
#include "Application.h"
#include <glad/glad.h> //For the Clear Colour

namespace EmberEngine
{
	Application* Application::Instance = nullptr;

	Application::Application()
		: MainWindow(std::unique_ptr<Window>(Window::Create({ "Ember Engine", 1280ui16, 720ui16 })))
	{
		EMBER_REVERSE_ASSERT(Instance, "Application already exists");
		Instance = this;

		MainWindow->SetEventCallback(EMBER_BIND_EVENT_FUNCTION(OnEvent));

		glGenVertexArrays(1, &VertexArray);
		glBindVertexArray(VertexArray);

		glGenBuffers(1, &VertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

		float vertices[6] =
		{
			-0.5f, -0.5f, //Bottom-Left Corner
			0.5f, -0.5f, //Bottom-Right Corner
			0.0f, 0.5f //Top Corner
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), nullptr);

		glGenBuffers(1, &IndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (Running)
		{
			glClearColor(1.0f, 0.25f, 0.125f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glBindVertexArray(VertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : layerStack)
				layer->OnUpdate();

			MainWindow->OnUpdate();
		}

		glDeleteBuffers(1, &IndexBuffer);
		glDeleteBuffers(1, &VertexBuffer);
		glDeleteVertexArrays(1, &VertexArray);
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

	uint16_t Application::GetWindowPosX()
	{
		return Instance->GetWindow().GetPosX();
	}

	uint16_t Application::GetWindowPosY()
	{
		return Instance->GetWindow().GetPosY();
	}

	uint16_t Application::GetWindowWidth()
	{
		return Instance->GetWindow().GetWidth();
	}

	uint16_t Application::GetWindowHeight()
	{
		return Instance->GetWindow().GetHeight();
	}
}