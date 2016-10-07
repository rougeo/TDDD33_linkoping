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

bool clock_increasing(int a, int b, int c){
	if ((a <= b) && (b <= c)) {
		return true;
	}
	if ((b <= c) && (c <= a)) {
		return true;
	}
	if ((c <= a) &&(a <= b)) {
		return true;
	}
	return false;
}


bool isCorrect(string set) {
	stringstream ss;// (stringstream::in | stringstream::out);
	string the_split;
	vector<string> v;
 	vector<string>::iterator it{v.begin()};
	ss << set;
	while(ss >> the_split) {
		v.push_back(the_split);
	} if (v.size() < 3) {
		cerr << "Bad number of parameters " << v.size() << endl;
		return false;
	} else {
		if ( atoi((v.at(0)).c_str()) && atoi((v.at(1)).c_str()) && atoi((v.at(2)).c_str()) ) {

			if (!clock_increasing(stoi(v.at(0)), stoi(v.at(1)), stoi(v.at(2)))) {
				cerr 	<< "The numbers must be clockwise equal or increasing "
				    	<<"starting from the smallest." <<endl;
			 	return false;
			}
		} else {
			cerr << "The three first parameters must be numbers." <<endl;
			return false;
		}
	}
	cout << "This line works" << endl;
	return true;
}
	
#if CONSOLE_FEED == 0
int main(int argc, char* argv[]) {
	string filename; // name of the test file
	vector<string> lines;
	int nb=0;
	bool a;
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


	// for (vector<string>::iterator i = lines.begin(); i != lines.end(); i++) {
	// 	a=isCorrect(*i);
	// 	if(!a)
	// 	cout<< "This error is in the line " << nb+1 <<endl;
	// 	nb++;
	// }
	return 1;
}


#elif CONSOLE_FEED == 1
int main() {
	string line;
	while(true) {
		cout << "Please enter a trimino: " << endl;
		getline(cin, line); // get values
		if(isCorrect(line)) {
			cout << "Trimino is  correct.";
		} else {
			cerr << "Trimino is not correct.";
		}
		cin.clear();
	}

	return 1;
}

#endif

