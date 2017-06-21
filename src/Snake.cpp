#include "Snake.hpp"

#include "Arena.hpp"
#include "Tail.hpp"

#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Core/GamepadPredefs.hpp"
#include "jam-engine/Utility/Trig.hpp"
#include "jam-engine/Utility/Math.hpp"

namespace snk
{

Snake::Snake(sf::Vector2f position, Arena *arena, int snakeId)
	:je::Entity(arena, "Snake", position, sf::Vector2i(16, 16))
	,controls(arena->getGame().getInput(), snakeId)
	,snakeId(snakeId)
	,direction(0.f)
	,speed(5.f)
	,head(8.f)
{
	controls.setAxis("move_x_gp", je::Controller::AxisBind(sf::Joystick::Axis::X));
	controls.setAxis("move_y_gp", je::Controller::AxisBind(sf::Joystick::Axis::Y));
	const je::Axes gpAxes(controls, "move_x_gp", "move_y_gp");
	movement = je::AxesSet({ gpAxes });
	//controls.addKeybind("turn_left", je::Binds::X360::LStickLeft);
	//controls.addKeybind("turn_right", je::Binds::X360::LStickRight);
}

float dot(sf::Vector2f a, sf::Vector2f b)
{
	return 0;
}

typedef sf::Vector2f V2;

void Snake::onUpdate()
{
	level->addEntity(new Tail(this, 50));
	const float turn_speed = 0.5f;
	sf::Vector2f input_vector = movement.getPos();
	const float input_magnitude = je::length(input_vector);
	sf::Vector2f current_vector = je::lengthdir(speed, direction);
	float dir_diff = je::direction(current_vector) - je::direction(input_vector);
	//dir_diff = std::min(dir_diff, 360.f - dir_diff);
	if (input_magnitude > 0.2f)
	{
		direction = je::direction(current_vector) + ((dir_diff)*input_magnitude*turn_speed);
		direction = je::direction(input_vector);
	}

	transform().move(je::lengthdir(speed, direction));
	head.setPosition(getPos());
}

void Snake::draw(sf::RenderTarget& target, const sf::RenderStates &states) const
{
	target.draw(head);
}

} // snk