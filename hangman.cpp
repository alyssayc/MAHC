#include <iostream>
#include <string>
#include <vector>
#include "color.h" // include colors

using namespace std;

/*
 
 This is the display: 7 strikes/outs


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

void clearScreen(){

    cout << string( 50, '\n' );
}


void printGuess(vector<char> guess){

	cout << "Current Status: "; 
	int count=0;
	for (int i = 0; i < guess.size() ; i++){
		if (guess[i] == '*'){
			count++;
		}
		cout << BOLDCYAN << guess[i] << " " << RESET;
	}
	cout << endl << "You have " << count << " letters left to guess" << endl << endl;
}


int main() {

	int strikes = 0;
	string phrase, tmp;

	//Player enters word for other player to guess
	//Once they confirm their word, player hands over to other player to guess
	cout << "Hello! Let's play hangman!" << endl << BOLDCYAN << "Enter your phrase to guess: " << RESET ;
	getline(cin, phrase);

	cout << "Your phrase is : " << phrase << ". If that's correct, type 'ready' to clear the screen, then hand the game over to the guesser:  ";
	cin >> tmp;

	if (tmp.compare("ready") == 0){
		clearScreen();
	}


	//Other Player Begins:
	vector<char> guess, tmp2;

	for (int i = 0; i < phrase.length() ; i++){
		guess.push_back('*');
	}
	
	displayMan(strikes);
	printGuess(guess);
	
	//Time to Guess!
	//ask to enter letter or guess the word
	char letter;
	cout << "Enter your letter: ";
	cin >> letter;
	cout << endl << "letter is " << letter << endl;

	for (int i = 0; i < phrase.length() ; i++){
		cout << "Letter is: " << letter << " and actual is " << phrase[i] << endl;
		if(letter == phrase[i]){
			tmp2.push_back(phrase[i]);
		}
		else{
			tmp2.push_back('*');
		}
	}

	guess=tmp2;

	printGuess(guess);
	//testing comparing chars

	/*phrase = "hi";
	guess.push_back('h');
	if (phrase[0]==guess[0]){
		cout << "yayy" << phrase[0] << endl;
	}
	*/

	return 0;

}







