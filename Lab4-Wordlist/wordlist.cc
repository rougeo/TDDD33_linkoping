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

void usage_print(string arg){
	cerr <<"Usage:"<< arg << " FILE [-a] [-f] [-o N]"<<endl;
}


void error_print (int i){
	if (i==1) {
		cerr <<"Error: No arguments given." << endl;
	}
	else
	if (i==2)
	 	cerr <<"Error: Second argument missing or invalid." << endl;
	else
	if (i==3)
	{
	 	cerr <<"Error: couldn't open  the given file " << endl;
	 	cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
	}
	else
	if (i==4)
	{
	 	cerr <<"Error: the third parameter must be a number " << endl;
	 	cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
	}
	else
	if (i==5)
	{
		cerr <<"Error: You  must add a number as third parameter " << endl;
		cerr << "Usage: ./a.out FILE [-a] [-f] [-o N]" << endl;
	}

}

bool checkfile( string filename){
	ifstream filestream(filename.c_str()); // try to open file stream, cast into pointer
	if (filestream) {
			return true;
	}
	return false;
}

int main(int argc, char* argv[]) {
	string filename; // name of the test file
	vector<string> words;
  string param;

	if ((argc != 3)&&(argc != 4)) {
			error_print(argc);
			usage_print(argv[0]);
			return 0;
	}
	else if (argc == 3) {
		if(checkfile(argv[1])){
			param = argv[2];
			if (param.compare("-a") == 0)
			{

			}
			else if (param.compare("-f") == 0)
			{

			}
			else if (param.compare("-o") == 0)
			{
				error_print(5);
				return 0;
			}
			else
			{
					error_print(2);
					usage_print(argv[0]);
					return 0;
			}

		}
		else
		{
			error_print(3);
			return 0;
		}
	}
	else /* argc == 4*/
	{
		if(checkfile(argv[1]))
		{
			param = argv[2];
			if (param.compare("-o") == 0)
			{
				param = argv[3];
				if (!(atoi(param.c_str())))
				{
					error_print(4);
					return 0;
				}
			}
			else
			{
				error_print(2);
				return 0;
			}
		}
		else
		{
			error_print(3);
			return 0;
		}
	}

	words = load_words(argv[1]);
	print_vector(words);

return 1;
}
