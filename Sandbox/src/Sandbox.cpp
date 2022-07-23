#include <EmberEngine.h>

class ExampleLayer : public EmberEngine::Layer
{
private:
	//Square
	EmberEngine::Ref<EmberEngine::VertexArray> squareVertexArray;
	EmberEngine::Ref<EmberEngine::VertexBuffer> squareVertexBuffer;
	EmberEngine::Ref<EmberEngine::IndexBuffer> squareIndexBuffer;
	EmberEngine::Ref<EmberEngine::Shader> squareShader;
	EmberEngine::Ref<EmberEngine::Texture> squareTexture;

	//Triangle
	EmberEngine::Ref<EmberEngine::VertexArray> triangleVertexArray;
	EmberEngine::Ref<EmberEngine::VertexBuffer> triangleVertexBuffer;
	EmberEngine::Ref<EmberEngine::IndexBuffer> triangleIndexBuffer;
	EmberEngine::Ref<EmberEngine::Shader> triangleShader;

	//Camera
	EmberEngine::OrthographicCamera orthoCamera;
	EmberEngine::Vector2 cameraPosition;
public:
	ExampleLayer() : Layer("Example"), orthoCamera(-1.6f, 1.6f, -0.9f, 0.9f), cameraPosition(0.0f, 0.0f)
	{
		//Triangle

		triangleVertexArray = EmberEngine::VertexArray::Create();

		float vertices[3 * 6] =
		{
			-0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 1.0f, //Bottom-Left Corner
			0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, //Bottom-Right Corner
			0.0f, 0.5f, 1.0f, 0.0f, 1.0f, 1.0f //Top Corner
		};

		triangleVertexBuffer = EmberEngine::VertexBuffer::Create(vertices, sizeof(vertices));
		EmberEngine::BufferLayout layout =
		{
			{ EmberEngine::ShaderDataType::Vec2, "i_Position" },
			{ EmberEngine::ShaderDataType::Vec4, "i_Colour" }
		};
		triangleVertexBuffer->SetLayout(layout);

		triangleVertexArray->AddVertexBuffer(triangleVertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		triangleIndexBuffer = EmberEngine::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
		triangleVertexArray->SetIndexBuffer(triangleIndexBuffer);

		std::string vertexSrcTriangle = R"(
			#version 330 core
			layout(location = 0) in vec2 i_Position;
			layout(location = 1) in vec4 i_Colour;
			uniform mat4 u_ViewProjection;
			out vec4 v_Colour;
			void main()
			{
				v_Colour = i_Colour;
				gl_Position = u_ViewProjection * vec4(i_Position, 0.0, 1.0);
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

		triangleShader = EmberEngine::Shader::Create(vertexSrcTriangle, fragmentSrcTriangle);






		//Square

		squareVertexArray = EmberEngine::VertexArray::Create();

		float SquareVertices[4 * 4] =
		{
			-0.75f, -0.75f, 0.0f, 0.0f, //Bottom-Left
			0.75f, -0.75f, 1.0f, 0.0f, //Bottom-Right
			0.75f, 0.75f, 1.0f, 1.0f, //Top-Right
			-0.75f, 0.75f, 0.0f, 1.0f //Top-Left
		};

		squareVertexBuffer = EmberEngine::VertexBuffer::Create(SquareVertices, sizeof(SquareVertices));

		squareVertexBuffer->SetLayout({
			{ EmberEngine::ShaderDataType::Vec2, "i_Position" },
			{ EmberEngine::ShaderDataType::Vec2, "i_TexCoord"}
			});
		squareVertexArray->AddVertexBuffer(squareVertexBuffer);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		squareIndexBuffer = EmberEngine::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		squareVertexArray->SetIndexBuffer(squareIndexBuffer);

		squareShader = EmberEngine::Shader::Create("Assets/Shaders/Texture.eesl");

		squareTexture = EmberEngine::Texture::Create("Assets/Textures/TestCharacter.png");

		squareShader->Bind();
		squareShader->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate() override
	{
		//std::cout << "DeltaTime: " << EmberEngine::Time::GetDeltaTime32() << std::endl;

		EmberEngine::Renderer::ClearScreen(0.25f, 0.25f, 0.25f);

		if (EmberEngine::Input::IsKeyPressed(EMBER_KEY_A))
		{
			cameraPosition.x -= EmberEngine::Time::GetDeltaTime32();
		}
		if (EmberEngine::Input::IsKeyPressed(EMBER_KEY_D))
		{
			cameraPosition.x += EmberEngine::Time::GetDeltaTime32();
		}
		if (EmberEngine::Input::IsKeyPressed(EMBER_KEY_W))
		{
			cameraPosition.y += EmberEngine::Time::GetDeltaTime32();
		}
		if (EmberEngine::Input::IsKeyPressed(EMBER_KEY_S))
		{
			cameraPosition.y -= EmberEngine::Time::GetDeltaTime32();
		}

		EmberEngine::Renderer::BeginScene(orthoCamera);

		squareTexture->Bind();
		EmberEngine::Renderer::DrawVertexArray(squareShader, squareVertexArray);

		EmberEngine::Renderer::DrawVertexArray(triangleShader, triangleVertexArray);

		EmberEngine::Renderer::EndScene();

		orthoCamera.SetPositionAndRotation(cameraPosition, orthoCamera.GetRotation() + EmberEngine::Time::GetDeltaTime32() * 10.0f);
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