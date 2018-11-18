#include "LevelBuilder1.h"



LevelBuilder1::LevelBuilder1()
{
	currentLevel = 0;
}


LevelBuilder1::~LevelBuilder1()
{

}

void LevelBuilder1::BuildLevel()
{
	currentLevel = new Level;
	currentLevel->setId(1);
}

void LevelBuilder1::BuildPlayer(sf::Vector2f position, sf::Vector2f size)
{
	Player* pAux = new Player();
	pAux->setLife(1000);
	pAux->InitializePlayer(position, size, "Textures/Player1_Standing.png", sf::Vector2u(8, 1), 200.0f, 200.0f);
	pAux->includeTextureVector((char*) "Textures/Player1_Standing.png");
	pAux->includeImgCountVector(8);
	pAux->includeTextureVector((char*) "Textures/Player1_Walking.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player1_Jumping.png");
	pAux->includeImgCountVector(13);
	pAux->includeTextureVector((char*) "Textures/Player1_Attacking.png");
	pAux->includeImgCountVector(12);
	pAux->setKeyRight(sf::Keyboard::D);
	pAux->setKeyLeft(sf::Keyboard::A);
	pAux->setKeyJump(sf::Keyboard::W);
	pAux->setKeyAttack(sf::Keyboard::Space);
	pAux->setDamage(100);
	pAux->setId(5);
	currentLevel->includePlayer(pAux);
}

void LevelBuilder1::BuildPlayer(sf::Vector2f position, sf::Vector2f size, const unsigned int life, const unsigned int points)
{
	Player* pAux = new Player();
	pAux->setLife(1000);
	pAux->InitializePlayer(position, size, "Textures/Player1_Standing.png", sf::Vector2u(8, 1), 200.0f, 200.0f);
	pAux->includeTextureVector((char*) "Textures/Player1_Standing.png");
	pAux->includeImgCountVector(8);
	pAux->includeTextureVector((char*) "Textures/Player1_Walking.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player1_Jumping.png");
	pAux->includeImgCountVector(13);
	pAux->includeTextureVector((char*) "Textures/Player1_Attacking.png");
	pAux->includeImgCountVector(12);
	pAux->setKeyRight(sf::Keyboard::D);
	pAux->setKeyLeft(sf::Keyboard::A);
	pAux->setKeyJump(sf::Keyboard::W);
	pAux->setKeyAttack(sf::Keyboard::Space);
	pAux->setDamage(100);
	pAux->setId(5);
	pAux->setLife(life);
	pAux->setPoints(points);
	currentLevel->includePlayer(pAux);
}

void LevelBuilder1::BuildPlayer2(sf::Vector2f position, sf::Vector2f size)
{
	Player* pAux = new Player();
	pAux->setLife(1000);
	pAux->InitializePlayer(position, size, "Textures/Player2_Standing.png", sf::Vector2u(6,1), 200.0f, 200.0f);
	pAux->includeTextureVector((char*) "Textures/Player2_Standing.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player2_Walking.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player2_Jumping.png");
	pAux->includeImgCountVector(9);
	pAux->includeTextureVector((char*) "Textures/Player2_Attacking.png");
	pAux->includeImgCountVector(8);
	pAux->setKeyRight(sf::Keyboard::Right);
	pAux->setKeyLeft(sf::Keyboard::Left);
	pAux->setKeyJump(sf::Keyboard::Up);
	pAux->setKeyAttack(sf::Keyboard::RAlt);
	pAux->setPlayer2();
	pAux->setDamage(100);
	pAux->setId(6);
	currentLevel->includePlayer(pAux);
}

void LevelBuilder1::BuildPlayer2(sf::Vector2f position, sf::Vector2f size, const unsigned int life, const unsigned int points)
{
	Player* pAux = new Player();
	pAux->setLife(1000);
	pAux->InitializePlayer(position, size, "Textures/Player2_Standing.png", sf::Vector2u(6, 1), 200.0f, 200.0f);
	pAux->includeTextureVector((char*) "Textures/Player2_Standing.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player2_Walking.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player2_Jumping.png");
	pAux->includeImgCountVector(9);
	pAux->includeTextureVector((char*) "Textures/Player2_Attacking.png");
	pAux->includeImgCountVector(8);
	pAux->setKeyRight(sf::Keyboard::Right);
	pAux->setKeyLeft(sf::Keyboard::Left);
	pAux->setKeyJump(sf::Keyboard::Up);
	pAux->setKeyAttack(sf::Keyboard::RAlt);
	pAux->setPlayer2();
	pAux->setDamage(100);
	pAux->setId(6);
	pAux->setLife(life);
	pAux->setPoints(points);
	currentLevel->includePlayer(pAux);
}

void LevelBuilder1::BuildEnemy(sf::Vector2f position, sf::Vector2f size)
{
	Enemy1* pAux = new Enemy1();
	pAux->setLife(500);
	pAux->InitializeEnemy1(position, size, "Textures/Enemy1.png", sf::Vector2u(8, 1), 300.0f, 80.0);
	pAux->includeTextureVector((char*) "Textures/Enemy1.png");
	pAux->includeImgCountVector(6);
	pAux->setDamage(7);
	pAux->setKillPoints(150);
	pAux->setId(7);
	currentLevel->includeEnemy(pAux);

}

void LevelBuilder1::BuildEnemy(sf::Vector2f position, sf::Vector2f size, const unsigned int life)
{
	Enemy1* pAux = new Enemy1();
	pAux->setLife(500);
	pAux->InitializeEnemy1(position, size, "Textures/Enemy1.png", sf::Vector2u(8, 1), 300.0f, 80.0);
	pAux->includeTextureVector((char*) "Textures/Enemy1.png");
	pAux->includeImgCountVector(6);
	pAux->setDamage(10);
	pAux->setKillPoints(150);
	pAux->setId(7);
	pAux->setLife(life);
	currentLevel->includeEnemy(pAux);
}

void LevelBuilder1::BuildEnemy2(sf::Vector2f position, sf::Vector2f size, const float pos1, const float pos2)
{
	Enemy2* pAux = new Enemy2();
	pAux->setLife(500);
	pAux->InitializeEnemy2(position, size, "Textures/Enemy1.png", sf::Vector2u(8, 1), 300.0f, 200.0, pos1, pos2);
	pAux->includeTextureVector((char*) "Textures/Enemy1.png");
	pAux->includeImgCountVector(6);
	pAux->setDamage(7);
	pAux->setKillPoints(150);
	pAux->setId(8);
	currentLevel->includeEnemy(pAux);
}

void LevelBuilder1::BuildEnemy2(sf::Vector2f position, sf::Vector2f size, const float pos1, const float pos2, const unsigned int life)
{
	Enemy2* pAux = new Enemy2();
	pAux->setLife(500);
	pAux->InitializeEnemy2(position, size, "Textures/Enemy1.png", sf::Vector2u(8, 1), 300.0f, 200.0, pos1, pos2);
	pAux->includeTextureVector((char*) "Textures/Enemy1.png");
	pAux->includeImgCountVector(6);
	pAux->setDamage(7);
	pAux->setKillPoints(150);
	pAux->setId(8);
	pAux->setLife(life);
	currentLevel->includeEnemy(pAux);
}

void LevelBuilder1::BuildPlatform(sf::Vector2f position, sf::Vector2f size, const char* textureFile)
{
	Platform* pAux = new Platform;
	pAux->InitializePlatform(position, size, textureFile);
	pAux->setId(4);
	currentLevel->includePlatform(pAux);
}

void LevelBuilder1::BuildObstacle()
{

}

void LevelBuilder1::BuildBackground(sf::Vector2f position, sf::Vector2f size)
{
	Background* pAux = new Background;
	pAux->Initialize(position, size, "Textures/Background.png", 0.f, 1.f);
	pAux->setId(1);
	currentLevel->includeBackground(pAux);
}

void LevelBuilder1::BuildBackground_1(sf::Vector2f position, sf::Vector2f size, const char * textureFile, const float increment, const float incrementScale)
{
	Background* pAux = new Background;
	pAux->Initialize(position, size, textureFile, increment, incrementScale);
	pAux->setId(2);
	currentLevel->includeBackground(pAux);
}

void LevelBuilder1::BuildBackground_2(sf::Vector2f position, sf::Vector2f size, const char* textureFile)
{
	Background* pAux = new Background;
	pAux->Initialize(position, size, textureFile, 0.f, 1.f);
	pAux->Stand();
	pAux->setId(3);
	currentLevel->includeBackground(pAux);
}

void LevelBuilder1::load(std::streampos str)
{
	std::ifstream Load("Game.dat", std::ios::in);
	int id;

	while (!Load.eof())
	{
		Load.seekg(str);

		Load >> id;

		str = Load.tellg();

		switch (id)
		{
		case 1:
		{
			str = LoadBackground(str);
			Load.seekg(str);
			id = -1;
			break;
		}
		case 2:
		{
			str = LoadBackground_1(str);
			Load.seekg(str);
			id = -1;
			break;
		}
		case 3:
		{
			str = LoadBackground_2(str);
			Load.seekg(str);
			id = -1;
			break;
		}
		case 4:
		{
			str = LoadPlatform(str);
			Load.seekg(str);
			id = -1;
			break;
		}
		case 5:
		{
			str = LoadPlayer(str);
			Load.seekg(str);
			id = -1;
			break;
		}
		case 6:
		{
			str = LoadPlayer2(str);
			Load.seekg(str);
			id = -1;
			break;
		}
		case 7:
		{
			str = LoadEnemy(str);
			Load.seekg(str);
			id = -1;
			break;
		}
		default:
			break;
		}
	}
}

std::streampos LevelBuilder1::LoadPlatform(std::streampos str)
{
	std::ifstream Load("Game.dat", std::ios::in);
	sf::Vector2f position, size;
	char textureFile[50];

	Load.seekg(str);

	Load >> position.x >> position.y >> size.x >> size.y >> textureFile;
	BuildPlatform(position, size, textureFile);

	str = Load.tellg();

	return str;
}

std::streampos LevelBuilder1::LoadBackground(std::streampos str)
{
	std::ifstream Load("Game.dat", std::ios::in);
	sf::Vector2f position, size;
	char textureFile[50];
	float increment, incrementscale;

	Load.seekg(str);

	Load >> position.x >> position.y >> size.x >> size.y >> textureFile >> increment >> incrementscale;
	BuildBackground(position, size);

	std::cout << position.x << ' ' << position.y << ' ' << size.x << ' ' << size.y << ' ' << textureFile << ' ' << increment << ' ' << incrementscale << std::endl;

	str = Load.tellg();

	return str;
}

std::streampos LevelBuilder1::LoadBackground_1(std::streampos str)
{
	std::ifstream Load("Game.dat", std::ios::in);
	sf::Vector2f position, size;
	char textureFile[50];
	float increment, incrementscale;

	Load.seekg(str);

	Load >> position.x >> position.y >> size.x >> size.y >> textureFile >> increment >> incrementscale;
	BuildBackground_1(position, size, textureFile, increment, incrementscale);

	str = Load.tellg();

	return str;
}

std::streampos LevelBuilder1::LoadBackground_2(std::streampos str)
{
	std::ifstream Load("Game.dat", std::ios::in);
	sf::Vector2f position, size;
	char textureFile[50];
	float increment, incrementscale;

	Load.seekg(str);

	Load >> position.x >> position.y >> size.x >> size.y >> textureFile >> increment >> incrementscale;
	BuildBackground_2(position, size, textureFile);

	str = Load.tellg();

	return str;
}

std::streampos LevelBuilder1::LoadPlayer(std::streampos str)
{
	std::ifstream Load("Game.dat", std::ios::in);
	sf::Vector2f position, size;
	unsigned int life, points;

	Load.seekg(str);

	Load >> position.x >> position.y >> size.x >> size.y >> life >> points;
	BuildPlayer(position, size, life, points);

	str = Load.tellg();

	return str;
}

std::streampos LevelBuilder1::LoadPlayer2(std::streampos str)
{
	std::ifstream Load("Game.dat", std::ios::in);
	sf::Vector2f position, size;
	unsigned int life, points;

	Load.seekg(str);

	Load >> position.x >> position.y >> size.x >> size.y >> life >> points;
	BuildPlayer2(position, size, life, points);

	str = Load.tellg();

	return str;
}

std::streampos LevelBuilder1::LoadEnemy(std::streampos str)
{
	std::ifstream Load("Game.dat", std::ios::in);
	sf::Vector2f position, size;
	unsigned int life;

	Load.seekg(str);

	Load >> position.x >> position.y >> size.x >> size.y >> life;
	BuildEnemy(position, size, life);

	str = Load.tellg();

	return str;
}

std::streampos LevelBuilder1::LoadEnemy2(std::streampos str)
{
	std::ifstream Load("Game.dat", std::ios::in);
	sf::Vector2f position, size;
	unsigned int life;
	float pos1, pos2;

	Load.seekg(str);

	Load >> position.x >> position.y >> size.x >> size.y >> pos1 >> pos2 >> life;
	BuildEnemy2(position, size, pos1, pos2, life);

	str = Load.tellg();

	return str;
}
