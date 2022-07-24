#include "EmberEnginePCH.h"
#include "Colour.h"

namespace EmberEngine
{
	Colour::Colour()
	{
	}

	Colour::Colour(float red, float green, float blue)
		: Red(red), Green(green), Blue(blue), Alpha(1.0f)
	{
	}

	Colour::Colour(float red, float green, float blue, float alpha)
		: Red(red), Green(green), Blue(blue), Alpha(alpha)
	{
	}
}