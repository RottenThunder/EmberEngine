#pragma once
#include "EmberEngine/Core/Base.h"
#include "RenderCommand.h"

namespace EmberEngine
{
	class Renderer
	{
	public:
		inline static API GetAPI() { return RendererAPI::GetAPI(); }

		static void BeginScene();
		static void EndScene();

		static void ClearScreen(float red, float green, float blue);
		static void ClearScreen(const Colour& colour);
		static void DrawVertexArray(const std::shared_ptr<VertexArray>& vertexArray);
	};
}