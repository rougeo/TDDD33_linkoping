#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "trimino.h"

using namespace std;

bool isCorrect(string set) {
	//TODO
	return false;
}

int main(int argc, char* argv[]) {
	string filename; // name of the test file
	vector<string> lines;

	// get the filename from the console or ask for it if not there
	if (argc == 1) {
		while (true) {
			cout << "Please enter a filename: ";
			getline(cin, filename); // get filename from cin
			ifstream filestream(filename.c_str()); // try to open file stream, cast into pointer
			if (filestream) {
				break;
			} else { // if file opening fails, ask for a new file name
				cerr << "Error: could not open file, please try again\n\n";
				cin.clear();
			}
		}
	} else if (argc == 2) {
		filename = argv[1];
		ifstream filestream(filename.c_str()); // try to open file stream, cast into pointer
		if (!filestream) {
			cerr << "Error: could not open file. Exiting ...\n";
		}
	} else {
		cerr << "Incorrect number of arguments. Exiting ...\n";
		return 0;
	}

	// here, we made sure that filestream exists
	// now, we can process this file
	ifstream filestream(filename.c_str());
	for(string line; getline( filestream, line ); )	{
		lines.push_back(line);
	}

	for (vector<string>::iterator i = lines.begin(); i != lines.end(); i++) {
	 	isCorrect(*i);
	}



	return 1;
}