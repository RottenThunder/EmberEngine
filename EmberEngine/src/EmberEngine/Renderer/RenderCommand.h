#pragma once
#include "RendererAPI.h"

namespace EmberEngine
{
	class RenderCommand
	{
	private:
		static RendererAPI* rendererAPI;
	public:
		inline static void SetClearColour(float red, float green, float blue) { rendererAPI->SetClearColour(red, green, blue); }
		inline static void SetClearColour(const Colour& colour) { rendererAPI->SetClearColour(colour); }
		inline static void Clear() { rendererAPI->Clear(); }
		inline static void Draw(const std::shared_ptr<VertexArray>& vertexArray) { rendererAPI->Draw(vertexArray); }
	};
}