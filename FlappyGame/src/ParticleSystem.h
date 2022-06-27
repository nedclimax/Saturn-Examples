#pragma once

#include <Saturn.h>

struct ParticleProps
{
	glm::vec2 Position;
	glm::vec2 Velocity, VelocityVariation;
	glm::vec4 ColorBegin, ColorEnd;
	float SizeBegin, SizeEnd, SizeVariation;
	float Rotation = 0.0f;
	float LifeTime = 1.0f;
	Saturn::Ref<Saturn::Texture2D> Texture;
};

class ParticleSystem
{
public:
	ParticleSystem();

	void OnUpdate(Saturn::Timestep ts);
	void OnRender();

	void Emit(const ParticleProps& props);
private:
	struct Particle
	{
		glm::vec2 Position;
		glm::vec2 Velocity;
		glm::vec4 ColorBegin, ColorEnd;
		float Rotation = 0.0f;
		float SizeBegin, SizeEnd;

		Saturn::Ref<Saturn::Texture2D> Texture;

		float Lifetime = 1.0f;
		float LifeRemaining = 0.0f;

		bool Active = false;
	};

	std::vector<Particle> m_ParticlePool;
	uint32_t m_PoolIndex = 999;
};