#include "ListPlayer.h"



ListPlayer::ListPlayer()
{
}


ListPlayer::~ListPlayer()
{
	players.clear();
}

void ListPlayer::include(Player * player)
{
	if (player != NULL)
		players.include(player);
}

void ListPlayer::draw(sf::RenderWindow * window)
{
	ListT<Player*>::Element<Player*>* pAux = players.getpFirst();

	while (pAux != NULL)
	{
		if (!(pAux->getInf()->Dead()))
			pAux->getInf()->draw(*window);
		pAux = pAux->getNext();
	}
}

void ListPlayer::update(const float deltaTime)
{
	ListT<Player*>::Element<Player*>* pAux = players.getpFirst();

	while (pAux != NULL)
	{
		if (!(pAux->getInf()->Dead()))
			pAux->getInf()->Update(deltaTime);
		pAux = pAux->getNext();
	}
}

void ListPlayer::checkCollision(Character* other, const float push)
{
	ListT<Player*>::Element<Player*>* pAux = players.getpFirst();
	sf::Vector2f direction;

	while (pAux != NULL && !(pAux->getInf()->Dead()))
	{
		if (!(pAux->getInf()->Dead()) && !other->Dead())
		{
			pAux->getInf()->checkCollision(*other, direction, push);
			other->onCollision(direction);
		}

		pAux = pAux->getNext();
	}
}

void ListPlayer::checkCollision(Player* other, const float push)
{
	ListT<Player*>::Element<Player*>* pAux = players.getpFirst();
	sf::Vector2f direction;

	while (pAux != NULL && !(pAux->getInf()->Dead()))
	{
		if (!(pAux->getInf()->Dead()) && (!other->Dead()) && (pAux->getInf() != other))
		{
			pAux->getInf()->checkCollision(*other, direction, push);
			other->onCollision(direction);
		}

		pAux = pAux->getNext();
	}
}

void ListPlayer::save()
{
	std::ofstream Save("Game.dat", std::ios::app);
	ListT<Player*>::Element <Player*>* pAux;
	pAux = players.getpFirst();

	while (pAux != NULL)
	{
		pAux->getInf()->save(Save);
		pAux = pAux->getNext();
	}
}
