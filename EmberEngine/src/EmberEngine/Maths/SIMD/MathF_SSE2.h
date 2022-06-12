#pragma once
#include "EmberEngine/Maths/MathF.h"

namespace EmberEngine
{
	class MathF_SSE2 : public MathF
	{
	protected:
		//Vector2 Implementation
		virtual void ResetVector2Impl(float* vec) override;
		virtual void ResetVector2Impl(double* vec) override;
		virtual void ResetVector2Impl(int* vec) override;
		virtual void Vector2AddImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector2AddImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector2AddImpl(int* dst, int* vec1, int* vec2) override;
		virtual void Vector2SubImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector2SubImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector2SubImpl(int* dst, int* vec1, int* vec2) override;
		virtual void Vector2MulImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector2MulImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector2MulImpl(int* dst, int* vec1, int* vec2) override;
		virtual void Vector2DivImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector2DivImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector2DivImpl(int* dst, int* vec1, int* vec2) override;

		//Vector3 Implementation
		virtual void ResetVector3Impl(float* vec) override;
		virtual void ResetVector3Impl(double* vec) override;
		virtual void ResetVector3Impl(int* vec) override;
		virtual void Vector3AddImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector3AddImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector3AddImpl(int* dst, int* vec1, int* vec2) override;
		virtual void Vector3SubImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector3SubImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector3SubImpl(int* dst, int* vec1, int* vec2) override;
		virtual void Vector3MulImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector3MulImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector3MulImpl(int* dst, int* vec1, int* vec2) override;
		virtual void Vector3DivImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector3DivImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector3DivImpl(int* dst, int* vec1, int* vec2) override;

		//Vector4 Implementation
		virtual void ResetVector4Impl(float* vec) override;
		virtual void ResetVector4Impl(double* vec) override;
		virtual void ResetVector4Impl(int* vec) override;
		virtual void Vector4AddImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector4AddImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector4AddImpl(int* dst, int* vec1, int* vec2) override;
		virtual void Vector4SubImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector4SubImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector4SubImpl(int* dst, int* vec1, int* vec2) override;
		virtual void Vector4MulImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector4MulImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector4MulImpl(int* dst, int* vec1, int* vec2) override;
		virtual void Vector4DivImpl(float* dst, float* vec1, float* vec2) override;
		virtual void Vector4DivImpl(double* dst, double* vec1, double* vec2) override;
		virtual void Vector4DivImpl(int* dst, int* vec1, int* vec2) override;
	};
}