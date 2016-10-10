#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include "trimino.h"
using namespace std;


int max_find(int a, int b) {
	if (a >= b) {
		return a;
	}
	return b;
}

int min_find(int a, int b) {
	if (a <= b) {
		return a;
	}
	return b;
}


bool clock_increasing(int a, int b, int c) {
	if ((a <= b) && (b <= c)) {
		return true;
	}
	if ((b <= c) && (c <= a)) {
		return true;
	}
	if ((c <= a) && (a <= b)) {
		return true;
	}
	return false;
}

bool isCorrect(string set, int min_v, int max_v) {
	stringstream ss;
	string the_split;
	vector<string> v;
 	vector<string>::iterator it{v.begin()};
	ss << set;
	while (ss >> the_split) {
			v.push_back(the_split);
		}
		if(v.size() < 3) {
			cerr << "\t(Reason: bad number of parameters)\n" << v.size()<< endl;
			return false;
		} else {
			if ((atoi((v.at(0)).c_str())) && (atoi((v.at(1)).c_str()))
																	&& (atoi((v.at(2)).c_str()))) {
				if (!clock_increasing(stoi(v.at(0)), stoi(v.at(1)), stoi(v.at(2)))) {
						cerr << "\t(Reason: The numbers must be clockwise equal or increasing "
						     <<"starting from the smallest)\n" <<endl;
								 return false;
				}

				if (min_v > min_find(min_find(stoi(v.at(0)), stoi(v.at(1))), stoi(v.at(2)))
				      || max_v < max_find(max_find(stoi(v.at(0)), stoi(v.at(1))), stoi(v.at(2)))) {
								cerr << "\t(Reason: bad range)\n" << endl;
					return false;
				}
			}	else {
				cerr << "\t(Reason: the three first parameters must be numbers)\n" << endl;
				return false;
			}
		}
			cout << "Line working" << endl;
			return true;
}

int main(int argc, char* argv[]) {
	string filename; // name of the test file
	vector<string> lines;
	int nb=0, min_value, max_value;
	bool a;
	// get the filename from the console or ask for it if not there
	if (argc == 1) {
		while (true) {
			cout << "Please enter a filename: ";
			getline(cin, filename); // get filename from cin
			ifstream filestream(filename.c_str()); // try to open file stream, cast into pointer
			if (filestream) {
				cout << "Please give the min value " <<endl;
				cin >>min_value;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				cout << "Please give the max value " <<endl;
				cin >>max_value;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				break;
			} else { // if file opening fails, ask for a new file name
				cerr << "Error: could not open file, please try again\n\n";
				cin.clear();
			}
		}
	} else if (argc == 2) {
		filename = argv[1];
		ifstream filestream(filename.c_str()); // try to open file stream, cast into pointer
		if (filestream) {
			cout << "Please give the min value " <<endl;
			cin >>min_value;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cout << "Please give the max value " <<endl;
			cin >>max_value;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
		}	else {
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
		a=isCorrect(*i, min_value, max_value);
		if(!a) {
			cout << "In file " << filename << ": error line " << i + 1 - lines.begin() << endl;
		}
	}
	return 1;
}
