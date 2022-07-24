#include "EmberEnginePCH.h"
#include "Renderer.h"

namespace EmberEngine
{
	Renderer::SceneData* Renderer::sceneData = new Renderer::SceneData;

	struct RendererStorage
	{
		Ref<VertexArray> QuadVertexArray;
		Ref<Shader> ColourShader;
		Ref<Shader> TextureShader;
	};

	static RendererStorage* Data;

	void Renderer::Init()
	{
		RenderCommand::Init();

		Data = new RendererStorage();

		Data->QuadVertexArray = VertexArray::Create();

		float SquareVertices[4 * 4] =
		{
			-0.5f, -0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.0f, 1.0f
		};

		Ref<VertexBuffer> squareVertexBuffer;
		squareVertexBuffer = VertexBuffer::Create(SquareVertices, sizeof(SquareVertices));

		squareVertexBuffer->SetLayout({
			{ ShaderDataType::Vec2, "i_Position" },
			{ ShaderDataType::Vec2, "i_TexCoord" }
			});

		Data->QuadVertexArray->AddVertexBuffer(squareVertexBuffer);

		Ref<IndexBuffer> squareIndexBuffer;
		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		squareIndexBuffer = IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));

		Data->QuadVertexArray->SetIndexBuffer(squareIndexBuffer);

		Data->ColourShader = Shader::Create("Assets/Shaders/Colour.eesl");
		Data->TextureShader = Shader::Create("Assets/Shaders/Texture.eesl");
		Data->TextureShader->Bind();
		Data->TextureShader->UploadUniformInt("u_Texture", 0);
	}

	void Renderer::Terminate()
	{
		delete Data;
	}

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		sceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();

		Data->ColourShader->Bind();
		Data->ColourShader->UploadUniformMatrix4x4("u_ViewProjection", sceneData->ViewProjectionMatrix);

		Data->TextureShader->Bind();
		Data->TextureShader->UploadUniformMatrix4x4("u_ViewProjection", sceneData->ViewProjectionMatrix);
	}

	void Renderer::EndScene()
	{

	}

	void Renderer::DrawQuad(const Vector2& position, const Vector2& size, const Colour& colour)
	{
		Data->ColourShader->Bind();
		Data->ColourShader->UploadUniformVector4f("u_Colour", colour);

		Matrix4x4 transform = CreateTranslation(position.x, position.y) * CreateScale(size.x, size.y);
		Data->ColourShader->UploadUniformMatrix4x4("u_Transform", transform);

		Data->QuadVertexArray->Bind();
		RenderCommand::Draw(Data->QuadVertexArray);
	}

	void Renderer::DrawQuad(const Vector2& position, const Vector2& size, const Ref<Texture>& texture)
	{
		Data->TextureShader->Bind();

		Matrix4x4 transform = CreateTranslation(position.x, position.y) * CreateScale(size.x, size.y);
		Data->TextureShader->UploadUniformMatrix4x4("u_Transform", transform);
		Data->TextureShader->UploadUniformVector4f("u_Colour", { 1.0f, 1.0f, 1.0f });

		texture->Bind();

		Data->QuadVertexArray->Bind();
		RenderCommand::Draw(Data->QuadVertexArray);
	}

	void Renderer::DrawQuad(const Vector2& position, const Vector2& size, const Ref<Texture>& texture, const Colour& tint)
	{
		Data->TextureShader->Bind();

		Matrix4x4 transform = CreateTranslation(position.x, position.y) * CreateScale(size.x, size.y);
		Data->TextureShader->UploadUniformMatrix4x4("u_Transform", transform);
		Data->TextureShader->UploadUniformVector4f("u_Colour", tint);

		texture->Bind();

		Data->QuadVertexArray->Bind();
		RenderCommand::Draw(Data->QuadVertexArray);
	}

	void Renderer::ClearScreen(float red, float green, float blue)
	{
		RenderCommand::SetClearColour(red, green, blue);
		RenderCommand::Clear();
	}

	void Renderer::ClearScreen(const Colour& colour)
	{
		RenderCommand::SetClearColour(colour);
		RenderCommand::Clear();
	}

	void Renderer::OnWindowResize(int32_t width, int32_t height)
	{
		RenderCommand::SetViewport(0, 0, width, height);
	}
}