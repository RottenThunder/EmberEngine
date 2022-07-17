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
		virtual void Draw(const std::shared_ptr<VertexArray>& vertexArray) override;
	};
}