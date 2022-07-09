#include "EmberEnginePCH.h"
#include "MathF.h"
#include "EmberEngine/Core/ProcessorAnalyser.h"
#include "SIMD/MathF_NULL.h"
#include "SIMD/MathF_SSE.h"
#include "SIMD/MathF_SSE2.h"
#include "SIMD/MathF_SSE3.h"
#include "SIMD/MathF_SSSE3.h"
#include "SIMD/MathF_SSE41.h"
#include "SIMD/MathF_SSE42.h"
#include "SIMD/MathF_AVX.h"
#include "SIMD/MathF_AVX2.h"
#include "SIMD/MathF_FMA.h"
#include "SIMD/MathF_AVX512F.h"

namespace EmberEngine
{
	MathF* MathF::Instance = nullptr;

	void MathFInit()
	{
		if (ProcessorAnalyser::AVX512F)
		{
			MathF::Instance = new MathF_AVX512F();
			return;
		}
		if (ProcessorAnalyser::FMA)
		{
			MathF::Instance = new MathF_FMA();
			return;
		}
		if (ProcessorAnalyser::AVX2)
		{
			MathF::Instance = new MathF_AVX2();
			return;
		}
		if (ProcessorAnalyser::AVX)
		{
			MathF::Instance = new MathF_AVX();
			return;
		}
		if (ProcessorAnalyser::SSE42)
		{
			MathF::Instance = new MathF_SSE42();
			return;
		}
		if (ProcessorAnalyser::SSE41)
		{
			MathF::Instance = new MathF_SSE41();
			return;
		}
		if (ProcessorAnalyser::SSSE3)
		{
			MathF::Instance = new MathF_SSSE3();
			return;
		}
		if (ProcessorAnalyser::SSE3)
		{
			MathF::Instance = new MathF_SSE3();
			return;
		}
		if (ProcessorAnalyser::SSE2)
		{
			MathF::Instance = new MathF_SSE2();
			return;
		}
		if (ProcessorAnalyser::SSE)
		{
			MathF::Instance = new MathF_SSE();
			return;
		}

		MathF::Instance = new MathF_NULL();
	}

	float ToRadians(float degrees)
	{
		return (degrees * MATHF_PI) / 180.0f;
	}

	float ToDegrees(float radians)
	{
		return (radians * 180.0f) / MATHF_PI;
	}
}