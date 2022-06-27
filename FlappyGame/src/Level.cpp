#include "Level.h"

#include "Random.h"

using namespace Saturn;

void Level::Init()
{
	m_Player.LoadAssets();
}

void Level::Reset()
{
	m_GameOver = false;

	m_Player.Reset();
}

void Level::OnUpdate(Timestep ts)
{
	m_Player.OnUpdate(ts);
}

void Level::OnRender()
{
	m_Player.OnRender();
}

void Level::OnImGuiRender()
{
	m_Player.OnImGuiRender();
}

void Level::CreatePillar(int index, float offset)
{
	Pillar& pillar = m_Pillars[index];
	pillar.TopPosition.x = offset;
	pillar.BottomPosition.x = offset;
	pillar.TopPosition.z = index * 0.1f - 0.5f;
	pillar.BottomPosition.z = index * 0.1f - 0.5f + 0.05f;

	float center = Random::Float() * 35.0f - 17.5f;
	float gap = 2.0f + Random::Float() * 5.0f;

	pillar.TopPosition.y = 10.0f - ((10.0f - center) * 0.2f) + gap * 0.5f;
	pillar.BottomPosition.y = -10.0f - ((-10.0f - center) * 0.2f) - gap * 0.5f;
}

void Level::GameOver()
{
	m_GameOver = true;
}