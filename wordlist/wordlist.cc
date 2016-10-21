#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <map>
#include <iomanip>

using namespace std;

vector<char> leadingJunk {'"', '\'', '('};
vector<char> trailingJunk {'!', '?', ';', ',', ':', '.', '"', '\''};
vector<string> wordList{"Mathieuestunfaggot", "blbl\"\"", "works", "works"};
vector<string> validWords;
map<string, int> frequencies;
int max_length = 0;


void printPair(const pair<string, int> &p) {
  cout << p.first << " " << setw(max_length - p.first.length() + 1) << p.second << endl;
}



string cleanWord(string &word) {
  vector<char>::iterator it;
  //cout << word << endl;
  it = find(leadingJunk.begin(), leadingJunk.end(), word.at(0));
  if (it != leadingJunk.end()) {
    word.erase(0, 1);
  }
  //cout << word << endl;

  it = find(trailingJunk.begin(), trailingJunk.end(), word.back());
  if (it != trailingJunk.end()) {
    word.pop_back();
  }
  //cout << word << endl;

  // remove 's if length is at least 2 to avoid out of range exceptions
  if (word.length() >= 2) {
    //cout << "blblbl";
    if (word.back() == 's') {
      if (word.at(word.length() - 2) == '\'') {
        word.pop_back();
        word.pop_back();
      }
    }
  }
  //cout << word << endl;
  return word;
}

void validWord(string word) {
  string::iterator it = word.begin();
  int doublehyphens = 1;
  // check that characters are a-z 0-9 A-Z and hyphens
  if (regex_match(word, regex("^[A-Za-z0-9-]+"))) {
    // first and alst char not hyphens
    if ((word.at(0) != '-') && (word.back() != '-')) {
      //cout << word << endl;
      while ((it = adjacent_find(it, word.end())) != word.end()) {
        char currentVal = *it;
        while (it != word.end() && *it == currentVal) {
          if (*it == '-') doublehyphens = 0;
          if (it < word.end())  ++it;
        }
      }
      // doublehyphens = 1 <=> no adjacent hyphens
      if (doublehyphens == 1) {
        // check length at least 3
        if (word.length() >= 3) {
          // word is valid, add it to valid words
          validWords.push_back(word);
          //cout << word << " added" << endl;
        }
      }
    }
  }
}

// -a (1/3)
void alphabetic_increasing(string word) {
  map<string, int>::iterator it;
  it = frequencies.find(word);
  if (word.length() > max_length) max_length = word.length();
  // if element was not present
  if (it == frequencies.end()) frequencies[word] = 1;
  else {
    // get old value
    int old_value = frequencies.find(word)->second;
    frequencies[word] = old_value + 1;
  }
}

// -o 3/3
void printSameOrder(string word, int N, int current_size) {
  // length + 1 because of the space after the words
  if (current_size + word.length() + 1 >= N) {
    cout << "\n" << word << " ";
    current_size = 0;
  } else {
    cout << word << " ";
  }
}


int main(int argc, char* argv[]) {
  int current_size = 0;
  int N;
  //first, clean the words
  for_each(wordList.begin(), wordList.end(), cleanWord);
  // cout << wordList.at(0) << endl;
  // cout << wordList.at(1) << endl;
  // cout << wordList.at(2) << endl;

  // get the valid words, put them into a new vector
  for_each(wordList.begin(), wordList.end(), validWord);
  // cout << validWords.at(0) << endl;
  // cout << validWords.at(1) << endl;

  // map for -a
  for_each(validWords.begin(), validWords.end(), alphabetic_increasing);

  // print -a
  //for_each(frequencies.begin(), frequencies.end(), printPair);

  /* print in decreasing frequency 2/3 */
  vector<pair<string, int>> decreasing_values(frequencies.begin(), frequencies.end());

  // Sort the vector according to the word count in descending order.
  sort(decreasing_values.begin(), decreasing_values.end(),
          [](const pair<string, int> &one, const pair<string, int> &two) {
            return one.second > two.second;});

  // print decreasing values
  // for_each(decreasing_values.begin(), decreasing_values.end(), printPair);
  for_each(validWords.begin(), validWords.end(),
          [&](string word) {
            printSameOrder(word, 30, current_size);
          });
  cout << "\n";

  return 0;
	}
