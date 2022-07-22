#pragma once
#include <string>
#include "EmberEngine/Core/Base.h"

namespace EmberEngine
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void Bind(uint32_t slot = 0) const = 0;
		virtual void UnBind(uint32_t slot = 0) const = 0;

		static Ref<Texture> Create(const std::string& filePath);
	};
}