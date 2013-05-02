#pragma once

#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "GameNode.h"
#include "fstreams.h"

class Controller
{
public:
	Controller(ifstream &infd);
	~Controller();
	bool runLevel();
	int search_neighbor(Point point);

private:
	Graph<GameNode>* _board;
	sf::RenderWindow _window;

	void init(ifstream &infd);
	void readLevel(ifstream &infd);
	void createNeighborsLists();
	void createWindow();
	bool handleEvents(const sf::Event& event);

	void draw();
};
