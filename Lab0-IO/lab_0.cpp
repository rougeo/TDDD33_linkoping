#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<limits>

//Complementary comments
//(See assessment protocol for guidance)
//2-7
//4-3
//8-8: When entering a character you need to hit enter twice.
//Also take one more look at the example. The output should be formated
//exactly like in the example.

using namespace std;

int main(){
	int integer;
	float float_number;
	char character;
	string word;
/*
	cout << "Enter one integer: ";
	cin >> integer;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "You entered the number: " << integer << endl;

	cout <<"Enter four integers: ";
	cin >> integer;
	cout << "You entered the numbers: " << integer;
	cin >> integer;
	cout << " " << integer;
	cin >> integer;
	cout << " " << integer;
	cin >> integer;
	cout << " " << integer << endl;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Enter one integer and one real number: ";
	cin >> integer >> float_number;
	cout << setw(18) << left << "The real is: " << setw(15)
		   << right << setprecision(3) << fixed << float_number << endl;
	cout << setw(18) << left << "The integer is: "
			 << setw(15) << right << integer << endl;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Enter one real and one integer number: ";
	cin >> float_number >> integer;
	cout << "The real is:" << setw(18) << right << setfill('.')
			 << setprecision(3) << fixed << float_number << endl;
	cout << "The integer is:" << setw(15) << right << setfill('.')
		   << integer << endl;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
*/
	cout << "Enter a character : ";
	cin >> character;
	cout << "You entered: " << character << endl;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Enter a word: ";
	cin >> word;
	cout << "The word '" << word << "' has " << word.size()
		   << " character(s)" << endl;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Enter an integer and a word: ";
	cin >> integer >> word;
	cout << "You entered '" << integer << "' and '" << word << "'" << endl;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Enter an character and a word: ";
	cin >> character >> word;
	cin.ignore( numeric_limits<streamsize>::max(),'\n');

	cout << "You entered the string '" << word
			 << "' and the character '" << character << "'"
			 << endl;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Enter a word and a real number: ";
	cin >> word >> float_number;
	cout << "You entered '" << word << "' and'" << float_number << "'" << endl;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Enter a text-line: ";
	getline (cin,word);
	cout << "You entered: " << word << endl;
	//cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "Enter a second line of text: ";
	getline (cin,word);
	cout << "You entered: " << word << endl;
	//cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Enter three words: ";
	cin >> word;
	cout << "You entered: " << word;
	cin >> word;
	cout << " " << word;
	cin >> word;
	cout << " " << word << endl;

}
