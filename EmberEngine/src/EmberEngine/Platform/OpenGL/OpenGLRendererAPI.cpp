#include "EmberEnginePCH.h"
#include "OpenGLRendererAPI.h"
#include <glad/glad.h>

namespace EmberEngine
{
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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::Draw(const std::shared_ptr<VertexArray>& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}
}