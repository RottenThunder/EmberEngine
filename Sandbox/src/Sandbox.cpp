#include <EmberEngine.h>

class ExampleLayer : public EmberEngine::Layer
{
private:
	//Square
	EmberEngine::Ref<EmberEngine::VertexArray> squareVertexArray;
	EmberEngine::Ref<EmberEngine::VertexBuffer> squareVertexBuffer;
	EmberEngine::Ref<EmberEngine::IndexBuffer> squareIndexBuffer;
	EmberEngine::Ref<EmberEngine::Shader> squareShader;

	//Triangle
	EmberEngine::Ref<EmberEngine::VertexArray> triangleVertexArray;
	EmberEngine::Ref<EmberEngine::VertexBuffer> triangleVertexBuffer;
	EmberEngine::Ref<EmberEngine::IndexBuffer> triangleIndexBuffer;
	EmberEngine::Ref<EmberEngine::Shader> triangleShader;
public:
	ExampleLayer() : Layer("Example")
	{
		//Triangle

		triangleVertexArray.reset(EmberEngine::VertexArray::Create());

		float vertices[3 * 6] =
		{
			-0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 1.0f, //Bottom-Left Corner
			0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, //Bottom-Right Corner
			0.0f, 0.5f, 1.0f, 0.0f, 1.0f, 1.0f //Top Corner
		};

		triangleVertexBuffer.reset(EmberEngine::VertexBuffer::Create(vertices, sizeof(vertices)));
		EmberEngine::BufferLayout layout =
		{
			{ EmberEngine::ShaderDataType::Vec2, "i_Position" },
			{ EmberEngine::ShaderDataType::Vec4, "i_Colour" }
		};
		triangleVertexBuffer->SetLayout(layout);

		triangleVertexArray->AddVertexBuffer(triangleVertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		triangleIndexBuffer.reset(EmberEngine::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		triangleVertexArray->SetIndexBuffer(triangleIndexBuffer);

		std::string vertexSrcTriangle = R"(
			#version 330 core
			layout(location = 0) in vec2 i_Position;
			layout(location = 1) in vec4 i_Colour;
			out vec4 v_Colour;
			void main()
			{
				v_Colour = i_Colour;
				gl_Position = vec4(i_Position, 0.0, 1.0);
			}
		)";

		std::string fragmentSrcTriangle = R"(
			#version 330 core
			layout(location = 0) out vec4 Colour;
			in vec4 v_Colour;
			void main()
			{
				Colour = v_Colour;
			}
		)";

		triangleShader.reset(EmberEngine::Shader::Create(vertexSrcTriangle, fragmentSrcTriangle));






		//Square

		squareVertexArray.reset(EmberEngine::VertexArray::Create());

		float SquareVertices[4 * 2] =
		{
			-0.75f, -0.75f, //Bottom-Left
			0.75f, -0.75f, //Bottom-Right
			0.75f, 0.75f, //Top-Right
			-0.75f, 0.75f //Top-Left
		};

		squareVertexBuffer.reset(EmberEngine::VertexBuffer::Create(SquareVertices, sizeof(SquareVertices)));

		squareVertexBuffer->SetLayout({
			{ EmberEngine::ShaderDataType::Vec2, "i_Position" }
			});
		squareVertexArray->AddVertexBuffer(squareVertexBuffer);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		squareIndexBuffer.reset(EmberEngine::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
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
				Colour = vec4(v_Position + 0.75, 0.0, 1.0);
			}
		)";

		squareShader.reset(EmberEngine::Shader::Create(vertexSrcSquare, fragmentSrcSquare));
	}

	void OnUpdate() override
	{
		std::cout << "DeltaTime: " << EmberEngine::Time::GetDeltaTime32() << std::endl;

		EmberEngine::Renderer::ClearScreen(0.25f, 0.25f, 0.25f);

		EmberEngine::Renderer::BeginScene();

		squareShader->Bind();
		EmberEngine::Renderer::DrawVertexArray(squareVertexArray);

		triangleShader->Bind();
		EmberEngine::Renderer::DrawVertexArray(triangleVertexArray);

		EmberEngine::Renderer::EndScene();

		if (EmberEngine::Input::IsKeyPressed(EMBER_KEY_A))
		{
			std::cout << "A Key Was Pressed!" << std::endl;
		}
	}

	void OnEvent(EmberEngine::Event& e) override
	{
		if (e.GetEventType() == EmberEngine::EventType::KeyPressed)
		{
			EmberEngine::KeyPressedEvent& keyEvent = (EmberEngine::KeyPressedEvent&)e;
			std::cout << char(keyEvent.GetKeyCode()) << std::endl;
		}
	}
};

class Sandbox : public EmberEngine::Application
{
private:
	ExampleLayer* Example = nullptr;
public:
	Sandbox()
		: Example(new ExampleLayer)
	{
		PushLayer(Example);
		std::cout << "Initial Window Position: " << GetWindowPosX() << ", " << GetWindowPosY() << std::endl;
		std::cout << "Initial Window Size: " << GetWindowWidth() << ", " << GetWindowHeight() << std::endl;
	}

	~Sandbox()
	{
		PopLayer(Example);
	}
};

EmberEngine::Application* EmberEngine::CreateApplication()
{
	return new Sandbox();
}