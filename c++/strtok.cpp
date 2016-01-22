#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

int main() {
    using namespace std;
    string sentence = "And I feel fine...";
    istringstream iss(sentence);
    vector <string> tokens;
	copy(istream_iterator<string>(iss),
    	istream_iterator<string>(),
    	back_inserter(tokens));
}
