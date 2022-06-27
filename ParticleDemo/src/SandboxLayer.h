#pragma once

#include <Saturn.h>

#include "ParticleSystem.h"

class SandboxLayer : public Saturn::Layer
{
public:
	SandboxLayer();
	virtual ~SandboxLayer() = default;

	void OnAttach() override;
	void OnDetach() override;
	void OnImGuiRender() override;
	void OnUpdate(Saturn::Timestep ts) override;
	void OnEvent(Saturn::Event& e) override;
private:
	Saturn::OrthoCameraController m_OrthoCamera;

	Saturn::Ref<Saturn::Texture2D> m_Background;

	ParticleSystem m_ParticleSystem;
	ParticleProps m_Particle;
};