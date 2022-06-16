#include "EmberEnginePCH.h"
#include "MathF_SSE3.h"

namespace EmberEngine
{
	void MathF_SSE3::ResetVector2Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE3::ResetVector2Impl(double* vec)
	{
		_mm_storeu_pd(vec, _mm_setzero_pd());
	}

	void MathF_SSE3::ResetVector2Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_SSE3::Vector2AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector2AddImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_add_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE3::Vector2AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE3::Vector2SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector2SubImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_sub_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE3::Vector2SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE3::Vector2MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector2MulImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_mul_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE3::Vector2MulImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
	}

	void MathF_SSE3::Vector2DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector2DivImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_div_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE3::Vector2DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
	}

	float MathF_SSE3::Vector2Magnitude32Impl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_sqrt_ps(_mm_hadd_ps(sqReg, _mm_setzero_ps())).m128_f32[0];
	}

	float MathF_SSE3::Vector2SqMagnitude32Impl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_hadd_ps(sqReg, _mm_setzero_ps()).m128_f32[0];
	}

	double MathF_SSE3::Vector2Magnitude64Impl(double* vec)
	{
		__m128d vecReg = _mm_loadu_pd(vec);
		__m128d sqReg = _mm_mul_pd(vecReg, vecReg);
		return _mm_sqrt_pd(_mm_hadd_pd(sqReg, _mm_setzero_pd())).m128d_f64[0];
	}

	double MathF_SSE3::Vector2SqMagnitude64Impl(double* vec)
	{
		__m128d vecReg = _mm_loadu_pd(vec);
		__m128d sqReg = _mm_mul_pd(vecReg, vecReg);
		return _mm_hadd_pd(sqReg, _mm_setzero_pd()).m128d_f64[0];
	}

	float MathF_SSE3::Vector2Magnitude32Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		return std::sqrt((float)(xSq + ySq));
	}

	float MathF_SSE3::Vector2SqMagnitude32Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		return (float)(xSq + ySq);
	}

	double MathF_SSE3::Vector2Magnitude64Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		return std::sqrt((double)(xSq + ySq));
	}

	double MathF_SSE3::Vector2SqMagnitude64Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		return (double)(xSq + ySq);
	}

	void MathF_SSE3::ResetVector3Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE3::ResetVector3Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
	}

	void MathF_SSE3::ResetVector3Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_SSE3::Vector3AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector3AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
	}

	void MathF_SSE3::Vector3AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE3::Vector3SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector3SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
	}

	void MathF_SSE3::Vector3SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE3::Vector3MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector3MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
	}

	void MathF_SSE3::Vector3MulImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
	}

	void MathF_SSE3::Vector3DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector3DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
	}

	void MathF_SSE3::Vector3DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
	}

	float MathF_SSE3::Vector3Magnitude32Impl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_sqrt_ps(_mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps())).m128_f32[0];
	}

	float MathF_SSE3::Vector3SqMagnitude32Impl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps()).m128_f32[0];
	}

	double MathF_SSE3::Vector3Magnitude64Impl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		return std::sqrt(xSq + ySq + zSq);
	}

	double MathF_SSE3::Vector3SqMagnitude64Impl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		return xSq + ySq + zSq;
	}

	float MathF_SSE3::Vector3Magnitude32Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		return std::sqrt((float)(xSq + ySq + zSq));
	}

	float MathF_SSE3::Vector3SqMagnitude32Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		return (float)(xSq + ySq + zSq);
	}

	double MathF_SSE3::Vector3Magnitude64Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		return std::sqrt((double)(xSq + ySq + zSq));
	}

	double MathF_SSE3::Vector3SqMagnitude64Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		return (double)(xSq + ySq + zSq);
	}

	void MathF_SSE3::ResetVector4Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE3::ResetVector4Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
		vec[3] = 0.0;
	}

	void MathF_SSE3::ResetVector4Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_SSE3::Vector4AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector4AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
		dst[3] = vec1[3] + vec2[3];
	}

	void MathF_SSE3::Vector4AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE3::Vector4SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector4SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
		dst[3] = vec1[3] - vec2[3];
	}

	void MathF_SSE3::Vector4SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE3::Vector4MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector4MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
		dst[3] = vec1[3] * vec2[3];
	}

	void MathF_SSE3::Vector4MulImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
		dst[3] = vec1[3] * vec2[3];
	}

	void MathF_SSE3::Vector4DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE3::Vector4DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
		dst[3] = vec1[3] / vec2[3];
	}

	void MathF_SSE3::Vector4DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
		dst[3] = vec1[3] / vec2[3];
	}

	float MathF_SSE3::Vector4Magnitude32Impl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_sqrt_ps(_mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps())).m128_f32[0];
	}

	float MathF_SSE3::Vector4SqMagnitude32Impl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps()).m128_f32[0];
	}

	double MathF_SSE3::Vector4Magnitude64Impl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double wSq = vec[3] * vec[3];
		return std::sqrt(xSq + ySq + zSq + wSq);
	}

	double MathF_SSE3::Vector4SqMagnitude64Impl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double wSq = vec[3] * vec[3];
		return xSq + ySq + zSq + wSq;
	}

	float MathF_SSE3::Vector4Magnitude32Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		int wSq = vec[3] * vec[3];
		return std::sqrt((float)(xSq + ySq + zSq + wSq));
	}

	float MathF_SSE3::Vector4SqMagnitude32Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		int wSq = vec[3] * vec[3];
		return (float)(xSq + ySq + zSq + wSq);
	}

	double MathF_SSE3::Vector4Magnitude64Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		int wSq = vec[3] * vec[3];
		return std::sqrt((double)(xSq + ySq + zSq + wSq));
	}

	double MathF_SSE3::Vector4SqMagnitude64Impl(int* vec)
	{
		int xSq = vec[0] * vec[0];
		int ySq = vec[1] * vec[1];
		int zSq = vec[2] * vec[2];
		int wSq = vec[3] * vec[3];
		return (double)(xSq + ySq + zSq + wSq);
	}
}