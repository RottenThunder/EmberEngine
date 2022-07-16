#include "EmberEnginePCH.h"
#include "RenderCommand.h"
#include "EmberEngine/Platform/OpenGL/OpenGLRendererAPI.h"

namespace EmberEngine
{
	RendererAPI* RenderCommand::rendererAPI = new OpenGLRendererAPI;
}