#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
namespace AS {
	class Ball
	{
	public:
		Ball(float x, float y, float radius);
		virtual ~Ball();

		void update(float deltaTime);
		void render(sf::RenderWindow& window);

	private:
		sf::CircleShape body;
		float x;
		float y;
		float radius;

		float x_speed;
		float y_speed;

	};
}

#endif