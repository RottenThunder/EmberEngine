#include "EmberEnginePCH.h"
#include "OpenGLTexture.h"
#include "stb_image.h"
#include <glad/glad.h>

namespace EmberEngine
{
	OpenGLTexture::OpenGLTexture(const std::string& filePath)
		: FilePath(filePath)
	{
		int32_t width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(filePath.c_str(), &width, &height, &channels, 0);
		EMBER_ASSERT(data, "Failed to load Image!");
		Width = width;
		Height = height;

		GLenum internalFormat = 0, dataFormat = 0;
		if (channels == 4)
		{
			internalFormat = GL_RGBA8;
			dataFormat = GL_RGBA;
		}
		else if (channels == 3)
		{
			internalFormat = GL_RGB8;
			dataFormat = GL_RGB;
		}

		EMBER_ASSERT(internalFormat & dataFormat, "Format Not Supported!");

		glCreateTextures(GL_TEXTURE_2D, 1, &RendererID);
		glTextureStorage2D(RendererID, 1, internalFormat, Width, Height);

		glTextureParameteri(RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTextureSubImage2D(RendererID, 0, 0, 0, Width, Height, dataFormat, GL_UNSIGNED_BYTE, data);

		stbi_image_free(data);
	}

	OpenGLTexture::~OpenGLTexture()
	{
		glDeleteTextures(1, &RendererID);
	}

	void OpenGLTexture::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, RendererID);
	}

	void OpenGLTexture::UnBind(uint32_t slot) const
	{
		glBindTextureUnit(slot, 0);
	}
}