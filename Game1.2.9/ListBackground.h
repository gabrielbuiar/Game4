#pragma once
#include"Background.h"
#include"ListT.h"
#include<SFML/Graphics.hpp>
#include <fstream>

class ListBackground
{
public:
	ListBackground();
	~ListBackground();
	void include(Background* back);
	void Draw(sf::RenderWindow* window);
	void move(sf::Vector2f position, float speed);
	ListT<Background*>::Element<Background*>* getFirst() { return backgrounds.getpFirst(); }
	void save();

private:
	ListT<Background*> backgrounds;
};