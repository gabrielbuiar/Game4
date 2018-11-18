#include "ListEntity.h"



ListEntity::ListEntity()
{
}


ListEntity::~ListEntity()
{
	Entities.clear();
}

void ListEntity::includePlayer(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, float speed, float jumpHeight)
{
	Player* pAux = new Player;
	pAux->InitializePlayer(position, size, textureFile, imgCount, speed, jumpHeight);
	Entities.include(static_cast<Entity*> (pAux));
}

void ListEntity::includePlatform(sf::Vector2f position, sf::Vector2f size, const char * textureFile)
{
	Platform* pAux = new Platform;
	pAux->InitializePlatform(position, size, textureFile);
	Entities.include(static_cast<Entity*> (pAux));
}


void ListEntity::Draw(sf::RenderWindow* window)
{
	ListT<Entity*>::Element <Entity*>* pAux;
	pAux = Entities.getpFirst();

	while (pAux != NULL)
	{
		pAux->getInf()->Draw(window);
		pAux = pAux->getNext();
	}
}

void ListEntity::Update(const float daltaTime)
{
	ListT<Entity*>::Element <Entity*>* pAux;
	pAux = Entities.getpFirst();

	while (pAux != NULL)
	{
		pAux->getInf()->Update(daltaTime);
		pAux = pAux->getNext();
	}
}

void ListEntity::move(sf::Vector2f position, float speed)
{
	ListT<Entity*>::Element <Entity*>* pAux;
	pAux = Entities.getpFirst();

	while (pAux != NULL)
	{
		pAux->getInf()->move(position, speed);
		pAux = pAux->getNext();
	}
}

void ListEntity::CheckCollision(Character* other, const float push)
{
	ListT<Entity*>::Element <Entity*>* pAux;
	pAux = Entities.getpFirst();
	sf::Vector2f direction;

	while (pAux != NULL)
	{
		pAux->getInf()->checkCollision(*other, direction, push);
		other->onCollision(direction);
		pAux = pAux->getNext();
	}
}

void ListEntity::save()
{
	std::ofstream Save("Game.dat", std::ios::app);
	ListT<Entity*>::Element <Entity*>* pAux;
	pAux = Entities.getpFirst();

	while (pAux != NULL)
	{
		pAux->getInf()->save(Save);
		pAux = pAux->getNext();
	}
}
