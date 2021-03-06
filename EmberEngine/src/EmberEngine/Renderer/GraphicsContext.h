#pragma once

namespace EmberEngine
{
	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
		virtual std::string GetVersion() = 0;
		virtual std::string GetGPU() = 0;
	};
}