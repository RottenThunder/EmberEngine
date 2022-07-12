#pragma once
#include <stdint.h>

#define EMBER_VERSION_MAJOR 0
#define EMBER_VERSION_MINOR 2
#define EMBER_VERSION_PATCH 1

#if defined EMBER_CONFIG_DEBUG
#define EMBER_ASSERTS_ENABLED
#else
#define EMBER_ASSERTS_DISABLED
#endif

#if defined EMBER_ASSERTS_ENABLED
#define EMBER_ASSERT(x, message) { if(!(x)) { std::cout << "[EMBER] Assertion Failed: " << message << "\n"; __debugbreak(); } }
#define EMBER_REVERSE_ASSERT(x, message) { if(x) { std::cout << "[EMBER] Assertion Failed: " << message << "\n"; __debugbreak(); } }
#else
#define EMBER_ASSERT(x, message) 
#define EMBER_REVERSE_ASSERT(x, message) 
#endif

#define EMBER_BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)
#define EMBER_BIT_FIELD(x) (1 << x)

#define EMBER_CPU_MMX_BIT EMBER_BIT_FIELD(23)
#define EMBER_CPU_SSE_BIT EMBER_BIT_FIELD(25)
#define EMBER_CPU_SSE2_BIT EMBER_BIT_FIELD(26)
#define EMBER_CPU_SSE3_BIT EMBER_BIT_FIELD(0)
#define EMBER_CPU_SSSE3_BIT EMBER_BIT_FIELD(9)
#define EMBER_CPU_SSE41_BIT EMBER_BIT_FIELD(19)
#define EMBER_CPU_SSE42_BIT EMBER_BIT_FIELD(20)
#define EMBER_CPU_AVX_BIT EMBER_BIT_FIELD(28)
#define EMBER_CPU_AVX2_BIT EMBER_BIT_FIELD(5)
#define EMBER_CPU_FMA_BIT EMBER_BIT_FIELD(12)
#define EMBER_CPU_AVX512F_BIT EMBER_BIT_FIELD(16)
#define EMBER_CPU_AVX512PF_BIT EMBER_BIT_FIELD(26)
#define EMBER_CPU_AVX512ER_BIT EMBER_BIT_FIELD(27)
#define EMBER_CPU_AVX512CD_BIT EMBER_BIT_FIELD(28)