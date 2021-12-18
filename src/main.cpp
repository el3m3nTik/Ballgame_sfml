#include <SFML/Graphics.hpp>
#include <iostream>

#include "Ball.hpp"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

static const unsigned int width = 640;
static const unsigned int height = 480;

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "ballgame");

	sf::Texture texture;
	if (!texture.loadFromFile("image/kletka2.jpg"))
	{
		std::cout << "ERROR when loading back.png" << std::endl;
		return false;
	}
	sf::Sprite back;
	back.setTexture(texture);

	sf::Image icon;
	if (!icon.loadFromFile("image/ball.png"))
	{
		return -1;
	}
	window.setIcon(30, 30, icon.getPixelsPtr());


	sf::Clock clock;
	float deltaTime = 0.0f;

	AS::Ball ball(70.0f, 90.0f, 20.0f);
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(back);

		ball.update(deltaTime);
		ball.render(window);

		window.display();

	}

	return 0;
}