#include <iostream>
#include <string>
#include <vector>
#include "color.h" // include colors

using namespace std;

/*
 
 O 
\|/
 | 
/ \

	_____
	|	|
	|   O
	|  \|/
	|	|
	|  / \
	|
____|______
*/
void displayMan (int num) {

	cout << "	_____" << endl << "	|   |" << endl;

	switch(num)
	{
		case 0 :
			for (int i = 0; i < 4; i++){
				cout << "	|" << endl;
			}
			break;

		case 1 :
			cout << "	|   " << BOLDCYAN << "O" << RESET << endl;
			for (int i = 1; i < 4; i++){
				cout << "	|" << endl;
			}
			break;

		case 2:
			cout << "	|   " << BOLDCYAN << "O" << RESET << endl;
			cout << "	|   " << BOLDCYAN << "| " << RESET << endl;
			for (int i = 2; i < 4; i++){
				cout << "	|" << endl;
			}
			break;

		case 3: 
			cout << "	|   " << BOLDCYAN << "O" << RESET << endl;
			cout << "	|  " << BOLDCYAN << "\\| " << RESET << endl;
			for (int i = 2; i < 4; i++){
				cout << "	|" << endl;
			}
			break;

		case 4:
			cout << "	|   " << BOLDCYAN << "O" << RESET << endl;
			cout << "	|  " << BOLDCYAN << "\\|/" << RESET << endl;
			for (int i = 2; i < 4; i++){
				cout << "	|" << endl;
			}
			break;

		case 5:
			cout << "	|   " << BOLDCYAN << "O" << RESET << endl;
			cout << "	|  " << BOLDCYAN << "\\|/" << RESET << endl;
			cout << "	|   " << BOLDCYAN << "|" << RESET << endl;
			for (int i = 3; i < 4; i++){
				cout << "	|" << endl;
			}
			break;

		case 6:
			cout << "	|   " << BOLDCYAN << "O" << RESET << endl;
			cout << "	|  " << BOLDCYAN << "\\|/" << RESET << endl;
			cout << "	|   " << BOLDCYAN << "|" << RESET << endl;
			cout << "	|  " << BOLDCYAN << "/ " RESET << endl;
			break;

		case 7:
			cout << "	|   " << BOLDCYAN << "O" << RESET << endl;
			cout << "	|  " << BOLDCYAN << "\\|/" << RESET << endl;
			cout << "	|   " << BOLDCYAN << "|" << RESET << endl;
			cout << "	|  " << BOLDCYAN << "/ \\" RESET << endl;
			break;

		default:
			cout << "Uh oh. Something's not right.";

	}

	cout << "	|" << endl << "    ____|______" << endl << endl << endl;

}

void ClearScreen()
    {
    cout << string( 100, '\n' );
    }


int main() {

	int strikes = 0;
	string phrase, tmp;
	vector<char> guess;

	/*cout << "Hello! Let's play hangman!" << endl << BOLDCYAN << "Enter your phrase to guess: " << RESET << endl;
	cin >> phrase;

	cout << "Your phrase is : " << phrase << ". If that's correct, type 'ready' to clear the screen, then hand the game over to the guesser:  ";
	cin >> tmp;

	if (tmp.compare("ready") == 0){
		ClearScreen();
		displayMan(strikes);
	}
	*/=

	for (int i = 0; i < phrase.length() << i++){
		guess.push_back == "_";

	}
	

	//testing comparing chars

	/*phrase = "hi";
	guess.push_back('h');
	if (phrase[0]==guess[0]){
		cout << "yayy" << phrase[0] << endl;
	}
	*/

	return 0;

}







