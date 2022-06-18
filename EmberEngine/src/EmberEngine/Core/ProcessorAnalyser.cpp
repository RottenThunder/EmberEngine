#include "EmberEnginePCH.h"
#include "ProcessorAnalyser.h"
#include "Base.h"

namespace EmberEngine
{
	bool ProcessorAnalyser::MMX = false;
	bool ProcessorAnalyser::SSE = false;
	bool ProcessorAnalyser::SSE2 = false;
	bool ProcessorAnalyser::SSE3 = false;
	bool ProcessorAnalyser::SSSE3 = false;
	bool ProcessorAnalyser::SSE41 = false;
	bool ProcessorAnalyser::SSE42 = false;
	bool ProcessorAnalyser::AVX = false;
	bool ProcessorAnalyser::AVX2 = false;
	bool ProcessorAnalyser::FMA = false;
	bool ProcessorAnalyser::AVX512F = false;
	bool ProcessorAnalyser::AVX512PF = false;
	bool ProcessorAnalyser::AVX512ER = false;
	bool ProcessorAnalyser::AVX512CD = false;
	bool ProcessorAnalyser::IsIntel = false;
	bool ProcessorAnalyser::IsAMD = false;
	std::string ProcessorAnalyser::Vendor = "";
	std::string ProcessorAnalyser::Brand = "";

	void ProcessorAnalyser::AnalyseF1ECX(int ecx)
	{
		SSE3 = ecx & EMBER_CPU_SSE3_BIT;
		SSSE3 = ecx & EMBER_CPU_SSSE3_BIT;
		SSE41 = ecx & EMBER_CPU_SSE41_BIT;
		SSE42 = ecx & EMBER_CPU_SSE42_BIT;
		AVX = ecx & EMBER_CPU_AVX_BIT;
		FMA = ecx & EMBER_CPU_FMA_BIT;
	}

	void ProcessorAnalyser::AnalyseF1EDX(int edx)
	{
		MMX = edx & EMBER_CPU_MMX_BIT;
		SSE = edx & EMBER_CPU_SSE_BIT;
		SSE2 = edx & EMBER_CPU_SSE2_BIT;
	}

	void ProcessorAnalyser::AnalyseF7EBX(int ebx)
	{
		AVX2 = ebx & EMBER_CPU_AVX2_BIT;
		AVX512F = ebx & EMBER_CPU_AVX512F_BIT;
		AVX512PF = ebx & EMBER_CPU_AVX512PF_BIT;
		AVX512ER = ebx & EMBER_CPU_AVX512ER_BIT;
		AVX512CD = ebx & EMBER_CPU_AVX512CD_BIT;
	}

	void ProcessorAnalyser::AnalyseF7ECX(int ecx)
	{
		//Does Nothing
		//This has more sub-instruction sets of AVX512
	}

	void ProcessorAnalyser::Analyse()
	{
		int cpuInfo[4];
		int hvFuncID;
		int F_1_ECX = 0;
		int F_1_EDX = 0;
		int F_7_EBX = 0;
		int F_7_ECX = 0;

		//Sets the highest valid function ID
		__cpuid(cpuInfo, 0);
		hvFuncID = cpuInfo[0];

		//Capture vendor string
		char vendor[32];
		std::memset(vendor, 0, sizeof(vendor));
		*reinterpret_cast<int*>(vendor) = cpuInfo[1];
		*reinterpret_cast<int*>(vendor + 4) = cpuInfo[3];
		*reinterpret_cast<int*>(vendor + 8) = cpuInfo[2];
		Vendor = vendor;
		if (Vendor == "GenuineIntel")
		{
			IsIntel = true;
		}
		else if (Vendor == "AuthenticAMD")
		{
			IsAMD = true;
		}

		//Capture brand string
		char brand[64];
		std::memset(brand, 0, sizeof(brand));
		__cpuid(cpuInfo, 0x80000000);

		if (cpuInfo[0] >= 0x80000004)
		{
			__cpuidex(cpuInfo, 0x80000002, 0);
			std::memcpy(brand, cpuInfo, sizeof(cpuInfo));
			__cpuidex(cpuInfo, 0x80000003, 0);
			std::memcpy(brand + 16, cpuInfo, sizeof(cpuInfo));
			__cpuidex(cpuInfo, 0x80000004, 0);
			std::memcpy(brand + 32, cpuInfo, sizeof(cpuInfo));
			Brand = brand;
		}

		//Analysing CPU Bits
		if (hvFuncID >= 1)
		{
			__cpuidex(cpuInfo, 1, 0);
			F_1_ECX = cpuInfo[2];
			F_1_EDX = cpuInfo[3];
		}
		if (hvFuncID >= 7)
		{
			__cpuidex(cpuInfo, 7, 0);
			F_7_EBX = cpuInfo[1];
			F_7_ECX = cpuInfo[2];
		}
		if (F_1_ECX != 0)
		{
			AnalyseF1ECX(F_1_ECX);
		}
		if (F_1_EDX != 0)
		{
			AnalyseF1EDX(F_1_EDX);
		}
		if (F_7_EBX != 0)
		{
			AnalyseF7EBX(F_7_EBX);
		}
		if (F_7_ECX != 0)
		{
			AnalyseF7ECX(F_7_ECX);
		}
	}
}