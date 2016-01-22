#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	string line;
	cout << "Please enter a string: ";
	getline(cin, line);
	cout << "You have entered: " << line << endl;
	int line2;
	int total;
	cout << "Please enter a string: ";
	cin >> line2;
	total += line2;
	cout << "You have entered: " << line2 << endl;
	cin >> line2;
	total += line2;
	cout << "You have entered: " << line2 << endl;
	cin >> line2;
	total += line2;
	cout << "You have entered: " << line2 << endl;
	cout << "The total is: " << total << endl;
}