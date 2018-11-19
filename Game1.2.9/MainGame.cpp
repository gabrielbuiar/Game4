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

	while (op != 4)
	{
		op = menu->execute();
		//op = 3;

		switch (op)
		{
		case 1:
		{
			createLevel_1_1(builder1);
			Level* level1 = builder1.getLevel();
			level1->Execute();
			op = menu->execute();
			break;
		}
		case 2:
		{
			createLevel_1_2(builder1);
			Level* level1 = builder1.getLevel();
			level1->Execute();
			op = menu->execute();
			break;
		}
		case 3:
		{
			Level* level = load();
			level->Execute();
			op = menu->execute();
			break;
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
	//builder.BuildEnemy(sf::Vector2f(1050.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(80.f, 125.f));
	//builder.BuildEnemy(sf::Vector2f(1550.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(80.f, 125.f));
	//builder.BuildEnemy(sf::Vector2f(1850.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(80.f, 125.f));
	//builder.BuildEnemy(sf::Vector2f(450.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(80.f, 125.f));
	//builder.BuildEnemy2(sf::Vector2f(1450.0f, WINDOW_HEIGHT - 80.f), sf::Vector2f(80.f, 125.f), 1000.f, 1750.f);
	builder.BuildObstacle_1(sf::Vector2f(1450.f, WINDOW_HEIGHT - 80.f), sf::Vector2f(100.f, 150.f), -450.f, 5.f);
	builder.BuildPlatform(sf::Vector2f(750.0f, WINDOW_HEIGHT), sf::Vector2f(20.0f, 200.0f), "Textures/Platform.png");
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

Level * MainGame::load()
{
	std::ifstream Load("Game.dat", std::ios::in);
	int id;

	std::streampos str;

	Load >> id;

	str = Load.tellg();

	switch (id)
	{
	case 1:
	{
		LevelBuilder1 builder;
		builder.BuildLevel();
		builder.load(str);
		
		return builder.getLevel();
	}
	case 2:
	{
		//Implement for LevelBuilder2
	}
	default:
	{
		break;
	}
	}

	return nullptr;
}
