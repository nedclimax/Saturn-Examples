#pragma once

#include <Saturn.h>

#include "Player.h"

struct Pillar
{
	glm::vec3 TopPosition = { 0.0f, 10.0f, 0.0f };
	glm::vec2 TopScale = { 15.0f, 20.0f };

	glm::vec3 BottomPosition = { 10.0f, 10.0f, 0.0f };
	glm::vec2 BottomScale = { 15.0f, 20.0f };
};

class Level
{
public:
	void Init();
	void Reset();

	void OnUpdate(Saturn::Timestep ts);
	void OnRender();
	void OnImGuiRender();

	bool IsGameOver() const { return m_GameOver; }

	Player& GetPlayer() { return m_Player; }
private:
	void CreatePillar(int index, float offset);

	void GameOver();
private:
	Player m_Player;

	bool m_GameOver = false;

	std::vector<Pillar> m_Pillars;
};