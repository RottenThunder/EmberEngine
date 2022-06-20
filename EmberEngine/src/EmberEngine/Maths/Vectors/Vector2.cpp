#include "EmberEnginePCH.h"
#include "Vector2.h"

namespace EmberEngine
{
	Vector2f V2Normalise(Vector2f vec)
	{
		Vector2f result = vec;
		MathF::Vector2Normalise(&result.x);
		return result;
	}

	Vector2d V2Normalise(Vector2d vec)
	{
		Vector2d result = vec;
		MathF::Vector2Normalise(&result.x);
		return result;
	}
}