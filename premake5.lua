-- Solution CallowEngine
workspace "CallowEngine" 
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

-- variable    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Project CallowEngine
project "CallowEngine"
    location "CallowEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

filter "system:windows"
    cppdialect "Default"
    staticruntime "On"
    systemversion "latest"

    defines
    {
        "CW_PLATFORM_WINDOWS",
        "CW_BUILD_DLL"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

filter "configurations:Debug"
    defines "CW_DEBUG"
    symbols "On"

filter "configurations:Release"
    defines "CW_RELEASE"
    optimize "On"

filter "configurations:Dist"
    defines "CW_DIST"
    optimize "On"

-- Project Sandbox
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "CallowEngine/vendor/spdlog/include",
        "CallowEngine"
    }
    
    links
    {
        "CallowEngine"
    }

filter "system:windows"
    cppdialect "Default"
    staticruntime "On"
    systemversion "latest"

    defines
    {
        "CW_PLATFORM_WINDOWS"
    }

filter "configurations:Debug"
    defines "CW_DEBUG"
    symbols "On"

filter "configurations:Release"
    defines "CW_RELEASE"
    optimize "On"

filter "configurations:Dist"
    defines "CW_DIST"
    optimize "On"