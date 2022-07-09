#include "EmberEnginePCH.h"
#include "Vector3.h"

namespace EmberEngine
{
	Vector3f V3Normalise(Vector3f vec)
	{
		Vector3f result = vec;
		MathF::Vector3Normalise(&result.x);
		return result;
	}

	Vector3d V3Normalise(Vector3d vec)
	{
		Vector3d result = vec;
		MathF::Vector3Normalise(&result.x);
		return result;
	}

	float V3Dot(Vector3f vec1, Vector3f vec2)
	{
		return MathF::Vector3Dot(&vec1.x, &vec2.x);
	}

	double V3Dot(Vector3d vec1, Vector3d vec2)
	{
		return MathF::Vector3Dot(&vec1.x, &vec2.x);
	}

	Vector3f V3Cross(Vector3f vec1, Vector3f vec2)
	{
		Vector3f result;
		MathF::Vector3Cross(&result.x, &vec1.x, &vec2.x);
		return result;
	}

	Vector3d V3Cross(Vector3d vec1, Vector3d vec2)
	{
		Vector3d result;
		MathF::Vector3Cross(&result.x, &vec1.x, &vec2.x);
		return result;
	}
}