#ifndef SNK_TAIL_HPP
#define SNK_TAIL_HPP

#include "jam-engine\Core\Entity.hpp"

#include <SFML/Graphics.hpp>

namespace snk
{
class Arena;
class Snake;

class Tail : public je::Entity
{
public:
	Tail(Snake*, int time);

private:
	void onUpdate() override;

	void draw(sf::RenderTarget& target, const sf::RenderStates &states) const override;

	int time;

	sf::CircleShape point;
};
}

#endif