#include "EmberEnginePCH.h"
#include "MathF_SSE.h"

namespace EmberEngine
{
	//Vector2 Implementation

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

	void MathF_SSE::Vector2MulImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE::Vector2MulImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
	}

	void MathF_SSE::Vector2MulImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
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

	void MathF_SSE::Vector2DivImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE::Vector2DivImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
	}

	void MathF_SSE::Vector2DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
	}

	float MathF_SSE::Vector2MagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		sqReg.m128_f32[0] = sqReg.m128_f32[0] + sqReg.m128_f32[1];
		return _mm_sqrt_ps(sqReg).m128_f32[0];
	}

	float MathF_SSE::Vector2SqMagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return sqReg.m128_f32[0] + sqReg.m128_f32[1];
	}

	double MathF_SSE::Vector2MagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		return std::sqrt(xSq + ySq);
	}

	double MathF_SSE::Vector2SqMagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		return xSq + ySq;
	}

	float MathF_SSE::Vector2MagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		return std::sqrt((float)(xSq + ySq));
	}

	float MathF_SSE::Vector2SqMagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		return (float)(xSq + ySq);
	}

	void MathF_SSE::Vector2NormaliseImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		sqReg.m128_f32[0] = sqReg.m128_f32[0] + sqReg.m128_f32[1];
		_mm_storeu_ps(vec, _mm_div_ps(vecReg, _mm_set1_ps(_mm_sqrt_ps(sqReg).m128_f32[0])));
	}

	void MathF_SSE::Vector2NormaliseImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double length = std::sqrt(xSq + ySq);
		vec[0] /= length;
		vec[1] /= length;
	}

	//Vector3 Implementation

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

	void MathF_SSE::Vector3MulImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE::Vector3MulImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
	}

	void MathF_SSE::Vector3MulImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
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

	void MathF_SSE::Vector3DivImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE::Vector3DivImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
	}

	void MathF_SSE::Vector3DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
	}

	float MathF_SSE::Vector3MagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		sqReg.m128_f32[0] = sqReg.m128_f32[0] + sqReg.m128_f32[1] + sqReg.m128_f32[2];
		return _mm_sqrt_ps(sqReg).m128_f32[0];
	}

	float MathF_SSE::Vector3SqMagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return sqReg.m128_f32[0] + sqReg.m128_f32[1] + sqReg.m128_f32[2];
	}

	double MathF_SSE::Vector3MagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		return std::sqrt(xSq + ySq + zSq);
	}

	double MathF_SSE::Vector3SqMagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		return xSq + ySq + zSq;
	}

	float MathF_SSE::Vector3MagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		return std::sqrt((float)(xSq + ySq + zSq));
	}

	float MathF_SSE::Vector3SqMagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		return (float)(xSq + ySq + zSq);
	}

	void MathF_SSE::Vector3NormaliseImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		sqReg.m128_f32[0] = sqReg.m128_f32[0] + sqReg.m128_f32[1] + sqReg.m128_f32[2];
		_mm_storeu_ps(vec, _mm_div_ps(vecReg, _mm_set1_ps(_mm_sqrt_ps(sqReg).m128_f32[0])));
	}

	void MathF_SSE::Vector3NormaliseImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double length = std::sqrt(xSq + ySq + zSq);
		vec[0] /= length;
		vec[1] /= length;
		vec[2] /= length;
	}

	//Vector4 Implementation

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

	void MathF_SSE::Vector4MulImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE::Vector4MulImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
		dst[3] = vec[3] * scalar;
	}

	void MathF_SSE::Vector4MulImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
		dst[3] = vec[3] * scalar;
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

	void MathF_SSE::Vector4DivImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE::Vector4DivImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
		dst[3] = vec[3] / scalar;
	}

	void MathF_SSE::Vector4DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
		dst[3] = vec[3] / scalar;
	}

	float MathF_SSE::Vector4MagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		sqReg.m128_f32[0] = sqReg.m128_f32[0] + sqReg.m128_f32[1] + sqReg.m128_f32[2] + sqReg.m128_f32[3];
		return _mm_sqrt_ps(sqReg).m128_f32[0];
	}

	float MathF_SSE::Vector4SqMagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return sqReg.m128_f32[0] + sqReg.m128_f32[1] + sqReg.m128_f32[2] + sqReg.m128_f32[3];
	}

	double MathF_SSE::Vector4MagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double wSq = vec[3] * vec[3];
		return std::sqrt(xSq + ySq + zSq + wSq);
	}

	double MathF_SSE::Vector4SqMagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double wSq = vec[3] * vec[3];
		return xSq + ySq + zSq + wSq;
	}

	float MathF_SSE::Vector4MagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		int wSq = vec[3] * vec[3];
		return std::sqrt((float)(xSq + ySq + zSq + wSq));
	}

	float MathF_SSE::Vector4SqMagnitudeImpl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		int wSq = vec[3] * vec[3];
		return (float)(xSq + ySq + zSq + wSq);
	}

	void MathF_SSE::Vector4NormaliseImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		sqReg.m128_f32[0] = sqReg.m128_f32[0] + sqReg.m128_f32[1] + sqReg.m128_f32[2] + sqReg.m128_f32[3];
		_mm_storeu_ps(vec, _mm_div_ps(vecReg, _mm_set1_ps(_mm_sqrt_ps(sqReg).m128_f32[0])));
	}

	void MathF_SSE::Vector4NormaliseImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double wSq = vec[3] * vec[3];
		double length = std::sqrt(xSq + ySq + zSq + wSq);
		vec[0] /= length;
		vec[1] /= length;
		vec[2] /= length;
		vec[3] /= length;
	}
}