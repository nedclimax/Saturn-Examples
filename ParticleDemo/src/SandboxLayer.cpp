#include "SandboxLayer.h"

#include "Random.h"

#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>

using namespace Saturn;

SandboxLayer::SandboxLayer()
	: Layer("SandboxLayer"), m_OrthoCamera(16.0f / 9.0f)
{
    Random::Init();
}

void SandboxLayer::OnAttach()
{
    m_Background = Texture2D::Create("assets/textures/prototype/Light/texture_07.png");

    m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
    m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
    m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
    m_Particle.LifeTime = 1.0f;
    m_Particle.Rotation = 5.0f;
    m_Particle.Velocity = { 0.0f, 0.0f };
    m_Particle.VelocityVariation = { 3.0f, 1.0f };
    m_Particle.Position = { 0.0f, 0.0f };
}

void SandboxLayer::OnDetach()
{

}

void SandboxLayer::OnUpdate(Saturn::Timestep ts)
{
    m_OrthoCamera.OnUpdate(ts);

    if (Input::IsKeyPressed(KEY_SPACE))
    {
        auto mousePos = Input::GetMousePosition();
        auto width = Application::Get().GetWindow().GetWidth();
        auto height = Application::Get().GetWindow().GetHeight();
        auto bounds = m_OrthoCamera.GetBounds();
        auto pos = m_OrthoCamera.GetCamera().GetPosition();

        mousePos.x = (mousePos.x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
        mousePos.y = bounds.GetHeight() * 0.5f - (mousePos.y / height) * bounds.GetHeight();

        m_Particle.Position = { mousePos.x + pos.x, mousePos.y + pos.y };
        for (int i = 0; i < 5; i++)
            m_ParticleSystem.Emit(m_Particle);
    }

    m_ParticleSystem.OnUpdate(ts);

    RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
    RenderCommand::Clear();
    
    auto pos = m_OrthoCamera.GetCamera().GetPosition();

    Renderer2D::BeginScene(m_OrthoCamera.GetCamera());
    Renderer2D::DrawQuad({ pos.x, pos.y, -0.1f }, { 100.0f, 100.0f }, m_Background, glm::vec4(1.0f), 10.0f);
    m_ParticleSystem.OnRender();
    Renderer2D::EndScene();
}

void SandboxLayer::OnImGuiRender()
{
    ImGui::Begin("Settings");
    ImGui::Text("Press [SPACE] to generate particles");
    ImGui::NewLine();
    ImGui::ColorEdit4("Birth Color", glm::value_ptr(m_Particle.ColorBegin));
    ImGui::ColorEdit4("Death Color", glm::value_ptr(m_Particle.ColorEnd));
    ImGui::NewLine();
    ImGui::DragFloat("Birth Size", &m_Particle.SizeBegin, 0.1f, 0.1f, 10.0f);
    ImGui::DragFloat("Death Size", &m_Particle.SizeEnd, 0.1f, 0.1f, 10.0f);
    ImGui::DragFloat("Size Variation", &m_Particle.SizeVariation, 0.1f);
    ImGui::NewLine();
    ImGui::DragFloat2("Velocity", glm::value_ptr(m_Particle.Velocity), 0.1f);
    ImGui::DragFloat2("Velocity Variation", glm::value_ptr(m_Particle.VelocityVariation), 0.1f);
    ImGui::NewLine();
    ImGui::DragFloat("Rotation", &m_Particle.Rotation, 0.1f);
    ImGui::NewLine();
    ImGui::DragFloat("Lifetime", &m_Particle.LifeTime, 0.1f);
    ImGui::End();
}

void SandboxLayer::OnEvent(Saturn::Event& e)
{
    m_OrthoCamera.OnEvent(e);
}
