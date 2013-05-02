#pragma once 
// for simpler use in ifstream

#include <fstream>

using std::ifstream;
// open file opens a file and check the opening was successful
namespace fstreams
{
	void OpenFile(ifstream &fin, char *ifile);
}