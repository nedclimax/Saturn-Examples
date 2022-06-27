#include "ParticleSystem.h"

#include "Random.h"

#include <glm/gtc/constants.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/compatibility.hpp>

using namespace Saturn;

ParticleSystem::ParticleSystem()
{
	m_ParticlePool.resize(1000);
}

void ParticleSystem::OnUpdate(Saturn::Timestep ts)
{
	for (auto& particle : m_ParticlePool)
	{
		if (!particle.Active)
			continue;

		if (particle.LifeRemaining <= 0.0f)
		{
			particle.Active = false;
			continue;
		}

		particle.LifeRemaining -= ts;
		particle.Position += particle.Velocity * (float)ts;
		particle.Rotation += 0.01f * ts;
	}
}

void ParticleSystem::OnRender()
{
	for (auto& particle : m_ParticlePool)
	{
		if (!particle.Active)
			continue;

		// Fade away particles
		float life = particle.LifeRemaining / particle.Lifetime;
		glm::vec4 color = glm::lerp(particle.ColorEnd, particle.ColorBegin, life);
		color.a = color.a * life;

		float size = glm::lerp(particle.SizeEnd, particle.SizeBegin, life);
		
		// Draw Particles
		Renderer2D::DrawRotatedQuad(particle.Position, { size, size }, particle.Rotation, color);
	}
}

void ParticleSystem::Emit(const ParticleProps& props)
{
	Particle& particle = m_ParticlePool[m_PoolIndex];
	particle.Active = true;

	particle.Position = props.Position;
	particle.Rotation = props.Rotation * Random::Float() * glm::pi<float>();

	particle.Velocity = props.Velocity;
	particle.Velocity.x += props.VelocityVariation.x * (Random::Float() - 0.5f);
	particle.Velocity.y += props.VelocityVariation.y * (Random::Float() - 0.5f);

	particle.ColorBegin = props.ColorBegin;
	particle.ColorEnd = props.ColorEnd;

	particle.Lifetime = props.LifeTime;
	particle.LifeRemaining = props.LifeTime;

	particle.SizeBegin = props.SizeBegin + props.SizeVariation * (Random::Float() - 0.5f);
	particle.SizeEnd = props.SizeEnd;

	m_PoolIndex = --m_PoolIndex % m_ParticlePool.size();
}