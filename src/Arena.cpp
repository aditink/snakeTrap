#include "Arena.hpp"

#include "Snake.hpp"

namespace snk
{

Arena::Arena(je::Game *game, int width, int height)
	:je::Level(game, width, height)
{
	addEntity(new Snake(sf::Vector2f(32, 320), this, 0));
	addEntity(new Snake(sf::Vector2f(160, 160), this, 1));
}

} // snk