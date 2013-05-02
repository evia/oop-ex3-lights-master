#include "Controller.h"
#include <SFML\Graphics.hpp>
#include "fstreams.h"

int main()
{
	ifstream infd; // in file stream
	fstreams::OpenFile(infd, "board.txt"); // oepn board

	int num_of_levels = 0;
	//infd >> num_of_levels; // get num of levels

	bool completed = true; // has the player completed the level?
	
	//for ( int level = 0; level < num_of_levels && completed && !infd.eof(); level++)
	//{
		Controller ctrl(infd);
		//ctrl.runLevel();
	//}

	return EXIT_SUCCESS;
}