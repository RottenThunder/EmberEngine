#include "EmberEnginePCH.h"
#include "MathF_SSE.h"

namespace EmberEngine
{
	void MathF_SSE::ResetVector2Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE::ResetVector2Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
	}

	void MathF_SSE::ResetVector2Impl(int* vec)
	{
		vec[0] = 0;
		vec[1] = 0;
	}

	void MathF_SSE::Vector2AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector2AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
	}

	void MathF_SSE::Vector2AddImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
	}

	void MathF_SSE::Vector2SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector2SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
	}

	void MathF_SSE::Vector2SubImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
	}

	void MathF_SSE::Vector2MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector2MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
	}

	void MathF_SSE::Vector2MulImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
	}

	void MathF_SSE::Vector2DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector2DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
	}

	void MathF_SSE::Vector2DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
	}

	void MathF_SSE::ResetVector3Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE::ResetVector3Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
	}

	void MathF_SSE::ResetVector3Impl(int* vec)
	{
		vec[0] = 0;
		vec[1] = 0;
		vec[2] = 0;
	}

	void MathF_SSE::Vector3AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector3AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
	}

	void MathF_SSE::Vector3AddImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
	}

	void MathF_SSE::Vector3SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector3SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
	}

	void MathF_SSE::Vector3SubImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
	}

	void MathF_SSE::Vector3MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector3MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
	}

	void MathF_SSE::Vector3MulImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
	}

	void MathF_SSE::Vector3DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector3DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
	}

	void MathF_SSE::Vector3DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
	}

	void MathF_SSE::ResetVector4Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE::ResetVector4Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
		vec[3] = 0.0;
	}

	void MathF_SSE::ResetVector4Impl(int* vec)
	{
		vec[0] = 0;
		vec[1] = 0;
		vec[2] = 0;
		vec[3] = 0;
	}

	void MathF_SSE::Vector4AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector4AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
		dst[3] = vec1[3] + vec2[3];
	}

	void MathF_SSE::Vector4AddImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
		dst[3] = vec1[3] + vec2[3];
	}

	void MathF_SSE::Vector4SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector4SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
		dst[3] = vec1[3] - vec2[3];
	}

	void MathF_SSE::Vector4SubImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
		dst[3] = vec1[3] - vec2[3];
	}

	void MathF_SSE::Vector4MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector4MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
		dst[3] = vec1[3] * vec2[3];
	}

	void MathF_SSE::Vector4MulImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
		dst[3] = vec1[3] * vec2[3];
	}

	void MathF_SSE::Vector4DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE::Vector4DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
		dst[3] = vec1[3] / vec2[3];
	}

	void MathF_SSE::Vector4DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
		dst[3] = vec1[3] / vec2[3];
	}
}