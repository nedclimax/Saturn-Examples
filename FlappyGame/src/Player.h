#pragma once

#include <Saturn.h>

class Player
{
public:
	Player();

	void LoadAssets();

	void OnUpdate(Saturn::Timestep ts);
	void OnRender();
	void OnImGuiRender();

	void Reset();

	float GetRotation() { return m_Velocity.y * 4.0f - 90.0f; }
	const glm::vec2& GetPosition() const { return m_Position; }
private:
	glm::vec2 m_Position = { 0.0f, 0.0f };
	glm::vec2 m_Velocity = { 5.0f, 0.0f };

	float m_EnginePower = 0.5f;
	float m_Gravity = 0.4f;

	Saturn::Ref<Saturn::Texture2D> m_Texture;
};