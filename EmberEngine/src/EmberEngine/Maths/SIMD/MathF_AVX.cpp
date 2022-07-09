#include "EmberEnginePCH.h"
#include "MathF_AVX.h"

namespace EmberEngine
{
	//Vector2 Implementation

	void MathF_AVX::ResetVector2Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_AVX::ResetVector2Impl(double* vec)
	{
		_mm_storeu_pd(vec, _mm_setzero_pd());
	}

	void MathF_AVX::ResetVector2Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_AVX::Vector2AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector2AddImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_add_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector2AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_AVX::Vector2SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector2SubImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_sub_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector2SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_AVX::Vector2MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector2MulImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_mul_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector2MulImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_AVX::Vector2MulImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_AVX::Vector2MulImpl(double* dst, double* vec, double scalar)
	{
		_mm_storeu_pd(dst, _mm_mul_pd(_mm_loadu_pd(vec), _mm_set1_pd(scalar)));
	}

	void MathF_AVX::Vector2MulImpl(int* dst, int* vec, int scalar)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_set1_epi32(scalar)));
	}

	void MathF_AVX::Vector2DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector2DivImpl(double* dst, double* vec1, double* vec2)
	{
		_mm_storeu_pd(dst, _mm_div_pd(_mm_loadu_pd(vec1), _mm_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector2DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
	}

	void MathF_AVX::Vector2DivImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_AVX::Vector2DivImpl(double* dst, double* vec, double scalar)
	{
		_mm_storeu_pd(dst, _mm_div_pd(_mm_loadu_pd(vec), _mm_set1_pd(scalar)));
	}

	void MathF_AVX::Vector2DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
	}

	float MathF_AVX::Vector2MagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_sqrt_ps(_mm_hadd_ps(sqReg, _mm_setzero_ps())).m128_f32[0];
	}

	float MathF_AVX::Vector2SqMagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_hadd_ps(sqReg, _mm_setzero_ps()).m128_f32[0];
	}

	double MathF_AVX::Vector2MagnitudeImpl(double* vec)
	{
		__m128d vecReg = _mm_loadu_pd(vec);
		__m128d sqReg = _mm_mul_pd(vecReg, vecReg);
		return _mm_sqrt_pd(_mm_hadd_pd(sqReg, _mm_setzero_pd())).m128d_f64[0];
	}

	double MathF_AVX::Vector2SqMagnitudeImpl(double* vec)
	{
		__m128d vecReg = _mm_loadu_pd(vec);
		__m128d sqReg = _mm_mul_pd(vecReg, vecReg);
		return _mm_hadd_pd(sqReg, _mm_setzero_pd()).m128d_f64[0];
	}

	float MathF_AVX::Vector2MagnitudeImpl(int* vec)
	{
		return std::sqrt((float)_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()).m128i_i32[0]);
	}

	float MathF_AVX::Vector2SqMagnitudeImpl(int* vec)
	{
		return (float)_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()).m128i_i32[0];
	}

	void MathF_AVX::Vector2NormaliseImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		_mm_storeu_ps(vec, _mm_div_ps(vecReg, _mm_set1_ps(_mm_sqrt_ps(_mm_hadd_ps(sqReg, _mm_setzero_ps())).m128_f32[0])));
	}

	void MathF_AVX::Vector2NormaliseImpl(double* vec)
	{
		__m128d vecReg = _mm_loadu_pd(vec);
		__m128d sqReg = _mm_mul_pd(vecReg, vecReg);
		_mm_storeu_pd(vec, _mm_div_pd(vecReg, _mm_set1_pd(_mm_sqrt_pd(_mm_hadd_pd(sqReg, _mm_setzero_pd())).m128d_f64[0])));
	}

	//Vector3 Implementation

	void MathF_AVX::ResetVector3Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_AVX::ResetVector3Impl(double* vec)
	{
		_mm256_storeu_pd(vec, _mm256_setzero_pd());
	}

	void MathF_AVX::ResetVector3Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_AVX::Vector3AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector3AddImpl(double* dst, double* vec1, double* vec2)
	{
		_mm256_storeu_pd(dst, _mm256_add_pd(_mm256_loadu_pd(vec1), _mm256_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector3AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_AVX::Vector3SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector3SubImpl(double* dst, double* vec1, double* vec2)
	{
		_mm256_storeu_pd(dst, _mm256_sub_pd(_mm256_loadu_pd(vec1), _mm256_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector3SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_AVX::Vector3MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector3MulImpl(double* dst, double* vec1, double* vec2)
	{
		_mm256_storeu_pd(dst, _mm256_mul_pd(_mm256_loadu_pd(vec1), _mm256_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector3MulImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_AVX::Vector3MulImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_AVX::Vector3MulImpl(double* dst, double* vec, double scalar)
	{
		_mm256_storeu_pd(dst, _mm256_mul_pd(_mm256_loadu_pd(vec), _mm256_set1_pd(scalar)));
	}

	void MathF_AVX::Vector3MulImpl(int* dst, int* vec, int scalar)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_set1_epi32(scalar)));
	}

	void MathF_AVX::Vector3DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector3DivImpl(double* dst, double* vec1, double* vec2)
	{
		_mm256_storeu_pd(dst, _mm256_div_pd(_mm256_loadu_pd(vec1), _mm256_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector3DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
	}

	void MathF_AVX::Vector3DivImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_AVX::Vector3DivImpl(double* dst, double* vec, double scalar)
	{
		_mm256_storeu_pd(dst, _mm256_div_pd(_mm256_loadu_pd(vec), _mm256_set1_pd(scalar)));
	}

	void MathF_AVX::Vector3DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
	}

	float MathF_AVX::Vector3MagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_sqrt_ps(_mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps())).m128_f32[0];
	}

	float MathF_AVX::Vector3SqMagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps()).m128_f32[0];
	}

	double MathF_AVX::Vector3MagnitudeImpl(double* vec)
	{
		__m256d vecReg = _mm256_loadu_pd(vec);
		__m256d sqReg = _mm256_mul_pd(vecReg, vecReg);
		return _mm256_sqrt_pd(_mm256_hadd_pd(_mm256_hadd_pd(sqReg, sqReg), _mm256_setzero_pd())).m256d_f64[0];
	}

	double MathF_AVX::Vector3SqMagnitudeImpl(double* vec)
	{
		__m256d vecReg = _mm256_loadu_pd(vec);
		__m256d sqReg = _mm256_mul_pd(vecReg, vecReg);
		return _mm256_hadd_pd(_mm256_hadd_pd(sqReg, sqReg), _mm256_setzero_pd()).m256d_f64[0];
	}

	float MathF_AVX::Vector3MagnitudeImpl(int* vec)
	{
		return std::sqrt((float)_mm_hadd_epi32(_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()), _mm_setzero_si128()).m128i_i32[0]);
	}

	float MathF_AVX::Vector3SqMagnitudeImpl(int* vec)
	{
		return (float)_mm_hadd_epi32(_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()), _mm_setzero_si128()).m128i_i32[0];
	}

	void MathF_AVX::Vector3NormaliseImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		_mm_storeu_ps(vec, _mm_div_ps(vecReg, _mm_set1_ps(_mm_sqrt_ps(_mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps())).m128_f32[0])));
	}

	void MathF_AVX::Vector3NormaliseImpl(double* vec)
	{
		__m256d vecReg = _mm256_loadu_pd(vec);
		__m256d sqReg = _mm256_mul_pd(vecReg, vecReg);
		_mm256_storeu_pd(vec, _mm256_div_pd(vecReg, _mm256_set1_pd(_mm256_sqrt_pd(_mm256_hadd_pd(_mm256_hadd_pd(sqReg, sqReg), _mm256_setzero_pd())).m256d_f64[0])));
	}

	float MathF_AVX::Vector3DotImpl(float* vec1, float* vec2)
	{
		__m128 reg = _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2));
		return reg.m128_f32[0] + reg.m128_f32[1] + reg.m128_f32[2];
	}

	double MathF_AVX::Vector3DotImpl(double* vec1, double* vec2)
	{
		__m256d reg = _mm256_mul_pd(_mm256_loadu_pd(vec1), _mm256_loadu_pd(vec2));
		return reg.m256d_f64[0] + reg.m256d_f64[1] + reg.m256d_f64[2];
	}

	void MathF_AVX::Vector3CrossImpl(float* dst, float* vec1, float* vec2)
	{
		__m128 reg1 = _mm_loadu_ps(vec1);
		__m128 reg2 = _mm_loadu_ps(vec2);
		__m128 int1 = _mm_mul_ps(reg1, _mm_shuffle_ps(reg2, reg2, 0xC9));
		__m128 int2 = _mm_mul_ps(reg2, _mm_shuffle_ps(reg1, reg1, 0xC9));
		int1 = _mm_sub_ps(int1, int2);
		_mm_storeu_ps(dst, _mm_shuffle_ps(int1, int1, 0xC9));
	}

	void MathF_AVX::Vector3CrossImpl(double* dst, double* vec1, double* vec2)
	{
		dst[0] = vec1[1] * vec2[2] - vec2[1] * vec1[2];
		dst[1] = vec1[2] * vec2[0] - vec2[2] * vec1[0];
		dst[2] = vec1[0] * vec2[1] - vec2[0] * vec1[1];
	}

	//Vector4 Implementation

	void MathF_AVX::ResetVector4Impl(float* vec)
	{
		_mm_storeu_ps(vec, _mm_setzero_ps());
	}

	void MathF_AVX::ResetVector4Impl(double* vec)
	{
		_mm256_storeu_pd(vec, _mm256_setzero_pd());
	}

	void MathF_AVX::ResetVector4Impl(int* vec)
	{
		_mm_storeu_si128((__m128i*)vec, _mm_setzero_si128());
	}

	void MathF_AVX::Vector4AddImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_add_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector4AddImpl(double* dst, double* vec1, double* vec2)
	{
		_mm256_storeu_pd(dst, _mm256_add_pd(_mm256_loadu_pd(vec1), _mm256_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector4AddImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_add_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_AVX::Vector4SubImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_sub_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector4SubImpl(double* dst, double* vec1, double* vec2)
	{
		_mm256_storeu_pd(dst, _mm256_sub_pd(_mm256_loadu_pd(vec1), _mm256_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector4SubImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_sub_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_AVX::Vector4MulImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector4MulImpl(double* dst, double* vec1, double* vec2)
	{
		_mm256_storeu_pd(dst, _mm256_mul_pd(_mm256_loadu_pd(vec1), _mm256_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector4MulImpl(int* dst, int* vec1, int* vec2)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec1), _mm_loadu_si128((__m128i*)vec2)));
	}

	void MathF_AVX::Vector4MulImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_mul_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_AVX::Vector4MulImpl(double* dst, double* vec, double scalar)
	{
		dst[0] = vec[0] * scalar;
		dst[1] = vec[1] * scalar;
		dst[2] = vec[2] * scalar;
		dst[3] = vec[3] * scalar;
		_mm256_storeu_pd(dst, _mm256_mul_pd(_mm256_loadu_pd(vec), _mm256_set1_pd(scalar)));
	}

	void MathF_AVX::Vector4MulImpl(int* dst, int* vec, int scalar)
	{
		_mm_storeu_si128((__m128i*)dst, _mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_set1_epi32(scalar)));
	}

	void MathF_AVX::Vector4DivImpl(float* dst, float* vec1, float* vec2)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec1), _mm_loadu_ps(vec2)));
	}

	void MathF_AVX::Vector4DivImpl(double* dst, double* vec1, double* vec2)
	{
		_mm256_storeu_pd(dst, _mm256_div_pd(_mm256_loadu_pd(vec1), _mm256_loadu_pd(vec2)));
	}

	void MathF_AVX::Vector4DivImpl(int* dst, int* vec1, int* vec2)
	{
		dst[0] = vec1[0] / vec2[0];
		dst[1] = vec1[1] / vec2[1];
		dst[2] = vec1[2] / vec2[2];
		dst[3] = vec1[3] / vec2[3];
	}

	void MathF_AVX::Vector4DivImpl(float* dst, float* vec, float scalar)
	{
		_mm_storeu_ps(dst, _mm_div_ps(_mm_loadu_ps(vec), _mm_set1_ps(scalar)));
	}

	void MathF_AVX::Vector4DivImpl(double* dst, double* vec, double scalar)
	{
		_mm256_storeu_pd(dst, _mm256_div_pd(_mm256_loadu_pd(vec), _mm256_set1_pd(scalar)));
	}

	void MathF_AVX::Vector4DivImpl(int* dst, int* vec, int scalar)
	{
		dst[0] = vec[0] / scalar;
		dst[1] = vec[1] / scalar;
		dst[2] = vec[2] / scalar;
		dst[3] = vec[3] / scalar;
	}

	float MathF_AVX::Vector4MagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_sqrt_ps(_mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps())).m128_f32[0];
	}

	float MathF_AVX::Vector4SqMagnitudeImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		return _mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps()).m128_f32[0];
	}

	double MathF_AVX::Vector4MagnitudeImpl(double* vec)
	{
		__m256d vecReg = _mm256_loadu_pd(vec);
		__m256d sqReg = _mm256_mul_pd(vecReg, vecReg);
		return _mm256_sqrt_pd(_mm256_hadd_pd(_mm256_hadd_pd(sqReg, sqReg), _mm256_setzero_pd())).m256d_f64[0];
	}

	double MathF_AVX::Vector4SqMagnitudeImpl(double* vec)
	{
		__m256d vecReg = _mm256_loadu_pd(vec);
		__m256d sqReg = _mm256_mul_pd(vecReg, vecReg);
		return _mm256_hadd_pd(_mm256_hadd_pd(sqReg, sqReg), _mm256_setzero_pd()).m256d_f64[0];
	}

	float MathF_AVX::Vector4MagnitudeImpl(int* vec)
	{
		return std::sqrt((float)_mm_hadd_epi32(_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()), _mm_setzero_si128()).m128i_i32[0]);
	}

	float MathF_AVX::Vector4SqMagnitudeImpl(int* vec)
	{
		return (float)_mm_hadd_epi32(_mm_hadd_epi32(_mm_mullo_epi32(_mm_loadu_si128((__m128i*)vec), _mm_loadu_si128((__m128i*)vec)), _mm_setzero_si128()), _mm_setzero_si128()).m128i_i32[0];
	}

	void MathF_AVX::Vector4NormaliseImpl(float* vec)
	{
		__m128 vecReg = _mm_loadu_ps(vec);
		__m128 sqReg = _mm_mul_ps(vecReg, vecReg);
		_mm_storeu_ps(vec, _mm_div_ps(vecReg, _mm_set1_ps(_mm_sqrt_ps(_mm_hadd_ps(_mm_hadd_ps(sqReg, sqReg), _mm_setzero_ps())).m128_f32[0])));
	}

	void MathF_AVX::Vector4NormaliseImpl(double* vec)
	{
		__m256d vecReg = _mm256_loadu_pd(vec);
		__m256d sqReg = _mm256_mul_pd(vecReg, vecReg);
		_mm256_storeu_pd(vec, _mm256_div_pd(vecReg, _mm256_set1_pd(_mm256_sqrt_pd(_mm256_hadd_pd(_mm256_hadd_pd(sqReg, sqReg), _mm256_setzero_pd())).m256d_f64[0])));
	}

	//Matrix4x4 Implementation

	void MathF_AVX::ResetMatrix4x4Impl(float* matrix)
	{
		_mm256_storeu_ps(matrix, _mm256_setzero_ps());
		_mm256_storeu_ps(matrix + 8, _mm256_setzero_ps());
	}

	void MathF_AVX::SetToIdentityImpl(float* matrix)
	{
		_mm256_storeu_ps(matrix, _mm256_setzero_ps());
		_mm256_storeu_ps(matrix + 8, _mm256_setzero_ps());
		matrix[0] = 1.0f;
		matrix[5] = 1.0f;
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}

	void MathF_AVX::MultiplyMatrix4x4Impl(float* dst, float* matrix1, float* matrix2)
	{
		float intermediate[64];

		_mm256_storeu_ps(intermediate, _mm256_mul_ps(_mm256_loadu_ps(matrix1), _mm256_set_m128(_mm_set1_ps(matrix2[1]), _mm_set1_ps(matrix2[0]))));
		_mm256_storeu_ps(intermediate + 8, _mm256_mul_ps(_mm256_loadu_ps(matrix1 + 8), _mm256_set_m128(_mm_set1_ps(matrix2[3]), _mm_set1_ps(matrix2[2]))));

		_mm256_storeu_ps(intermediate + 16, _mm256_mul_ps(_mm256_loadu_ps(matrix1), _mm256_set_m128(_mm_set1_ps(matrix2[5]), _mm_set1_ps(matrix2[4]))));
		_mm256_storeu_ps(intermediate + 24, _mm256_mul_ps(_mm256_loadu_ps(matrix1 + 8), _mm256_set_m128(_mm_set1_ps(matrix2[7]), _mm_set1_ps(matrix2[6]))));

		_mm256_storeu_ps(intermediate + 32, _mm256_mul_ps(_mm256_loadu_ps(matrix1), _mm256_set_m128(_mm_set1_ps(matrix2[9]), _mm_set1_ps(matrix2[8]))));
		_mm256_storeu_ps(intermediate + 40, _mm256_mul_ps(_mm256_loadu_ps(matrix1 + 8), _mm256_set_m128(_mm_set1_ps(matrix2[11]), _mm_set1_ps(matrix2[10]))));

		_mm256_storeu_ps(intermediate + 48, _mm256_mul_ps(_mm256_loadu_ps(matrix1), _mm256_set_m128(_mm_set1_ps(matrix2[13]), _mm_set1_ps(matrix2[12]))));
		_mm256_storeu_ps(intermediate + 56, _mm256_mul_ps(_mm256_loadu_ps(matrix1 + 8), _mm256_set_m128(_mm_set1_ps(matrix2[15]), _mm_set1_ps(matrix2[14]))));

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

	void MathF_AVX::SetToTranslationImpl(float* matrix, float* vec2)
	{
		_mm256_storeu_ps(matrix, _mm256_setzero_ps());
		_mm256_storeu_ps(matrix + 8, _mm256_setzero_ps());
		matrix[0] = 1.0f;
		matrix[5] = 1.0f;
		matrix[10] = 1.0f;
		matrix[12] = vec2[0];
		matrix[13] = vec2[1];
		matrix[15] = 1.0f;
	}

	void MathF_AVX::SetToScaleImpl(float* matrix, float* vec2)
	{
		_mm256_storeu_ps(matrix, _mm256_setzero_ps());
		_mm256_storeu_ps(matrix + 8, _mm256_setzero_ps());
		matrix[0] = vec2[0];
		matrix[5] = vec2[1];
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}

	void MathF_AVX::SetToRotationImpl(float* matrix, float radians)
	{
		_mm256_storeu_ps(matrix, _mm256_setzero_ps());
		_mm256_storeu_ps(matrix + 8, _mm256_setzero_ps());
		float sinAngle = std::sin(radians);
		float cosAngle = std::cos(radians);
		matrix[0] = cosAngle;
		matrix[1] = sinAngle;
		matrix[4] = -sinAngle;
		matrix[5] = cosAngle;
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}

	void MathF_AVX::SetToTranslationWithoutResetImpl(float* matrix, float* vec2)
	{
		matrix[0] = 1.0f;
		matrix[5] = 1.0f;
		matrix[10] = 1.0f;
		matrix[12] = vec2[0];
		matrix[13] = vec2[1];
		matrix[15] = 1.0f;
	}

	void MathF_AVX::SetToScaleWithoutResetImpl(float* matrix, float* vec2)
	{
		matrix[0] = vec2[0];
		matrix[5] = vec2[1];
		matrix[10] = 1.0f;
		matrix[15] = 1.0f;
	}

	void MathF_AVX::SetToRotationWithoutResetImpl(float* matrix, float radians)
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