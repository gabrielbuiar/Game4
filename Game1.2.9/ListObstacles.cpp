#include "ListObstacles.h"



ListObstacles::ListObstacles()
{
}


ListObstacles::~ListObstacles()
{
}

void ListObstacles::draw(sf::RenderWindow * window)
{
	ListT<Obstacle*>::Element<Obstacle*>* pAux1 = obstacles.getpFirst();

	while (pAux1 != NULL)
	{
		pAux1->getInf()->draw(*window);
		pAux1 = pAux1->getNext();
	}
	ListT<Obstacle1*>::Element<Obstacle1*>* pAux2 = obstacles1.getpFirst();

	while (pAux2 != NULL)
	{
		pAux2->getInf()->draw(*window);
		pAux2 = pAux2->getNext();
	}
}

void ListObstacles::update(const float deltaTime)
{
	ListT<Obstacle*>::Element<Obstacle*>* pAux1 = obstacles.getpFirst();

	while (pAux1 != NULL)
	{
		pAux1->getInf()->Update(deltaTime);
		pAux1 = pAux1->getNext();
	}

	ListT<Obstacle1*>::Element<Obstacle1*>* pAux2 = obstacles1.getpFirst();

	while (pAux2 != NULL)
	{
		pAux2->getInf()->Update(deltaTime);
		pAux2 = pAux2->getNext();
	}
}

void ListObstacles::checkCollision(Entity* other, const float push)
{
	ListT<Obstacle*>::Element<Obstacle*>* pAux1 = obstacles.getpFirst();
	sf::Vector2f direction;
	while (pAux1 != NULL)
	{
		pAux1->getInf()->checkCollision(*other, direction, push);
		pAux1 = pAux1->getNext();
	}

	ListT<Obstacle1*>::Element<Obstacle1*>* pAux2 = obstacles1.getpFirst();

	while (pAux2 != NULL)
	{
		pAux2->getInf()->checkCollision(*other, direction, push);
		pAux2 = pAux2->getNext();
	}
}

void ListObstacles::checkCollision(Character * other, const float push)
{
	ListT<Obstacle*>::Element<Obstacle*>* pAux1 = obstacles.getpFirst();
	sf::Vector2f direction;
	while (pAux1 != NULL)
	{
			pAux1->getInf()->checkCollision(*other, direction, push);
			other->onCollision(direction);

		pAux1 = pAux1->getNext();
	}

	ListT<Obstacle1*>::Element<Obstacle1*>* pAux2 = obstacles1.getpFirst();

	while (pAux2 != NULL)
	{
		pAux2->getInf()->checkCollision(*other, direction, push);
		pAux2 = pAux2->getNext();
	}
}

void ListObstacles::save()
{
	std::ofstream Save("Game.dat", std::ios::app);
	ListT<Obstacle*>::Element <Obstacle*>* pAux1;
	pAux1 = obstacles.getpFirst();

	while (pAux1 != NULL)
	{
		pAux1->getInf()->save(Save);
		pAux1 = pAux1->getNext();
	}

	ListT<Obstacle1*>::Element <Obstacle1*>* pAux2;
	pAux2 = obstacles1.getpFirst();

	while (pAux2 != NULL)
	{
		pAux2->getInf()->save(Save);
		pAux2 = pAux2->getNext();
	}
}
