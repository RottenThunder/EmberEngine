#include "EmberEnginePCH.h"
#include "Application.h"
#include "ProcessorAnalyser.h"
#include <glad/glad.h> //For the Clear Colour

namespace EmberEngine
{
	Application* Application::Instance = nullptr;

	Application::Application()
		: MainWindow(std::unique_ptr<Window>(Window::Create({ "Ember Engine", 1280, 720 })))
	{
		EMBER_REVERSE_ASSERT(Instance, "Application already exists");
		Instance = this;

		std::cout << "CPU: " << ProcessorAnalyser::Brand << std::endl;
		std::cout << "GPU: " << MainWindow->GetGraphicsContext()->GetGPU() << std::endl;

		MainWindow->SetEventCallback(EMBER_BIND_EVENT_FUNCTION(OnEvent));

		vertexArray.reset(VertexArray::Create());

		float vertices[3 * 6] =
		{
			-0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 1.0f, //Bottom-Left Corner
			0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, //Bottom-Right Corner
			0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f //Top Corner
		};

		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
		BufferLayout layout =
		{
			{ ShaderDataType::Vec2, "i_Position" },
			{ ShaderDataType::Vec4, "i_Colour" }
		};
		vertexBuffer->SetLayout(layout);

		vertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		vertexArray->SetIndexBuffer(indexBuffer);

		std::string vertexSrc = R"(
			#version 330 core
			layout(location = 0) in vec2 i_Position;
			layout(location = 1) in vec4 i_Colour;
			out vec2 v_Position;
			out vec4 v_Colour;
			void main()
			{
				v_Position = i_Position;
				v_Colour = i_Colour;
				gl_Position = vec4(i_Position, 0.0, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			layout(location = 0) out vec4 Colour;
			in vec2 v_Position;
			in vec4 v_Colour;
			void main()
			{
				Colour = v_Colour;
			}
		)";

		shader.reset(new Shader(vertexSrc, fragmentSrc));






		//Square

		squareVertexArray.reset(VertexArray::Create());

		float SquareVertices[4 * 2] =
		{
			-0.75f, -0.75f, //Bottom-Left
			0.75f, -0.75f, //Bottom-Right
			0.75f, 0.75f, //Top-Right
			-0.75f, 0.75f //Top-Left
		};

		std::shared_ptr<VertexBuffer> squareVertexBuffer;
		squareVertexBuffer.reset(VertexBuffer::Create(SquareVertices, sizeof(SquareVertices)));

		squareVertexBuffer->SetLayout({
			{ ShaderDataType::Vec2, "i_Position" }
			});

		squareVertexArray->AddVertexBuffer(squareVertexBuffer);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<IndexBuffer> squareIndexBuffer;
		squareIndexBuffer.reset(IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));

		squareVertexArray->SetIndexBuffer(squareIndexBuffer);

		std::string vertexSrcSquare = R"(
			#version 330 core
			layout(location = 0) in vec2 i_Position;
			out vec2 v_Position;
			void main()
			{
				v_Position = i_Position;
				gl_Position = vec4(i_Position, 0.0, 1.0);
			}
		)";

		std::string fragmentSrcSquare = R"(
			#version 330 core
			layout(location = 0) out vec4 Colour;
			in vec2 v_Position;
			void main()
			{
				Colour = vec4(0.1, v_Position + 0.5, 1.0);
			}
		)";

		shaderSquare.reset(new Shader(vertexSrcSquare, fragmentSrcSquare));
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

			shaderSquare->Bind();
			squareVertexArray->Bind();
			glDrawElements(GL_TRIANGLES, squareVertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

			shader->Bind();
			vertexArray->Bind();
			glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : layerStack)
				layer->OnUpdate();

			MainWindow->OnUpdate();
		}
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

	int32_t Application::GetWindowPosX()
	{
		return Instance->GetWindow().GetPosX();
	}

	int32_t Application::GetWindowPosY()
	{
		return Instance->GetWindow().GetPosY();
	}

	Vector2i Application::GetWindowPos()
	{
		return Instance->GetWindow().GetPos();
	}

	int32_t Application::GetWindowWidth()
	{
		return Instance->GetWindow().GetWidth();
	}

	int32_t Application::GetWindowHeight()
	{
		return Instance->GetWindow().GetHeight();
	}
}