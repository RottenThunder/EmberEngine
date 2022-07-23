workspace "EmberEngine"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

project "EmberEngine"
	location "EmberEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "On"

	targetdir ("Bin/%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}/%{prj.name}")
	objdir ("Bin-Int/%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}/%{prj.name}")

	pchheader "EmberEnginePCH.h"
	pchsource "EmberEngine/src/EmberEnginePCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glad_/**.h",
		"%{prj.name}/vendor/glad_/**.cpp",
		"%{prj.name}/vendor/stb/**.h",
		"%{prj.name}/vendor/stb/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"Dependencies/GLFW/include",
		"%{prj.name}/vendor/glad_/include",
		"%{prj.name}/vendor/stb"
	}

	links
	{
		"Dependencies/GLFW/lib/glfw3_mt.lib",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"EMBER_PLATFORM_WINDOWS"
		}

	filter "system:linux"
		pic "On"
		systemversion "latest"

		defines
		{
			"EMBER_PLATFORM_LINUX"
		}

	filter "configurations:Debug"
		defines "EMBER_CONFIG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "EMBER_CONFIG_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Distribution"
		defines "EMBER_CONFIG_DISTRIBUTION"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "On"

	targetdir ("Bin/%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}/%{prj.name}")
	objdir ("Bin-Int/%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"EmberEngine/src",
		"Dependencies/GLFW/include"
	}

	links
	{
		"EmberEngine"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"EMBER_PLATFORM_WINDOWS"
		}

	filter "system:linux"
		pic "On"
		systemversion "latest"

		defines
		{
			"EMBER_PLATFORM_LINUX"
		}

	filter "configurations:Debug"
		defines "EMBER_CONFIG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "EMBER_CONFIG_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Distribution"
		defines "EMBER_CONFIG_DISTRIBUTION"
		runtime "Release"
		optimize "On"
