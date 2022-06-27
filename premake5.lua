include "./Saturn/vendor/premake/premake_customization/solution_items.lua"
include "./Saturn/vendor/premake/premake_customization/actions.lua"

workspace "TestGame"
	architecture "x86_64"
	startproject "ParticleDemo"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	solution_items {
		".editorconfig"
	}

	flags {
		"MultiProcessorCompile"
	}

include "Saturn/external.lua"
include "FlappyGame"
include "ParticleDemo"
