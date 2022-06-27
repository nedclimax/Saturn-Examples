#include "Player.h"

#include <imgui/imgui.h>

using namespace Saturn;

Player::Player()
{

}

void Player::LoadAssets()
{
	m_Texture = Texture2D::Create("assets/textures/rocket.png");
}

void Player::OnUpdate(Timestep ts)
{
	if (Input::IsKeyPressed(KEY_SPACE))
	{
		m_Velocity.y += m_EnginePower;
		if (m_Velocity.y < 0.0f)
			m_Velocity.y += m_EnginePower * 2.0f;
	}
	else
	{
		m_Velocity.y -= m_Gravity;
	}

	m_Velocity.y = glm::clamp(m_Velocity.y, -20.0f, 20.0f);
}

void Player::OnRender()
{
	Renderer2D::DrawRotatedQuad(m_Position, { 1.1f, 1.7f }, GetRotation(), m_Texture);
}

void Player::OnImGuiRender()
{
	ImGui::DragFloat("Engine Power", &m_EnginePower, 0.1f);
	ImGui::DragFloat("Gravity", &m_Gravity, 0.1f);
	if (ImGui::Button("Reset settings"))
	{
		Reset();
	}
}

void Player::Reset()
{
	m_EnginePower = 0.5f;
	m_Gravity = 0.4f;
}