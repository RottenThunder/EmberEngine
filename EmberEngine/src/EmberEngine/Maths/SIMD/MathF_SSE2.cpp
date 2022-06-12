#include "EmberEnginePCH.h"
#include "MathF_SSE2.h"

namespace EmberEngine
{
	void MathF_SSE2::ResetVector2Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE2::ResetVector2Impl(double* vec)
	{
		_mm_storeu_pd(vec, _mm_setzero_pd());
	}

	void MathF_SSE2::ResetVector2Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_SSE2::Vector2AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector2AddImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_add_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE2::Vector2AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE2::Vector2SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector2SubImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_sub_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE2::Vector2SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE2::Vector2MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector2MulImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_mul_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE2::Vector2MulImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mul_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE2::Vector2DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector2DivImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_div_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE2::Vector2DivImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_div_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE2::ResetVector3Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE2::ResetVector3Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
	}

	void MathF_SSE2::ResetVector3Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_SSE2::Vector3AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector3AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
	}

	void MathF_SSE2::Vector3AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE2::Vector3SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector3SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
	}

	void MathF_SSE2::Vector3SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE2::Vector3MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector3MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
	}

	void MathF_SSE2::Vector3MulImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mul_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE2::Vector3DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector3DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
	}

	void MathF_SSE2::Vector3DivImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_div_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE2::ResetVector4Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE2::ResetVector4Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
		vec[3] = 0.0;
	}

	void MathF_SSE2::ResetVector4Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_SSE2::Vector4AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector4AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
		dst[3] = vec1[3] + vec2[3];
	}

	void MathF_SSE2::Vector4AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE2::Vector4SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector4SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
		dst[3] = vec1[3] - vec2[3];
	}

	void MathF_SSE2::Vector4SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE2::Vector4MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector4MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
		dst[3] = vec1[3] * vec2[3];
	}

	void MathF_SSE2::Vector4MulImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mul_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE2::Vector4DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE2::Vector4DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
		dst[3] = vec1[3] / vec2[3];
	}

	void MathF_SSE2::Vector4DivImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_div_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}
}