#include <<algorithm>

using namespace std;

vector<char> leadingJunk {'"', '\'', '('};
vector<char> trailingJunk {'!', '?', ';', ',', ':', '.', '"', '\''}

bool isLeadingJunk(char c) {
  for_each(leadingJunk.begin(), leadingJunk.end(), [](const char c2)) {
    if (c == c2) return true;
  }
  return false;
}

bool isTrailingJunk(char c) {
  for_each(trailingJunk.begin(), trailingJunk.end(), [](const char c2)) {
    if (c == c2) return true;
  }
  return false;
}


void cleanWords(vector<String> &v){
  // remove leading junk
  
}

int main(int argc, char* argv[]) {
  // TODO
  return 0;
	}
