#include "EmberEnginePCH.h"
#include "MathF_NULL.h"

namespace EmberEngine
{
	MathF* MathF::Instance = new MathF_NULL();

	void MathF_NULL::ResetVector2Impl(float* vec)
	{
		vec[0] = 0.0f;
		vec[1] = 0.0f;
	}

	void MathF_NULL::ResetVector2Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
	}

	void MathF_NULL::ResetVector2Impl(int* vec)
	{
		vec[0] = 0;
		vec[1] = 0;
	}

	void MathF_NULL::ResetVector3Impl(float* vec)
	{
		vec[0] = 0.0f;
		vec[1] = 0.0f;
		vec[2] = 0.0f;
	}

	void MathF_NULL::ResetVector3Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
	}

	void MathF_NULL::ResetVector3Impl(int* vec)
	{
		vec[0] = 0;
		vec[1] = 0;
		vec[2] = 0;
	}

	void MathF_NULL::ResetVector4Impl(float* vec)
	{
		vec[0] = 0.0f;
		vec[1] = 0.0f;
		vec[2] = 0.0f;
		vec[3] = 0.0f;
	}

	void MathF_NULL::ResetVector4Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
		vec[3] = 0.0;
	}

	void MathF_NULL::ResetVector4Impl(int* vec)
	{
		vec[0] = 0;
		vec[1] = 0;
		vec[2] = 0;
		vec[3] = 0;
	}
}