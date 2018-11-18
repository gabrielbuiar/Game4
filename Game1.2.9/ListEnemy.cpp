#include "ListEnemy.h"



ListEnemy::ListEnemy()
{
}


ListEnemy::~ListEnemy()
{
	enemies.clear();
}

void ListEnemy::include(Enemy * enemy)
{
	if (enemy != NULL)
		enemies.include(enemy);
}

void ListEnemy::draw(sf::RenderWindow * window)
{
	ListT<Enemy*>::Element<Enemy*>* pAux = enemies.getpFirst();

	while (pAux != NULL)
	{
		if (!(pAux->getInf()->Dead()))
			pAux->getInf()->draw(*window);
		pAux = pAux->getNext();
	}
}

void ListEnemy::update(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2)
{
	ListT<Enemy*>::Element<Enemy*>* pAux = enemies.getpFirst();

	while (pAux != NULL)
	{
		if (!(pAux->getInf()->Dead()))
		{
			pAux->getInf()->Update(deltaTime, position1, position2);
		}
		pAux = pAux->getNext();
	}
}

void ListEnemy::update(const float deltaTime, sf::Vector2f position1)
{
	ListT<Enemy*>::Element<Enemy*>* pAux = enemies.getpFirst();

	while (pAux != NULL)
	{
		if (!(pAux->getInf()->Dead()))
			pAux->getInf()->Update(deltaTime, position1);
		pAux = pAux->getNext();
	}
}

void ListEnemy::checkCollision(Player * other, const float push)
{
	ListT<Enemy*>::Element <Enemy*>* pAux = enemies.getpFirst();

	sf::Vector2f direction;

	while (pAux != NULL)
	{
		if (!pAux->getInf()->Dead())
		{
			direction.x = 0.f;
			direction.y = 0.f;

			pAux->getInf()->checkCollision(*other, direction, push);
			other->onCollision(direction);
			if (direction.x != 0.f || direction.y != 0.f)
			{

				if (!other->attacking())
					other->operator-=(pAux->getInf()->getDamage());
				else
				{
					if (direction.x < 0.f && other->getfaceRight())
						other->operator-=(pAux->getInf()->getDamage());

					if (direction.x > 0.f && !(other->getfaceRight()))
						other->operator-=(pAux->getInf()->getDamage());

					if (direction.x > 0.f && other->getfaceRight() || direction.x < 0.f && !(other->getfaceRight()))
					{
						pAux->getInf()->operator-=(other->getDamage());
						if (other->getDamage() > pAux->getInf()->getLife())
						{
							other->operator+=(pAux->getInf()->getKillPoints());
							pAux->getInf();
						}
					}
				}
			}
		}

		pAux = pAux->getNext();
	}
}

void ListEnemy::save()
{
	std::ofstream Save("Game.dat", std::ios::app);
	ListT<Enemy*>::Element <Enemy*>* pAux;
	pAux = enemies.getpFirst();

	while (pAux != NULL)
	{
		pAux->getInf()->save(Save);
		pAux = pAux->getNext();
	}
}
