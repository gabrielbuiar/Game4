#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

int Menu::execute()
{

	window = new sf::RenderWindow(sf::VideoMode(unsigned int (WINDOW_WIDHT), unsigned int (WINDOW_HEIGHT)), "GAME", sf::Style::Default);


	while (window->isOpen())
	{

		sf::Event evnt;

		while (window->pollEvent(evnt))
		{

			switch (evnt.type)
			{
			case sf::Event::Closed:
				//Closes window
				window->close();
				return 3;

			case sf::Event::Resized:
				//Resize window and view
				//ResizeView();
				break;

			default:
				break;
			}
		}

		if (!menuTexture.loadFromFile(MENU_TEXT))
			std::cout << "ERROR" << std::endl;
		menuSprite.setTexture(menuTexture);

		menuSprite.setPosition(0.0f, 0.0f);

		if (!novoJogo.loadFromFile(NOVO_JOGO))
			std::cout << "ERROR" << std::endl;
		novoJogoSprite.setTexture(novoJogo);

		novoJogoSprite.setPosition(50.0f, 600.0f);

		if (!novoJogo.loadFromFile(NOVO_JOGO))
			std::cout << "ERROR" << std::endl;
		novoJogoSprite.setTexture(novoJogo);

		novoJogoSprite.setPosition(50.0f, 600.0f);


		if (!carregarJogo.loadFromFile(CARREGAR_JOGO))
			std::cout << "ERROR" << std::endl;
		carregarJogoSprite.setTexture(carregarJogo);

		carregarJogoSprite.setPosition(500.0f, 600.0f);

		if (!faseDois.loadFromFile(FASE_DOIS))
			std::cout << "ERROR" << std::endl;
		faseDoisSprite.setTexture(faseDois);

		faseDoisSprite.setPosition(950.0f, 600.0f);

		sf::FloatRect novo = novoJogoSprite.getGlobalBounds();
		sf::FloatRect fase = faseDoisSprite.getGlobalBounds();
		sf::FloatRect load = carregarJogoSprite.getGlobalBounds();

		int mouseX = sf::Mouse::getPosition(*window).x;
		int mouseY = sf::Mouse::getPosition(*window).y;

		float novoJogoX = novoJogoSprite.getPosition().x;
		float novoJogoY = novoJogoSprite.getPosition().y;

		float fase2X = faseDoisSprite.getPosition().x;
		float fase2Y = faseDoisSprite.getPosition().y;

		float loadX = carregarJogoSprite.getPosition().x;
		float loadY = carregarJogoSprite.getPosition().y;

		if (mouseX >= novoJogoX && mouseX <= novoJogoX + novo.width
			&& mouseY >= novoJogoY && mouseY <= novoJogoY + novo.height)
		{
			novoJogo.loadFromFile(NOVO_JOGO_RED);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				novoJogoSprite.setColor(sf::Color::Transparent);
				faseDoisSprite.setColor(sf::Color::Transparent);
				carregarJogoSprite.setColor(sf::Color::Transparent);

				if (!umJogador.loadFromFile(UM_PLAYER))
					std::cout << "ERROR" << std::endl;
				umJogadorSprite.setTexture(umJogador);
				umJogadorSprite.setPosition(100.0f, 50.0f);

				if (!doisJogadores.loadFromFile(DOIS_PLAYERS))
					std::cout << "ERROR" << std::endl;
				doisJogadoresSprite.setTexture(doisJogadores);
				doisJogadoresSprite.setPosition(800.0f, 50.0f);

				if (!ScottT.loadFromFile(SCOTT))
					std::cout << "ERROR" << std::endl;
				ScottS.setTexture(ScottT);

				if (!RamonaT.loadFromFile(RAMONA))
					std::cout << "ERROR" << std::endl;
				RamonaS.setTexture(RamonaT);

				ScottS.setPosition(120.0f, 230.0f);
				RamonaS.setPosition(810.0f, 177.0f);



				//level1.Inicializa();
				//level1.InitializePlatforms();
				//level1.InitializePlayers();
				//level->Execute(window);

			}

		}

		sf::FloatRect pUm = umJogadorSprite.getGlobalBounds();
		sf::FloatRect pDois = doisJogadoresSprite.getGlobalBounds();

		float Player1X = umJogadorSprite.getPosition().x;
		float Player1Y = umJogadorSprite.getPosition().y;

		float Player2X = doisJogadoresSprite.getPosition().x;
		float Player2Y = doisJogadoresSprite.getPosition().y;

		if (mouseX >= Player1X && mouseX <= Player1X + pUm.width
			&& mouseY >= Player1Y && mouseY <= Player1Y + pUm.height && LayerOne)
		{
			umJogador.loadFromFile(UM_PLAYER_RED);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				window->close();
				return 1;
			}
		}
		else
		{
			umJogador.loadFromFile(UM_PLAYER);
		}

		if (mouseX >= Player2X && mouseX <= Player2X + pDois.width
			&& mouseY >= Player2Y && mouseY <= Player2Y + pDois.height)
		{
			doisJogadores.loadFromFile(DOIS_PLAYERS_RED);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				window->close();
				return 2;
			}
		}
		else
		{
			doisJogadores.loadFromFile(DOIS_PLAYERS);
		}

		if (mouseX >= fase2X && mouseX <= fase2X + fase.width
			&& mouseY >= fase2Y && mouseY <= fase2Y + fase.height)
		{
			faseDois.loadFromFile(FASE_DOIS_RED);
		}

		if (mouseX >= loadX && mouseX <= loadX + load.width
			&& mouseY >= loadY && mouseY <= loadY + load.height)
		{
			carregarJogo.loadFromFile(CARREGAR_JOGO_RED);
		}

		window->clear();
		window->draw(menuSprite);
		window->draw(novoJogoSprite);
		window->draw(carregarJogoSprite);
		window->draw(faseDoisSprite);
		window->draw(umJogadorSprite);
		window->draw(doisJogadoresSprite);
		window->draw(ScottS);
		window->draw(RamonaS);
		window->display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			window->close();
			return 1;
		}

	}
}