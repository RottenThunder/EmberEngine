#pragma once
#include "EmberEngine/Renderer/Texture.h"

namespace EmberEngine
{
	class OpenGLTexture : public Texture
	{
	private:
		std::string FilePath;
		uint32_t Width, Height;
		uint32_t RendererID;
	public:
		OpenGLTexture(const std::string& filePath);
		virtual ~OpenGLTexture();

		virtual uint32_t GetWidth() const override { return Width; }
		virtual uint32_t GetHeight() const override { return Height; }

		virtual void Bind(uint32_t slot = 0) const override;
		virtual void UnBind(uint32_t slot = 0) const override;
	};
}