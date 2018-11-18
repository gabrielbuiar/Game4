#include "ListEnemy.h"



ListEnemy::ListEnemy()
{
}


ListEnemy::~ListEnemy()
{
	enemies1.clear();
	enemies2.clear();
}

void ListEnemy::draw(sf::RenderWindow * window)
{
	ListT<Enemy1*>::Element<Enemy1*>* pAux1 = enemies1.getpFirst();

	while (pAux1 != NULL)
	{
		if (!(pAux1->getInf()->Dead()))
			pAux1->getInf()->draw(*window);
		pAux1 = pAux1->getNext();
	}

	ListT<Enemy2*>::Element<Enemy2*>* pAux2 = enemies2.getpFirst();

	while (pAux2 != NULL)
	{
		if (!(pAux2->getInf()->Dead()))
			pAux2->getInf()->draw(*window);
		pAux2 = pAux2->getNext();
	}
}

void ListEnemy::update(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2)
{
	ListT<Enemy1*>::Element<Enemy1*>* pAux1 = enemies1.getpFirst();

	while (pAux1 != NULL)
	{
		if (!(pAux1->getInf()->Dead()))
			pAux1->getInf()->Update(deltaTime, position1, position2);
		pAux1 = pAux1->getNext();
	}

	ListT<Enemy2*>::Element<Enemy2*>* pAux2 = enemies2.getpFirst();

	while (pAux2 != NULL)
	{
		if (!(pAux2->getInf()->Dead()))
			pAux2->getInf()->Update(deltaTime, position1, position2);
		pAux2 = pAux2->getNext();
	}
}

void ListEnemy::update(const float deltaTime, sf::Vector2f position1)
{
	ListT<Enemy1*>::Element<Enemy1*>* pAux1 = enemies1.getpFirst();

	while (pAux1 != NULL)
	{
		if (!(pAux1->getInf()->Dead()))
			pAux1->getInf()->Update(deltaTime, position1);
		pAux1 = pAux1->getNext();
	}

	ListT<Enemy2*>::Element<Enemy2*>* pAux2 = enemies2.getpFirst();

	while (pAux2 != NULL)
	{
		if (!(pAux2->getInf()->Dead()))
			pAux2->getInf()->Update(deltaTime, position1);
		pAux2 = pAux2->getNext();
	}
}

void ListEnemy::checkCollision(Player * other, const float push)
{
	ListT<Enemy1*>::Element <Enemy1*>* pAux1 = enemies1.getpFirst();

	sf::Vector2f direction;

	while (pAux1 != NULL)
	{
		if (!pAux1->getInf()->Dead())
		{
			direction.x = 0.f;
			direction.y = 0.f;

			pAux1->getInf()->checkCollision(*other, direction, push);
			other->onCollision(direction);
			if (direction.x != 0.f || direction.y != 0.f)
			{

				if (!other->attacking())
					other->operator-=(pAux1->getInf()->getDamage());
				else
				{
					if (direction.x < 0.f && other->getfaceRight())
						other->operator-=(pAux1->getInf()->getDamage());

					if (direction.x > 0.f && !(other->getfaceRight()))
						other->operator-=(pAux1->getInf()->getDamage());

					if (direction.x > 0.f && other->getfaceRight() || direction.x < 0.f && !(other->getfaceRight()))
					{
						pAux1->getInf()->operator-=(other->getDamage());
						if (other->getDamage() > pAux1->getInf()->getLife())
						{
							other->operator+=(pAux1->getInf()->getKillPoints());
							pAux1->getInf();
						}
					}
				}
			}
		}

		pAux1 = pAux1->getNext();
	}

	ListT<Enemy2*>::Element <Enemy2*>* pAux2 = enemies2.getpFirst();

	while (pAux2 != NULL)
	{
		if (!pAux2->getInf()->Dead())
		{
			direction.x = 0.f;
			direction.y = 0.f;

			pAux2->getInf()->checkCollision(*other, direction, push);
			other->onCollision(direction);
			if (direction.x != 0.f || direction.y != 0.f)
			{

				if (!other->attacking())
					other->operator-=(pAux2->getInf()->getDamage());
				else
				{
					if (direction.x < 0.f && other->getfaceRight())
						other->operator-=(pAux2->getInf()->getDamage());

					if (direction.x > 0.f && !(other->getfaceRight()))
						other->operator-=(pAux2->getInf()->getDamage());

					if (direction.x > 0.f && other->getfaceRight() || direction.x < 0.f && !(other->getfaceRight()))
					{
						pAux2->getInf()->operator-=(other->getDamage());
						if (other->getDamage() > pAux2->getInf()->getLife())
						{
							other->operator+=(pAux2->getInf()->getKillPoints());
							pAux2->getInf();
						}
					}
				}
			}
		}

		pAux2 = pAux2->getNext();
	}
}

void ListEnemy::save()
{
	std::ofstream Save("Game.dat", std::ios::app);
	ListT<Enemy1*>::Element <Enemy1*>* pAux1;
	pAux1 = enemies1.getpFirst();

	while (pAux1 != NULL)
	{
		pAux1->getInf()->save(Save);
		pAux1 = pAux1->getNext();
	}

	ListT<Enemy2*>::Element <Enemy2*>* pAux2;
	pAux2 = enemies2.getpFirst();

	while (pAux2 != NULL)
	{
		pAux2->getInf()->save(Save);
		pAux2 = pAux2->getNext();
	}
}
