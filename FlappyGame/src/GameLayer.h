#pragma once

#include <Saturn.h>

#include "Level.h"

class GameLayer : public Saturn::Layer
{
public:
	GameLayer();
	virtual ~GameLayer() = default;

	void OnAttach() override;
	void OnDetach() override;
	void OnUpdate(Saturn::Timestep ts) override;
	void OnImGuiRender() override;
	void OnEvent(Saturn::Event& e) override;

	bool OnMouseButtonPressed(Saturn::MouseButtonPressedEvent& e);
	bool OnWindowResize(Saturn::WindowResizeEvent& e);
private:
	void CreateCamera(uint32_t width, uint32_t height);
private:
	Saturn::Scope<Saturn::OrthoCamera> m_Camera;

	Level m_Level;

	enum class GameState
	{
		Play = 0, MainMenu = 1, GameOver = 2
	};

	GameState m_State = GameState::MainMenu;
};