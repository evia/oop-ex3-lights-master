#pragma once

#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <vector>

class GameNodeGraphics 
{
public:
	GameNodeGraphics(const Point& location);
	void draw(sf::RenderWindow& window, bool antennot_logic[NUM_OF_POSSIBLE_NEIGHBORS]);
	void light(sf::RenderWindow& window);
	bool isPosIn(const Point& pos) const;
	Point getPos() const;

private:
	sf::CircleShape _lightbulb;
	std::vector<sf::RectangleShape> _antennot;
};