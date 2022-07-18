#include "EmberEnginePCH.h"
#include "Renderer.h"

namespace EmberEngine
{
	void Renderer::BeginScene()
	{

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

	void Renderer::DrawVertexArray(const Ref<VertexArray>& vertexArray)
	{
		vertexArray->Bind();
		RenderCommand::Draw(vertexArray);
	}
}