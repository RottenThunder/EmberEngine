#pragma once

#define EMBER_VERSION_MAJOR 0
#define EMBER_VERSION_MINOR 0
#define EMBER_VERSION_PATCH 0

#if defined EMBER_CONFIG_DEBUG
#define EMBER_ASSERTS_ENABLED
#else
#define EMBER_ASSERTS_DISABLED
#endif

#if defined EMBER_ASSERTS_ENABLED
#define EMBER_ASSERT(x, message) { if(!(x)) { std::cout << "Assertion Failed: " << message << "\n"; __debugbreak(); } }
#define EMBER_REVERSE_ASSERT(x, message) { if(x) { std::cout << "Assertion Failed: " << message << "\n"; __debugbreak(); } }
#else
#define EMBER_ASSERT(x, message) 
#define EMBER_REVERSE_ASSERT(x, message) 
#endif