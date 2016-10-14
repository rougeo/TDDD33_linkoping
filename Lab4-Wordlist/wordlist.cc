#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

vector<string> load_words(string file){
	stringstream ss;
	string the_split;
	vector<string> v;
	vector<string> lines;
 	vector<string>::iterator it{v.begin()};
	ifstream filestream(file.c_str());
	for(string line; getline( filestream, line ); )	{
    ss << line;
		while (ss >> the_split) {
			 v.push_back(the_split);
			}
			ss.clear();
	}
	return v;
}

void print_vector (vector<string> v){

	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it  << endl;
		}
}



int main(int argc, char* argv[]) {
	string filename; // name of the test file
	vector<string> words;

	if (argc == 1) {
		cerr <<"Error: No arguments given." << endl;
		cerr <<"Usage:"<< argv[0] << " FILE [-a] [-f] [-o N]"<<endl;
			return 0;
	}
	else if (argc == 2) {
		cerr << "Error: Second argument missing or invalid." << endl;
			return 0;
	}
	else
	{
		filename = argv[1];
		ifstream filestream(filename.c_str()); // try to open file stream, cast into pointer
		if (!filestream) {
			cerr << "Error: could not open file. Exiting ...\n";
		return 0;
		}
	}

	words = load_words(argv[1]);
	print_vector(words);

return 1;
}
