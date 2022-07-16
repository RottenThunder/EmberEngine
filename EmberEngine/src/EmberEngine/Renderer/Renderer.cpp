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

	void Renderer::ClearScreen(const Colour& colour)
	{
		RenderCommand::SetClearColour(colour);
		RenderCommand::Clear();
	}

	void Renderer::DrawVertexArray(const std::shared_ptr<VertexArray>& vertexArray)
	{
		vertexArray->Bind();
		RenderCommand::Draw(vertexArray);
	}
}