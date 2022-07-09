#include "EmberEnginePCH.h"
#include "MathF_SSE42.h"

namespace EmberEngine
{
	//Vector2 Implementation

	void MathF_SSE42::ResetVector2Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE42::ResetVector2Impl(double* vec)
	{
		_mm_storeu_pd(vec, _mm_setzero_pd());
	}

	void MathF_SSE42::ResetVector2Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_SSE42::Vector2AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector2AddImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_add_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE42::Vector2AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE42::Vector2SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector2SubImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_sub_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE42::Vector2SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE42::Vector2MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector2MulImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_mul_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE42::Vector2MulImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE42::Vector2MulImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE42::Vector2MulImpl(double* dst, double* vec, double scalar)
	{
		_mm_storeu_pd(dst, _mm_mul_pd(_mm_loadu_pd(vec), _mm_set1_pd(scalar)));
	}

	void MathF_SSE42::Vector2MulImpl(int* dst, int* vec, int scalar)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_set1_epi32(scalar)));
	}

	void MathF_SSE42::Vector2DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector2DivImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_div_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_SSE42::Vector2DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
	}

	void MathF_SSE42::Vector2DivImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE42::Vector2DivImpl(double* dst, double* vec, double scalar)
	{
		_mm_storeu_pd(dst, _mm_div_pd(_mm_loadu_pd(vec), _mm_set1_pd(scalar)));
	}

	void MathF_SSE42::Vector2DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
	}

	float MathF_SSE42::Vector2MagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_sqrt_ps(_mm_hadd_ps(sqReg, _mm_setzero_ps())).m128_f32[0];
	}

	float MathF_SSE42::Vector2SqMagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_hadd_ps(sqReg, _mm_setzero_ps()).m128_f32[0];
	}

	double MathF_SSE42::Vector2MagnitudeImpl(double* vec)
	{
		__m128d vecReg = _mm_loadu_pd(vec);
		__m128d sqReg = _mm_mul_pd(vecReg, vecReg);
		return _mm_sqrt_pd(_mm_hadd_pd(sqReg, _mm_setzero_pd())).m128d_f64[0];
	}

	double MathF_SSE42::Vector2SqMagnitudeImpl(double* vec)
	{
		__m128d vecReg = _mm_loadu_pd(vec);
		__m128d sqReg = _mm_mul_pd(vecReg, vecReg);
		return _mm_hadd_pd(sqReg, _mm_setzero_pd()).m128d_f64[0];
	}

	float MathF_SSE42::Vector2MagnitudeImpl(int* vec)
	{
		return std::sqrt((float)_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()).m128i_i32[0]);
	}

	float MathF_SSE42::Vector2SqMagnitudeImpl(int* vec)
	{
		return (float)_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()).m128i_i32[0];
	}

	void MathF_SSE42::Vector2NormaliseImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		_mm_storeu_ps(vec, _mm_div_ps(vecReg, _mm_set1_ps(_mm_sqrt_ps(_mm_hadd_ps(sqReg, _mm_setzero_ps())).m128_f32[0])));
	}

	void MathF_SSE42::Vector2NormaliseImpl(double* vec)
	{
		__m128d vecReg = _mm_loadu_pd(vec);
		__m128d sqReg = _mm_mul_pd(vecReg, vecReg);
		_mm_storeu_pd(vec, _mm_div_pd(vecReg, _mm_set1_pd(_mm_sqrt_pd(_mm_hadd_pd(sqReg, _mm_setzero_pd())).m128d_f64[0])));
	}

	//Vector3 Implementation

	void MathF_SSE42::ResetVector3Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE42::ResetVector3Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
	}

	void MathF_SSE42::ResetVector3Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_SSE42::Vector3AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector3AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
	}

	void MathF_SSE42::Vector3AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE42::Vector3SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector3SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
	}

	void MathF_SSE42::Vector3SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE42::Vector3MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector3MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
	}

	void MathF_SSE42::Vector3MulImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE42::Vector3MulImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE42::Vector3MulImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
	}

	void MathF_SSE42::Vector3MulImpl(int* dst, int* vec, int scalar)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_set1_epi32(scalar)));
	}

	void MathF_SSE42::Vector3DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector3DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
	}

	void MathF_SSE42::Vector3DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
	}

	void MathF_SSE42::Vector3DivImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE42::Vector3DivImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
	}

	void MathF_SSE42::Vector3DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
	}

	float MathF_SSE42::Vector3MagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_sqrt_ps(_mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps())).m128_f32[0];
	}

	float MathF_SSE42::Vector3SqMagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps()).m128_f32[0];
	}

	double MathF_SSE42::Vector3MagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		return std::sqrt(xSq + ySq + zSq);
	}

	double MathF_SSE42::Vector3SqMagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		return xSq + ySq + zSq;
	}

	float MathF_SSE42::Vector3MagnitudeImpl(int* vec)
	{
		return std::sqrt((float)_mm_hadd_epi32(_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()), _mm_setzero_si128()).m128i_i32[0]);
	}

	float MathF_SSE42::Vector3SqMagnitudeImpl(int* vec)
	{
		return (float)_mm_hadd_epi32(_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()), _mm_setzero_si128()).m128i_i32[0];
	}

	void MathF_SSE42::Vector3NormaliseImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		_mm_storeu_ps(vec, _mm_div_ps(vecReg, _mm_set1_ps(_mm_sqrt_ps(_mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps())).m128_f32[0])));
	}

	void MathF_SSE42::Vector3NormaliseImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double length = std::sqrt(xSq + ySq + zSq);
		vec[0] /= length;
		vec[1] /= length;
		vec[2] /= length;
	}

	float MathF_SSE42::Vector3DotImpl(float* vec1, float* vec2)
	{
		__m128 reg = _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2));
		return reg.m128_f32[0] + reg.m128_f32[1] + reg.m128_f32[2];
	}

	double MathF_SSE42::Vector3DotImpl(double* vec1, double* vec2)
	{
		double xSq = vec1[0] * vec2[0];
		double ySq = vec1[1] * vec2[1];
		double zSq = vec1[2] * vec2[2];
		return xSq + ySq + zSq;
	}

	void MathF_SSE42::Vector3CrossImpl(float* dst, float* vec1, float* vec2)
	{
		__m128 reg1 = _mm_loadu_ps(vec1);
		__m128 reg2 = _mm_loadu_ps(vec2);
		__m128 int1 = _mm_mul_ps(reg1, _mm_shuffle_ps(reg2, reg2, 0xC9));
		__m128 int2 = _mm_mul_ps(reg2, _mm_shuffle_ps(reg1, reg1, 0xC9));
		int1 = _mm_sub_ps(int1, int2);
		_mm_storeu_ps(dst, _mm_shuffle_ps(int1, int1, 0xC9));
	}

	void MathF_SSE42::Vector3CrossImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[1] * vec2[2] - vec2[1] * vec1[2];
		dst[1] = vec1[2] * vec2[0] - vec2[2] * vec1[0];
		dst[2] = vec1[0] * vec2[1] - vec2[0] * vec1[1];
	}

	//Vector4 Implementation

	void MathF_SSE42::ResetVector4Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_SSE42::ResetVector4Impl(double* vec)
	{
		vec[0] = 0.0;
		vec[1] = 0.0;
		vec[2] = 0.0;
		vec[3] = 0.0;
	}

	void MathF_SSE42::ResetVector4Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_SSE42::Vector4AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector4AddImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
		dst[3] = vec1[3] + vec2[3];
	}

	void MathF_SSE42::Vector4AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE42::Vector4SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector4SubImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
		dst[3] = vec1[3] - vec2[3];
	}

	void MathF_SSE42::Vector4SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE42::Vector4MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector4MulImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] * vec2[0];
		dst[1] = vec1[1] * vec2[1];
		dst[2] = vec1[2] * vec2[2];
		dst[3] = vec1[3] * vec2[3];
	}

	void MathF_SSE42::Vector4MulImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_SSE42::Vector4MulImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE42::Vector4MulImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
		dst[3] = vec[3] * scalar;
	}

	void MathF_SSE42::Vector4MulImpl(int* dst, int* vec, int scalar)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_set1_epi32(scalar)));
	}

	void MathF_SSE42::Vector4DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_SSE42::Vector4DivImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
		dst[3] = vec1[3] / vec2[3];
	}

	void MathF_SSE42::Vector4DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
		dst[3] = vec1[3] / vec2[3];
	}

	void MathF_SSE42::Vector4DivImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_SSE42::Vector4DivImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
		dst[3] = vec[3] / scalar;
	}

	void MathF_SSE42::Vector4DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
		dst[3] = vec[3] / scalar;
	}

	float MathF_SSE42::Vector4MagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_sqrt_ps(_mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps())).m128_f32[0];
	}

	float MathF_SSE42::Vector4SqMagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps()).m128_f32[0];
	}

	double MathF_SSE42::Vector4MagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double wSq = vec[3] * vec[3];
		return std::sqrt(xSq + ySq + zSq + wSq);
	}

	double MathF_SSE42::Vector4SqMagnitudeImpl(double* vec)
	{
		double xSq = vec[0] * vec[0];
		double ySq = vec[1] * vec[1];
		double zSq = vec[2] * vec[2];
		double wSq = vec[3] * vec[3];
		return xSq + ySq + zSq + wSq;
	}

	float MathF_SSE42::Vector4MagnitudeImpl(int* vec)
	{
		return std::sqrt((float)_mm_hadd_epi32(_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()), _mm_setzero_si128()).m128i_i32[0]);
	}

	float MathF_SSE42::Vector4SqMagnitudeImpl(int* vec)
	{
		return (float)_mm_hadd_epi32(_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()), _mm_setzero_si128()).m128i_i32[0];
	}

	void MathF_SSE42::Vector4NormaliseImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		_mm_storeu_ps(vec, _mm_div_ps(vecReg, _mm_set1_ps(_mm_sqrt_ps(_mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps())).m128_f32[0])));
	}

	void MathF_SSE42::Vector4NormaliseImpl(double* vec)
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

	//Matrix4x4 Implementation

	void MathF_SSE42::ResetMatrix4x4Impl(float* matrix)
	{
		_mm_storeu_ps(matrix, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 4, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 8, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 12, _mm_setzero_ps());
	}

	void MathF_SSE42::SetToIdentityImpl(float* matrix)
	{
		_mm_storeu_ps(matrix, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 4, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 8, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 12, _mm_setzero_ps());
		matrix[0] = 1.0f;
		matrix[5] = 1.0f;
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}

	void MathF_SSE42::MultiplyMatrix4x4Impl(float* dst, float* matrix1, float* matrix2)
	{
		float intermediate[64];

		_mm_storeu_ps(intermediate, _mm_mul_ps(_mm_loadu_ps(matrix1), _mm_set1_ps(matrix2[0])));
		_mm_storeu_ps(intermediate + 4, _mm_mul_ps(_mm_loadu_ps(matrix1 + 4), _mm_set1_ps(matrix2[1])));
		_mm_storeu_ps(intermediate + 8, _mm_mul_ps(_mm_loadu_ps(matrix1 + 8), _mm_set1_ps(matrix2[2])));
		_mm_storeu_ps(intermediate + 12, _mm_mul_ps(_mm_loadu_ps(matrix1 + 12), _mm_set1_ps(matrix2[3])));

		_mm_storeu_ps(intermediate + 16, _mm_mul_ps(_mm_loadu_ps(matrix1), _mm_set1_ps(matrix2[4])));
		_mm_storeu_ps(intermediate + 20, _mm_mul_ps(_mm_loadu_ps(matrix1 + 4), _mm_set1_ps(matrix2[5])));
		_mm_storeu_ps(intermediate + 24, _mm_mul_ps(_mm_loadu_ps(matrix1 + 8), _mm_set1_ps(matrix2[6])));
		_mm_storeu_ps(intermediate + 28, _mm_mul_ps(_mm_loadu_ps(matrix1 + 12), _mm_set1_ps(matrix2[7])));

		_mm_storeu_ps(intermediate + 32, _mm_mul_ps(_mm_loadu_ps(matrix1), _mm_set1_ps(matrix2[8])));
		_mm_storeu_ps(intermediate + 36, _mm_mul_ps(_mm_loadu_ps(matrix1 + 4), _mm_set1_ps(matrix2[9])));
		_mm_storeu_ps(intermediate + 40, _mm_mul_ps(_mm_loadu_ps(matrix1 + 8), _mm_set1_ps(matrix2[10])));
		_mm_storeu_ps(intermediate + 44, _mm_mul_ps(_mm_loadu_ps(matrix1 + 12), _mm_set1_ps(matrix2[11])));

		_mm_storeu_ps(intermediate + 48, _mm_mul_ps(_mm_loadu_ps(matrix1), _mm_set1_ps(matrix2[12])));
		_mm_storeu_ps(intermediate + 52, _mm_mul_ps(_mm_loadu_ps(matrix1 + 4), _mm_set1_ps(matrix2[13])));
		_mm_storeu_ps(intermediate + 56, _mm_mul_ps(_mm_loadu_ps(matrix1 + 8), _mm_set1_ps(matrix2[14])));
		_mm_storeu_ps(intermediate + 60, _mm_mul_ps(_mm_loadu_ps(matrix1 + 12), _mm_set1_ps(matrix2[15])));

		_mm_storeu_ps(intermediate, _mm_add_ps(_mm_loadu_ps(intermediate), _mm_loadu_ps(intermediate + 4)));
		_mm_storeu_ps(intermediate + 8, _mm_add_ps(_mm_loadu_ps(intermediate + 8), _mm_loadu_ps(intermediate + 12)));
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(intermediate), _mm_loadu_ps(intermediate + 8)));

		_mm_storeu_ps(intermediate + 16, _mm_add_ps(_mm_loadu_ps(intermediate + 16), _mm_loadu_ps(intermediate + 20)));
		_mm_storeu_ps(intermediate + 24, _mm_add_ps(_mm_loadu_ps(intermediate + 24), _mm_loadu_ps(intermediate + 28)));
		_mm_storeu_ps(dst + 4, _mm_add_ps(_mm_loadu_ps(intermediate + 16), _mm_loadu_ps(intermediate + 24)));

		_mm_storeu_ps(intermediate + 32, _mm_add_ps(_mm_loadu_ps(intermediate + 32), _mm_loadu_ps(intermediate + 36)));
		_mm_storeu_ps(intermediate + 40, _mm_add_ps(_mm_loadu_ps(intermediate + 40), _mm_loadu_ps(intermediate + 44)));
		_mm_storeu_ps(dst + 8, _mm_add_ps(_mm_loadu_ps(intermediate + 32), _mm_loadu_ps(intermediate + 40)));

		_mm_storeu_ps(intermediate + 48, _mm_add_ps(_mm_loadu_ps(intermediate + 48), _mm_loadu_ps(intermediate + 52)));
		_mm_storeu_ps(intermediate + 56, _mm_add_ps(_mm_loadu_ps(intermediate + 56), _mm_loadu_ps(intermediate + 60)));
		_mm_storeu_ps(dst + 12, _mm_add_ps(_mm_loadu_ps(intermediate + 48), _mm_loadu_ps(intermediate + 56)));
	}

	void MathF_SSE42::SetToTranslationImpl(float* matrix, float* vec2)
	{
		_mm_storeu_ps(matrix, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 4, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 8, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 12, _mm_setzero_ps());
		matrix[0] = 1.0f;
		matrix[5] = 1.0f;
		matrix[10] = 1.0f;
		matrix[12] = vec2[0];
		matrix[13] = vec2[1];
		matrix[15] = 1.0f;
	}

	void MathF_SSE42::SetToScaleImpl(float* matrix, float* vec2)
	{
		_mm_storeu_ps(matrix, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 4, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 8, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 12, _mm_setzero_ps());
		matrix[0] = vec2[0];
		matrix[5] = vec2[1];
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}

	void MathF_SSE42::SetToRotationImpl(float* matrix, float radians)
	{
		_mm_storeu_ps(matrix, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 4, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 8, _mm_setzero_ps());
		_mm_storeu_ps(matrix + 12, _mm_setzero_ps());
		float sinAngle = std::sin(radians);
		float cosAngle = std::cos(radians);
		matrix[0] = cosAngle;
		matrix[1] = sinAngle;
		matrix[4] = -sinAngle;
		matrix[5] = cosAngle;
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}

	void MathF_SSE42::SetToTranslationWithoutResetImpl(float* matrix, float* vec2)
	{
		matrix[0] = 1.0f;
		matrix[5] = 1.0f;
		matrix[10] = 1.0f;
		matrix[12] = vec2[0];
		matrix[13] = vec2[1];
		matrix[15] = 1.0f;
	}

	void MathF_SSE42::SetToScaleWithoutResetImpl(float* matrix, float* vec2)
	{
		matrix[0] = vec2[0];
		matrix[5] = vec2[1];
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}

	void MathF_SSE42::SetToRotationWithoutResetImpl(float* matrix, float radians)
	{
		float sinAngle = std::sin(radians);
		float cosAngle = std::cos(radians);
		matrix[0] = cosAngle;
		matrix[1] = sinAngle;
		matrix[4] = -sinAngle;
		matrix[5] = cosAngle;
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}
}