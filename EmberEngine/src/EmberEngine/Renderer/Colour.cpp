#include "EmberEnginePCH.h"
#include "Colour.h"

namespace EmberEngine
{
	Colour::Colour()
	{
	}

	Colour::Colour(float red, float green, float blue, float alpha)
		: Red(red), Green(green), Blue(blue), Alpha(alpha)
	{
	}

	void Colour::SetToTransparent()
	{
		MathF::ResetVector4(&Red);
	}
}