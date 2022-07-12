#include "EmberEnginePCH.h"
#include "Application.h"
#include "ProcessorAnalyser.h"
#include <glad/glad.h> //For the Clear Colour

namespace EmberEngine
{
	Application* Application::Instance = nullptr;

	Application::Application()
		: MainWindow(std::unique_ptr<Window>(Window::Create({ "Ember Engine", 1280ui16, 720ui16 })))
	{
		EMBER_REVERSE_ASSERT(Instance, "Application already exists");
		Instance = this;

		std::cout << "CPU: " << ProcessorAnalyser::Brand << std::endl;
		std::cout << "GPU: " << MainWindow->GetGraphicsContext()->GetGPU() << std::endl;

		MainWindow->SetEventCallback(EMBER_BIND_EVENT_FUNCTION(OnEvent));

		glGenVertexArrays(1, &VertexArray);
		glBindVertexArray(VertexArray);

		float vertices[6] =
		{
			-0.5f, -0.5f, //Bottom-Left Corner
			0.5f, -0.5f, //Bottom-Right Corner
			0.0f, 0.5f //Top Corner
		};

		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), nullptr);

		uint32_t indices[3] = { 0, 1, 2 };
		indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

		std::string vertexSrc = R"(
			#version 330 core
			layout(location = 0) in vec2 i_Position;
			out vec2 v_Position;
			void main()
			{
				v_Position = i_Position;
				gl_Position = vec4(i_Position, 0.0, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			layout(location = 0) out vec4 Colour;
			in vec2 v_Position;
			void main()
			{
				Colour = vec4(0.0, v_Position + 0.5, 1.0);
			}
		)";

		shader.reset(new Shader(vertexSrc, fragmentSrc));
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

			shader->Bind();

			glBindVertexArray(VertexArray);
			glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : layerStack)
				layer->OnUpdate();

			MainWindow->OnUpdate();
		}

		shader->UnBind();
		indexBuffer->UnBind();
		vertexBuffer->UnBind();
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