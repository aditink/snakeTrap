#include "jam-engine/Core/Game.hpp"

#include "Arena.hpp"

int main()
{
	const int width = 640;
	const int height = 480;
	je::Game game(width, height, 30);
	game.setLevel(new snk::Arena(&game, width, height));
	return game.execute();
}
