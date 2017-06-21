#include "Tail.hpp"

#include "Snake.hpp"

namespace snk
{

Tail::Tail(Snake *snake, int time)
	:je::Entity(snake->getLevel(), "Tail", snake->getPos(), sf::Vector2i(16,16))
	,time(time)
	,point(8)
{
	point.setPosition(snake->getPos());
}

void Tail::onUpdate()
{
	time--;
	if (time <= 0) {
		destroy();
	}
}
void Tail::draw(sf::RenderTarget& target, const sf::RenderStates &states) const
{
	target.draw(point);
}

}