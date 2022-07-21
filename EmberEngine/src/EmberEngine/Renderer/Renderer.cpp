#include "EmberEnginePCH.h"
#include "Renderer.h"

namespace EmberEngine
{
	Renderer::SceneData* Renderer::sceneData = new Renderer::SceneData;

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		sceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{

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

	void Renderer::DrawVertexArray(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray)
	{
		shader->Bind();
		shader->UploadUniformMatrix4x4("u_ViewProjection", sceneData->ViewProjectionMatrix);

		vertexArray->Bind();
		RenderCommand::Draw(vertexArray);
	}
}