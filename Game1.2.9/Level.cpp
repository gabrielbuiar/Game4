/*
(c)2018, Gabriel Buiar e Fiul
*/

#include "Level.h"


Level::Level() :
	view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(static_cast<float>(WINDOW_WIDHT), static_cast<float>(WINDOW_HEIGHT)))

{
	Character::setLevelLimit(WINDOW_HEIGHT + 75.f);
}


Level::~Level()
{
}

void Level::ResizeView()
{
	float aspectRatio = float(window->getSize().x) / float(window->getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
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
		if (!pAux2->getInf()->Dead())
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
	ListT<Enemy1*>::Element<Enemy1*>* pAux1 = Enemies.getFirst1();
	while (pAux1 != NULL)
	{
		Platforms.CheckCollision(pAux1->getInf(), 1.f);
		pAux1 = pAux1->getNext();
	}

	ListT<Enemy2*>::Element<Enemy2*>* pAux4 = Enemies.getFirst2();

	while (pAux4 != NULL)
	{
		Platforms.CheckCollision(pAux4->getInf(), 1.f);
		pAux4 = pAux4->getNext();
	}

	//Collisions between the obstacles and the platforms
	ListT<Entity*>::Element<Entity*>* pAux7 = Platforms.getFirst();
	while (pAux7 != NULL)
	{
		Obstacles.checkCollision(pAux7->getInf(), 0.f);
		pAux7 = pAux7->getNext();
	}

	//Collisions between the obstacles and the players
	ListT<Player*>::Element<Player*>* pAux5 = Players.getFirst();
	while (pAux5 != NULL)
	{
		Obstacles.checkCollision(pAux5->getInf(), 0.f);
		pAux5 = pAux5->getNext();
	}
	//Collision between the obstacles and the enemies
	ListT<Enemy1*>::Element<Enemy1*>* pAux6 = Enemies.getFirst1();
	while (pAux6 != NULL)
	{
		Obstacles.checkCollision(pAux6->getInf(), 0.f);
		pAux6 = pAux6->getNext();
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
				save();
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
		if ((!P2) || (P2 && player2->Dead()))
			Enemies.update(deltaTime, player1->getPosition());
		else if (P2 && player1->Dead())
			Enemies.update(deltaTime, player2->getPosition());
		else
			Enemies.update(deltaTime, player1->getPosition(), player2->getPosition());
		Obstacles.update(deltaTime);


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
			save();
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
		Obstacles.draw(window);

		window->display();
		
	}
}
