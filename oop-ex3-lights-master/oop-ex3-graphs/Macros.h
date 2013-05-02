#pragma once

// a point on the screen
struct Point {
	Point() { }
	Point(float x1, float y1) { x = x1; y = y1; }
	float x, y;
};

enum MOUSE_CLICK_TYPE {
	RIGHT = 0,
	LEFT = 1
};


const unsigned WINDOW_W = 800;
const unsigned WINDOW_H = 600;


const unsigned NUM_OF_POSSIBLE_NEIGHBORS = 6;
const unsigned NODE_RADIUS = 10;
const unsigned ANTENNA_WIDTH = 3;
const unsigned EDGE_LENGTH = 20; // the length of an edge.
const unsigned VERTEX_DISTANCE = 40; // this is the space between two vertexes.
const float HEIGHT_DIFFRENCE = float((sqrt(3.0)/2)*EDGE_LENGTH); // the height diffrence between two rows is e.q triangle height.
const float VTX_HEIGHT_HEIGHT_DIFFRENCE = float((sqrt(3.0)/2)*VERTEX_DISTANCE);
const unsigned FIRST_ROW_VTX_NUM = 3;

const char Edge = '0' ;
const char NoEdge = '1' ;
const char space_c = ' ';
const char Newline_c = '\n';

const unsigned EDGE_VAL = 1;
const unsigned NO_EDGE_VAL = 0;

const int NOT_FOUND = -1;

const Point INIT_POINT(250,250);  // the first on the screen


enum NEIGHBOR_NUM {
	FIRST_N = 0,
	SECOND_N = 1,
	THIRD_N = 2,
	FOURTH_N = 3,
	FIFTH_N = 4,
	SIXTH_N = 5
};