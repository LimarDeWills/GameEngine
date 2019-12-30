workspace "Engine"
	architecture "x64"

	configurations{
		
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildCfg}-%{cfg.system}-%{cfg.architecture}"


project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .."/%{prg.name}")
	objdir ("bin-int/" .. outputdir .."/%{prg.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	include
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system.Windows"
	
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EG_PLATFORM_WINDOWS",
			"EG_BUILD_DLL"		
		}

	postbuildcommand 
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configuration:Debug"
		defines "EG_DEBUG"
		symbols "On"

		filter "configuration:Release"
		defines "EG_DEBUG"
		optimize "On"

		filter "configuration:Dist"
		defines "EG_DEBUG"
		optimize "On"