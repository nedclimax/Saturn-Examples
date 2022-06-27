#include <Saturn.h>
#include <Saturn/Core/EntryPoint.h>

#include "GameLayer.h"

using namespace Saturn;

class FlappyGame : public Saturn::Application
{
public:
	FlappyGame()
	{
		PushLayer(new GameLayer);
	}
};

Saturn::Application* Saturn::CreateApplication()
{
	return new FlappyGame();
}