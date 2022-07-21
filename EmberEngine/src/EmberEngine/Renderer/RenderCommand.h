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
		inline static void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height) { rendererAPI->SetViewport(x, y, width, height); }
		inline static void Clear() { rendererAPI->Clear(); }
		inline static void Draw(const Ref<VertexArray>& vertexArray) { rendererAPI->Draw(vertexArray); }
	};
}