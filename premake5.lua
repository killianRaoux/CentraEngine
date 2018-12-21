workspace "CentraEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "CentraEngine"
		location "CentraEngine"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "ctpch.h"
		pchsource "CentraEngine/src/ctpch.cpp"
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}
		excludes
		{
			"%{prj.name}/src/vendor/glm/**.cpp",
		}
		libdirs
		{
			"dependance/SDL2/lib/x64",
			"dependance/GL/lib/Release/x64"
		}
		includedirs 
		{
			"%{prj.name}/src/vendor",
			"%{prj.name}/src",
			"dependance/spdlog/include",
			"dependance/SDL2/include",
			"dependance/GL/include"
		}

		links 
		{
			"SDL2",
			"SDL2main",
			"glew32",
			"glew32s",
			"glut32"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines
			{
				"CT_BUILD_DLL"
			}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}

		filter "configurations:Debug"
			defines "CT_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "CT_Release"
			symbols "On"

		filter "configurations:Dist"
			defines "CT_DIST"
			symbols "On"


project "Sandbox"
	architecture "x64"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"dependance/spdlog/include",
		"CentraEngine/src",
		"%{prj.name}/src/vendor",
		"dependance/SDL2/include",
		"dependance/GL/include"
	}
	
	libdirs
	{
		"dependance/SDL2/lib/x64",
		"dependance/GL/lib/Release/x64"
	}
	
	links 
	{
		"CentraEngine",
		"SDL2",
		"SDL2main",
		"glew32",
		"glew32s"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "CT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CT_Release"
		symbols "On"

	filter "configurations:Dist"
		defines "CT_DIST"
		symbols "On"