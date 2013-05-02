// this is the header file for Game Node which holds the game relevant information of each vertex.

#pragma once

#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "GameNodeGraphics.h"


class GameNode {
public:
	GameNode(unsigned index, const Point &loc, bool antennot[]);
	void addPotential(unsigned neigh);
	bool click(Graph<GameNode>& graph, Point& loc, MOUSE_CLICK_TYPE click);
	bool checkAntenna(unsigned index) const;

	void draw(sf::RenderWindow& window);
	void light(sf::RenderWindow& window);
	Point getPos() const { return _graphics.getPos(); }
	void setPotentialNeighbors(int index, int neighbor);

private:
	unsigned _my_index;
	bool _antennot[NUM_OF_POSSIBLE_NEIGHBORS]; // this is the flag Array represents where the Node's edges.
	unsigned _potentialNeighbors[NUM_OF_POSSIBLE_NEIGHBORS]; // potential neighbors of the Node represented by their index on the graph.
	GameNodeGraphics _graphics; // graphic representation of the Game node.


	void shiftRight(bool temp_antennot[]);
	void shiftLeft(bool temp_antennot[]);
	void shift(bool last_antennot[], unsigned shifter);
};

