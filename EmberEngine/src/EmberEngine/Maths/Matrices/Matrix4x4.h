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
		inline void ToTranslation(float* vec2) { MathF::SetToTranslation(&x0, vec2); }
		inline void ToScale(float* vec2) { MathF::SetToScale(&x0, vec2); }
		inline void ToRotation(float radians) { MathF::SetToRotation(&x0, radians); }
		inline void ToTranslationWithoutReset(float* vec2) { MathF::SetToTranslationWithoutReset(&x0, vec2); }
		inline void ToScaleWithoutReset(float* vec2) { MathF::SetToScaleWithoutReset(&x0, vec2); }
		inline void ToRotationWithoutReset(float radians) { MathF::SetToRotationWithoutReset(&x0, radians); }
	};

	Matrix4x4 CreateTranslation(float x, float y);
	Matrix4x4 CreateTranslation(float* vec2);
	Matrix4x4 CreateScale(float sx, float sy);
	Matrix4x4 CreateScale(float* vec2);
	Matrix4x4 CreateRotation(float radians);
	Matrix4x4 CreateOrthographic(float left, float right, float bottom, float top);
}