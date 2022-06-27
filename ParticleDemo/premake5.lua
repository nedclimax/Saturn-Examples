project "ParticleDemo"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.h",
        "src/**.hpp",
        "src/**.c",
        "src/**.cpp",
    }

    includedirs {
        "../Saturn/Saturn/vendor/glm",
	"../Saturn/Saturn/vendor/spdlog/include",
        "../Saturn/Saturn/vendor",
        "../Saturn/Saturn/src"
    }

    links {
        "Saturn"
    }

    defines {
        "_CRT_SECURE_NO_WARNINGS"
    }

    systemversion "latest"

    filter "configurations:Debug"
        defines "ST_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ST_RELEASE"
        runtime "Release"
        optimize "on"
        symbols "on"

    filter "configurations:Dist"
        kind "WindowedApp"
        defines "ST_DIST"
        runtime "Release"
        optimize "on"
        symbols "off"
