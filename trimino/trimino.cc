#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "trimino.h"

//use preprocessor to chang from file read to console read
#define CONSOLE_FEED  0

using namespace std;

bool isCorrect(string set) {
	//TODO
	return false;
}
#if CONSOLE_FEED == 0
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
			return -1;
		}
	} else {
		cerr << "Incorrect number of arguments. Usage: ./program_name \"filename\" console_feed \n";
		return -1;
	}

	// here, we made sure that filestream exists
	// now, we can process this file and add each element into a vector
	// not checking again, because chance that the file is removed
	// while processing this program is not worth checking
	ifstream filestream(filename.c_str());
	for(string line; getline( filestream, line ); )	{
		lines.push_back(line);
	}

	// iterate through the vector
	for (vector<string>::iterator i = lines.begin(); i != lines.end(); i++) {	
	 	if(!isCorrect(*i)) { // if isCorrect returns false, line is not correct
	 		// print error message. Add 1 to the iterator since it starts at 0
	 		cerr << "In file " << filename << " line " << i + 1 - lines.begin() << ": " << *i << " is not correct." << endl;
	 	}
	}



	return 1;
}

#elif CONSOLE_FEED == 1


#endif