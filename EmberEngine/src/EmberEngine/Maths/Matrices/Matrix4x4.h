#pragma once
#include "EmberEngine/Maths/MathF.h"
#include "EmberEngine/Maths/Vectors/Vector3.h"

namespace EmberEngine
{
	class Matrix4x4
	{
	public:
		float x0, y0, z0, w0;      //[x0, x1, x2, x3]
		float x1, y1, z1, w1;	   //[y0, y1, y2, y3]
		float x2, y2, z2, w2;	   //[z0, z1, z2, z3]
		float x3, y3, z3, w3;	   //[w0, w1, w2, w3]
	public:
		Matrix4x4() {}

		inline void Reset() { MathF::ResetMatrix4x4(&x0); }
		inline void ToIdentity() { MathF::SetToIdentity(&x0); }
		inline void Multiply(Matrix4x4 matrix) { MathF::MultiplyMatrix4x4(&x0, &x0, &matrix.x0); }
		inline void ToTranslation(float* vec2) { MathF::SetToTranslation(&x0, vec2); }
		inline void ToScale(float* vec2) { MathF::SetToScale(&x0, vec2); }
		inline void ToRotation(float radians) { MathF::SetToRotation(&x0, radians); }
		inline void ToTranslationWithoutReset(float* vec2) { MathF::SetToTranslationWithoutReset(&x0, vec2); }
		inline void ToScaleWithoutReset(float* vec2) { MathF::SetToScaleWithoutReset(&x0, vec2); }
		inline void ToRotationWithoutReset(float radians) { MathF::SetToRotationWithoutReset(&x0, radians); }
	};

	inline Matrix4x4 operator*(Matrix4x4 a, Matrix4x4 b) { Matrix4x4 result; MathF::MultiplyMatrix4x4(&result.x0, &a.x0, &b.x0); return result; }
	inline Matrix4x4& operator*= (Matrix4x4& matrix1, Matrix4x4 matrix2) { MathF::MultiplyMatrix4x4(&matrix1.x0, &matrix1.x0, &matrix2.x0); return matrix1; }

	Matrix4x4 CreateTranslation(float x, float y);
	Matrix4x4 CreateTranslation(float* vec2);
	Matrix4x4 CreateScale(float sx, float sy);
	Matrix4x4 CreateScale(float* vec2);
	Matrix4x4 CreateRotation(float radians);
	Matrix4x4 CreateView();
	Matrix4x4 CreateView(Vector3 eye, Vector3 target, Vector3 up);
	Matrix4x4 CreateOrthographic(float left, float right, float bottom, float top);
}