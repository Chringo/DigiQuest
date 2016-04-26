#include <SFML/Window.hpp>
#include "Game.hpp"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(1280, 720), "TITLE"/*, sf::Style::None*/);
	Game game;
	sf::Clock gameTime;

	while (window.isOpen())
	{
		// Check all the window's events that were triggered since the last iteration of the loop
		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::KeyPressed:
				if (e.key.code != sf::Keyboard::Escape)// 36 = ESC
				{
					std::printf("%d", e.key.code);
				}
				else // Close
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		
		game.Update(gameTime.restart().asSeconds());
		window.clear();
		window.draw(game);
		window.display();
	}

	return 0;
}