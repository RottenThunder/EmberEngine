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
}