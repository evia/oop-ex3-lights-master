#include "GameNode.h"

const unsigned TO_OPPOSITE = 3;


// Constructor
GameNode::GameNode(unsigned index, const Point &loc, bool antennot[]) : _my_index(index), _graphics(loc)
{ 
	for (unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
		_antennot[i] = antennot[i];
}

// check if opposite antenna exists
bool GameNode::checkAntenna(unsigned index) const
{
	// validate
	if (index >= NUM_OF_POSSIBLE_NEIGHBORS)
		return false;

	// return opposite antenna status (clock rotation)
	return _antennot[(index+TO_OPPOSITE) % NUM_OF_POSSIBLE_NEIGHBORS];
}

// event handler for clicking on the game node
bool GameNode::click(Graph<GameNode>& graph, Point& loc, MOUSE_CLICK_TYPE click)
{
	// check location
	if (!_graphics.isPosIn(loc))
			return false;

	bool last_antennot[NUM_OF_POSSIBLE_NEIGHBORS];

	if (click == RIGHT)
		shiftRight(last_antennot);
	else shiftLeft(last_antennot);

	for (unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
	{
/*		if (last_antennot[i] == true && _antennot[i] == false && graph[_potentialNeighbors[i]].checkAntenna(i))
			graph.remEdge(_my_index, _potentialNeighbors[i]);

		else if (last_antennot[i] == false && _antennot[i] == true && graph[_potentialNeighbors[i]].checkAntenna(i))
			graph.addEdge(_my_index, _potentialNeighbors[i]); */
	}
	return true;
}

// shift antennot left
void GameNode::shiftLeft(bool last_antennot[]) { shift(last_antennot, NUM_OF_POSSIBLE_NEIGHBORS-1); }
// shift antennot right
void GameNode::shiftRight(bool last_antennot[]) { shift(last_antennot, 1); }

// shift antennot according to shifter
void GameNode::shift(bool last_antennot[], unsigned shifter)
{
	// save 
	for (unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
		last_antennot[i] = _antennot[i];

	// shift
	for (unsigned i = 0; i < NUM_OF_POSSIBLE_NEIGHBORS; i++)
		_antennot[i] = last_antennot[(i+shifter) % NUM_OF_POSSIBLE_NEIGHBORS];
}


void GameNode::draw(sf::RenderWindow& window)
{
	_graphics.draw(window, _antennot);
}
void GameNode::light(sf::RenderWindow& window)
{
	_graphics.light(window);
}

void GameNode::setPotentialNeighbors(int index, int neighbor)
{
	_potentialNeighbors[index] = neighbor;
}