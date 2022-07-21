#pragma once
#include "Colour.h"
#include "VertexArray.h"

namespace EmberEngine
{
	enum class API
	{
		None = 0, OpenGL = 1
	};

	class RendererAPI
	{
	private:
		static API CurrentAPI;
	public:
		inline static API GetAPI() { return CurrentAPI; }

		virtual void SetClearColour(float red, float green, float blue) = 0;
		virtual void SetClearColour(const Colour& colour) = 0;
		virtual void Clear() = 0;
		virtual void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height) = 0;
		virtual void Draw(const Ref<VertexArray>& vertexArray) = 0;
	};
}