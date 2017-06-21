#ifndef SNK_SNAKE_HPP
#define SNK_SNAKE_HPP

#include "jam-engine/Core/Entity.hpp"
#include "jam-engine/Core/Controller.hpp"

#include <SFML/Graphics.hpp>

namespace snk
{

class Arena;

class Snake : public je::Entity
{
public:
	Snake(sf::Vector2f position, Arena *arena, int snakeId);

	int getSnakeId() const { return snakeId; }

private:
	void onUpdate() override;

	void draw(sf::RenderTarget& target, const sf::RenderStates &states) const override;

	je::Controller controls;
	je::AxesSet movement;
	int snakeId;
	sf::CircleShape head;
	float direction;
	float speed;
};

} // snk

#endif