#include "EmberEnginePCH.h"
#include "OpenGLRendererAPI.h"
#include <glad/glad.h>

namespace EmberEngine
{
	void OpenGLRendererAPI::Init()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLRendererAPI::SetClearColour(float red, float green, float blue)
	{
		glClearColor(red, green, blue, 1.0f);
	}

	void OpenGLRendererAPI::SetClearColour(const Colour& colour)
	{
		glClearColor(colour.Red, colour.Green, colour.Blue, colour.Alpha);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void OpenGLRendererAPI::SetViewport(int32_t x, int32_t y, int32_t width, int32_t height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLRendererAPI::Draw(const Ref<VertexArray>& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}
}