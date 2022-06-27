#include <Saturn.h>
#include <Saturn/Core/EntryPoint.h>

#include "SandboxLayer.h"

class ParticleDemo : public Saturn::Application
{
public:
	ParticleDemo()
	{
		PushLayer(new SandboxLayer());
	}
};

Saturn::Application* Saturn::CreateApplication()
{
	return new ParticleDemo();
}