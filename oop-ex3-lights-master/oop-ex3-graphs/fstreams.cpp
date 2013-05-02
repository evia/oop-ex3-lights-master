#include "fstreams.h"
#include <iostream>

namespace fstreams
{
	// function gets an ifstream and a filename 
	// and opens it, if it cannot it will send an error and exits.
	void OpenFile(ifstream &fin, char *file)
	{
		fin.open(file);
		if (!fin)
		{
			std::cerr << "Failed to open file : " << file << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}