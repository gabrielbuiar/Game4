#include "ListBackground.h"



ListBackground::ListBackground()
{
}


ListBackground::~ListBackground()
{
}

void ListBackground::include(Background * back)
{
	if (back != NULL)
		backgrounds.include(back);
}

void ListBackground::Draw(sf::RenderWindow * window)
{
	ListT<Background*>::Element <Background*>* pAux;
	pAux = backgrounds.getpFirst();

	while (pAux != NULL)
	{
		pAux->getInf()->Draw(window);
		pAux = pAux->getNext();
	}
}

void ListBackground::move(sf::Vector2f position, float speed)
{
	ListT<Background*>::Element <Background*>* pAux;
	pAux = backgrounds.getpFirst();

	while (pAux != NULL)
	{
		pAux->getInf()->move(position, speed);
		pAux = pAux->getNext();
	}
}

void ListBackground::save()
{
	std::ofstream Save("Game.dat", std::ios::app);
	ListT<Background*>::Element <Background*>* pAux;
	pAux = backgrounds.getpFirst();

	while (pAux != NULL)
	{
		pAux->getInf()->save(Save);
		pAux = pAux->getNext();
	}
	
}
