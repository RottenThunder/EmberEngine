#pragma once

namespace EmberEngine
{
	class ProcessorAnalyser
	{
	private:
		static void AnalyseF1ECX(int ecx);
		static void AnalyseF1EDX(int edx);
		static void AnalyseF7EBX(int ebx);
		static void AnalyseF7ECX(int ecx);
	public:
		static bool MMX;
		static bool SSE;
		static bool SSE2;
		static bool SSE3;
		static bool SSSE3;
		static bool SSE41;
		static bool SSE42;
		static bool AVX;
		static bool AVX2;
		static bool FMA;
		static bool AVX512F;
		static bool AVX512PF;
		static bool AVX512ER;
		static bool AVX512CD;
		static bool IsIntel;
		static bool IsAMD;
		static std::string Vendor;
		static std::string Brand;
		static void Analyse();
	};
}