/*
(c)2018, Gabriel Buiar e Fiul
*/

#include "Level.h"


Level::Level() :
	view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(static_cast<float>(WINDOW_WIDHT), static_cast<float>(WINDOW_HEIGHT)))

{
}


Level::~Level()
{
}

void Level::ResizeView()
{
	float aspectRatio = float(window->getSize().x) / float(window->getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void Level::InitializePlatforms()
{
	Platforms.includePlatform(sf::Vector2f(1500.0f, VIEW_HEIGHT), sf::Vector2f(3000.0f, 100.0f), "Textures/Backgrounds.png");
	Platforms.includePlatform(sf::Vector2f(1000.0f, VIEW_HEIGHT / 2.0f), sf::Vector2f(1000.0f, 100.0f), "Textures/Backgrounds.png");
}

void Level::Initialize()
{
	InitializePlatforms();
}

void Level::includePlayer(Player * player)
{
	Players.include(player);

	if (FirstPlayer)
	{
		player1 = player;
	}
	else
	{
		player2 = player;
		P2 = true;
	}
	
	FirstPlayer = false;
}

void Level::checkCollisions()
{
	//Collisions between the players and the players
	ListT<Player*>::Element<Player*>* pAux3 = Players.getFirst();

	sf::Vector2f direction;

	while (pAux3 != NULL)
	{
		Players.checkCollision(pAux3->getInf(),	-5.f);
		pAux3 = pAux3->getNext();
	}

	//Collisions between the enemies and the players
	ListT<Player*>::Element<Player*>* pAux2 = Players.getFirst();
	while (pAux2 != NULL)
	{
		Enemies.checkCollision(pAux2->getInf(), -.5f);
		pAux2 = pAux2->getNext();
	}

	//Collisions between the players and the platforms
	ListT<Player*>::Element<Player*>* pAux0 = Players.getFirst();
	while (pAux0 != NULL)
	{
		Platforms.CheckCollision(pAux0->getInf(), 1.f);
		pAux0 = pAux0->getNext();
	}

	//Collisions between the enemies and the platforms
	ListT<Enemy*>::Element<Enemy*>* pAux1 = Enemies.getFirst();
	while (pAux1 != NULL)
	{
		Platforms.CheckCollision(pAux1->getInf(), 1.f);
		pAux1 = pAux1->getNext();
	}

}

void Level::save()
{
	std::ofstream Save("Game.dat", std::ios::out);
	Save << levelId << std::endl;

	Backgrounds.save();
	Platforms.save();
	Players.save();
	Enemies.save();
}

void Level::Execute()
{
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDHT, WINDOW_HEIGHT), "GAME", sf::Style::Default);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 60.0f)
			deltaTime = 1.0f / 60.0f;

		sf::Event evnt;

		while (window->pollEvent(evnt))
		{

			switch (evnt.type)
			{
			case sf::Event::Closed:
				//Closes window
				window->close();
				break;

			case sf::Event::Resized:
				//Resize window and view
				ResizeView();
				break;

			default:
				break;
			}
		}

		//Update
		Players.update(deltaTime);
		if (!P2)
			Enemies.update(deltaTime, player1->getPosition());
		else
			Enemies.update(deltaTime, player1->getPosition(), player2->getPosition());


		if (!player1->Dead())
		{
			if (player1->getPosition().x >= ((WINDOW_WIDHT / 2.0f) - (WINDOW_WIDHT * PLAYERXPOSSCALE)))
			{
				if (P2)
				{
					if (player2->getPosition().x >= WINDOW_WIDHT / 2.f + (WINDOW_WIDHT * PLAYERXPOSSCALE) + player1->getPosition().x)
						player2->setPositionx(player1->getPosition().x + WINDOW_WIDHT / 2.f + (WINDOW_WIDHT * PLAYERXPOSSCALE));
					if (player2->getPosition().x <= -(WINDOW_WIDHT / 2.f) + (WINDOW_WIDHT * PLAYERXPOSSCALE) + player1->getPosition().x)
						player2->setPositionx(player1->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE) - (WINDOW_WIDHT / 2.f));
				}
			}

			else
			{
				if (P2)
				{
					if (player2->getPosition().x >= WINDOW_WIDHT)
						player2->setPositionx(float(WINDOW_WIDHT));
				}
			}
			if (player1->getPosition().x <= 0.f)
				player1->setPositionx(0.f);
		}
		if (P2)
		{
			if (!player2->Dead())
				if (player2->getPosition().x <= 0.f)
					player2->setPositionx(0.f);
		}

		if ((!P2 && player1->Dead()) || (P2 && player1->Dead() && player2->Dead()))
		{
			window->close();
			break;
		}


		//Move the view and the background according to the players
		if (!player1->Dead())
		{
			if (player1->getPosition().x >= ((WINDOW_WIDHT / 2.0f) - (WINDOW_WIDHT * PLAYERXPOSSCALE)))
			{
				view.setCenter(player1->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE), (WINDOW_HEIGHT / 2.0f));
				Backgrounds.move(sf::Vector2f(player1->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE) - (WINDOW_WIDHT / 2.0f), 0.0f), player1->getSpeed());
			}
			else
			{
				view.setCenter(WINDOW_WIDHT / 2.0f, WINDOW_HEIGHT / 2.0f);
			}
		}
		else
		{
				view.setCenter(player2->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE), (WINDOW_HEIGHT / 2.0f));
				Backgrounds.move(sf::Vector2f(player2->getPosition().x + (WINDOW_WIDHT * PLAYERXPOSSCALE) - (WINDOW_WIDHT / 2.0f), 0.0f), player2->getSpeed());
		}

		//Check Collisions
		checkCollisions();

		//Clear the window and set the view
		window->clear(sf::Color(171, 106, 140));
		window->setView(view);

		//Draw
		Backgrounds.Draw(window);
		Platforms.Draw(window);
		Players.draw(window);
		Enemies.draw(window);

		window->display();
		
	}
}
