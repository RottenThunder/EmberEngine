#pragma once
#include "EmberEngine/Renderer/RendererAPI.h"

namespace EmberEngine
{
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void SetClearColour(float red, float green, float blue) override;
		virtual void SetClearColour(const Colour& colour) override;
		virtual void Clear() override;
		virtual void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height) override;
		virtual void Draw(const Ref<VertexArray>& vertexArray) override;
	};
}