#include "MainGame.h"



MainGame::MainGame()
{

}


MainGame::~MainGame()
{

}

void MainGame::Execute()
{

	menu = new Menu;
	int op = 0;

	while (op != 3)
	{
		op = menu->execute();

		switch (op)
		{
		case 1:
		{
			createLevel_1_1(builder1);
			Level* level1 = builder1.getLevel();
			level1->Execute();
			break;
		}
		case 2:
		{
			createLevel_1_2(builder1);
			Level* level1 = builder1.getLevel();
			level1->Execute();
			break;
		}
		case 3:
		{

		}
		}
	}
}

void MainGame::createLevel_1_1(LevelBuilder& builder)
{
	builder.BuildLevel();
	builder.BuildBackground(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT));
	builder.BuildBackground_1(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_1(sf::Vector2f(WINDOW_WIDHT, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_2(sf::Vector2f(-300.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png");
	builder.BuildBackground_2(sf::Vector2f(WINDOW_WIDHT - 300, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png");
	builder.BuildPlayer(sf::Vector2f(100.0f, WINDOW_HEIGHT - 75.f), sf::Vector2f(100.0f, 150.0f));
	builder.BuildPlatform(sf::Vector2f(1500.0f, WINDOW_HEIGHT), sf::Vector2f(3000.0f, 100.0f), "Textures/Platform.png");
	builder.BuildPlatform(sf::Vector2f(1000.0f, WINDOW_HEIGHT / 2.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Platform.png");
	builder.BuildEnemy(sf::Vector2f(1050.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(80.f, 125.f));
	builder.BuildEnemy(sf::Vector2f(1550.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(80.f, 125.f));
	builder.BuildEnemy(sf::Vector2f(1850.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(80.f, 125.f));
	builder.BuildEnemy(sf::Vector2f(450.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(80.f, 125.f));
}

void MainGame::createLevel_1_2(LevelBuilder& builder)
{
	builder.BuildLevel();
	builder.BuildBackground(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT));
	builder.BuildBackground_1(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_1(sf::Vector2f(WINDOW_WIDHT, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_3.png", -0.01f, -15.2f);
	builder.BuildBackground_2(sf::Vector2f(-300.0f, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png");
	builder.BuildBackground_2(sf::Vector2f(WINDOW_WIDHT - 300, 0.0f), sf::Vector2f(WINDOW_WIDHT, WINDOW_HEIGHT), "Textures/Background_Layer_2.png");
	builder.BuildPlayer(sf::Vector2f(100.0f, WINDOW_HEIGHT - 75.f), sf::Vector2f(100.0f, 150.0f));
	builder.BuildPlayer2(sf::Vector2f(1150.0f, WINDOW_HEIGHT - 75.f), sf::Vector2f(100.0f, 150.0f));
	builder.BuildPlatform(sf::Vector2f(1500.0f, WINDOW_HEIGHT), sf::Vector2f(3000.0f, 100.0f), "Textures/Platform.png");
	builder.BuildPlatform(sf::Vector2f(1000.0f, WINDOW_HEIGHT / 2.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Platform.png");
	builder.BuildEnemy(sf::Vector2f(1050.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(100.0f, 150.0f));
	builder.BuildEnemy(sf::Vector2f(1550.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(100.0f, 150.0f));
	builder.BuildEnemy(sf::Vector2f(1850.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(100.0f, 150.0f));
	builder.BuildEnemy(sf::Vector2f(450.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(100.0f, 150.0f));
}
