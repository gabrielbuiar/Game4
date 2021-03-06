/*
	Classe Level - ghjdjlkjgdflkjglkdfjglkdfjgldfk

	(c) 2018, Gabriel Buiar e Fiul

	Historico
	1.0 - 18nov2018	- Versao Inicial
*/
#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Platform.h"
#include "ListT.h"
#include "ListEntity.h"
#include "Background.h"
#include "ListPlayer.h"
#include "ListEnemy.h"
#include "ListObstacles.h"
#include "ListBackground.h"
#include <vector>
#include <fstream>

class Level
{
public:
	Level();
	~Level();
	void Execute();
	void ResizeView();

	/*void InitializePlatforms();
	void Initialize();*/
	void setPlayer1(Player* player) { player1 = player; }
	void setPlayer2(Player* player) { player2 = player; }

	void includePlayer(Player*  player);
	void includeEnemy(Enemy1* enemy) { Enemies.include(enemy); }
	void includeEnemy(Enemy2* enemy) { Enemies.include(enemy); }
	void includePlatform(Platform* platform) { Platforms.include(*platform); }
	void includeBackground(Background* background) { Backgrounds.include(background); }
	void includeObstacle(Obstacle* obstacle) { Obstacles.include(obstacle); }
	void includeObstacle(Obstacle1* obstacle) { Obstacles.include(obstacle); }
	void save();
	void setId(const int id) { levelId = id; }
	void pause(sf::RenderWindow& window);

	void checkCollisions();

private:
	//Macros
	const int WINDOW_WIDHT = 1920;
	const int WINDOW_HEIGHT = 1080;
	const float VIEW_HEIGHT = 1000.0f;
	const char* PLAYER_TEXTURE_FILE = "Textures/Player1_Standing.png";
	const char* BACKGROUND_TEXTURE_FILE = "Textures/Background.png";
	const float PLAYERXPOSSCALE = 1.0f / 3.5f;

	int levelId;

	sf::RenderWindow* window = NULL;
	sf::View view;
	sf::Texture playerText;
	sf::Sprite playerSprite;

	//Lists of the different Entities
	ListEntity Platforms;
	ListBackground Backgrounds;
	ListPlayer Players;
	ListEnemy Enemies;
	ListObstacles Obstacles;


	//std::vector<sf::Sprite> Background;

	Player* player1;
	Player* player2 = NULL;

	bool FirstPlayer = true;
	bool P2 = false;

	int pauseDelay = 0;

	Background back;
};
