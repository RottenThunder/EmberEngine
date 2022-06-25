#pragma once
#include "EmberEngine/Maths/MathF.h"

namespace EmberEngine
{
	class Matrix4x4
	{
	public:
		float x0, y0, z0, w0;
		float x1, y1, z1, w1;
		float x2, y2, z2, w2;
		float x3, y3, z3, w3;
	public:
		Matrix4x4() { MathF::ResetMatrix4x4(&x0); }

		inline void Reset() { MathF::ResetMatrix4x4(&x0); }
		inline void ToIdentity() { MathF::SetToIdentity(&x0); }
	};

	Matrix4x4 CreateOrthographic(float left, float right, float bottom, float top);
}