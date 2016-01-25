#include <iostream>
#include <string>
#include <vector>
#include "color.h" // include colors
#include <typeinfo>
#include "hangman.h"
#include <cctype> // used to check if the word/guess is a word
#include <set>
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

int printGuess(vector<char> guess){

	cout << "Current Status: "; 
	int count=0;
	for (int i = 0; i < guess.size() ; i++){
		if (guess[i] == '*'){
			count++;
		}
		cout << BOLDCYAN << guess[i] << " " << RESET;
	}
	cout << endl << "You have " << count << " letters left to guess" << endl << endl;
	return count;
}

int isWord(string word){
	for (int i = 0; i < word.length(); i++){
		if (!isalpha(word[i])){
			return 0;
		}
	}
	return 1;
}

int playHangman() {

	int strikes = 0, playAgain = 0;
	string phrase, tmp, trash;
	char tryAgain;

	//Player enters word for other player to guess
	//Once they confirm their word, player hands over to other player to guess
	while (playAgain == 0){
		cout << "Hello! Let's play hangman!" << endl;

enterWord:	cout << BOLDCYAN << "Enter your word to guess: " << RESET ;
		cin >> phrase;

		if (!isWord(phrase)){
			cout << "Sorry! That is not an acceptable word. Please only include letters in your word." << endl;
			goto enterWord;
		}
		cout << "Your word is : " << BOLDCYAN << phrase << RESET << "." << endl;
		cout << "If that's correct, type 'ready' to clear the screen, then hand the game over to the guesser." << endl << "Otherwise, type anything else." << endl;

		/*
		cout << "Your word is : " << BOLDCYAN << phrase << RESET << ". If that's correct, type 'ready' to clear the screen, then hand the game over to the guesser:  ";
		cin >> tmp;
		*/
		//getline(cin, trash);
		cin >> tmp;
		if (tmp != "ready"){
			goto enterWord;
		}
		clearScreen();
		
		/*
		int ready=0;
		while (ready==0){
			if (tmp.compare("ready") == 0){
				ready = 1;
				clearScreen();
			} else {
				cout << endl << endl << "Oops. Looks like you're not ready! Type 'ready' when you're ready to clear the screen, then hand the game over to the guesser: ";
				cin >> tmp;
			}
		}*/

		//Other Player Begins:
		vector<char> guess, recentChanges, compare, wrongLetters;
		set<char> used;
		//instantiates guess to be "* * * * *.." to match the num of chars of the phrase
		for (int i = 0; i < phrase.length() ; i++){
			guess.push_back('*');
		}
		
		//initial display of man and current status
		displayMan(strikes);
		cout << endl << endl;
		printGuess(guess);
		
		//Time to Guess!
		//ask to enter letter or guess the word
		char letter;
		bool is_in;
		int boo = 0; //if boo is 0, that means the guessed letter is not in the phrase --> increment strikes
		//int isLetter = 0; //0 if the letter entered is not a char, if it is isLetter = 1
		while (strikes < 8){

			//while (isLetter == 0) {
			// checks if the char is a letter
guess:		do{
				cout << "Enter your letter guess: ";
				cin >> letter;
				if (!isalpha(letter)){
					cout << "Sorry, that is not an acceptable letter." << endl;
				}
			} while(!isalpha(letter));

			// checks if the letter has been guessed already
			is_in = used.find(letter) != used.end();
			if (!is_in){
				used.insert(letter);
			} else{
				cout << "You have already guessed that letter!" << endl;
				goto guess;
			}

			//	cout << "Enter your letter: ";
			//	cin >> letter;
				//cout << typeid(letter).name() << endl;
				/*if (typeid(letter).name() == 'c'){
					isLetter = 1;
				}*/
			//}
			//cout << "======================================================================";
			clearScreen();
			//cout << endl << "letter is " << letter << endl;

			for (int i = 0; i < phrase.length() ; i++){
			//cout << "Letter is: " << letter << " and actual is " << phrase[i] << endl;
				if(letter == phrase[i]){
					recentChanges.push_back(phrase[i]);
					boo = 1;
				}
				else{
					recentChanges.push_back('*');
				}
			}

			//increment strikes if didn't hit a match, append letter to wrongLetters vector
			if (boo == 0){
				strikes++; 
				wrongLetters.push_back(letter);
			}

			//update guess to reflect recent changes
			// guess = current guess with past changes
			// recentChanges = vector with recent (if any) changes
			if (boo == 1){
				for (int i = 0; i < guess.size(); i++){
					if (guess[i] != '*'){
						compare.push_back(guess[i]);
					}
					else if (recentChanges[i] != '*'){
						compare.push_back(recentChanges[i]);
					}
					else{
						compare.push_back('*');
					}
				}
				guess=compare;
			}

			compare.clear();
			recentChanges.clear();
			boo=0;
			//cout << "Strikes: " << strikes << endl;
			
			displayMan(strikes);

			//Print out incorrect guesses
			cout << "Previous Incorrect Guesses: ";
			for (int i = 0 ; i < wrongLetters.size() ; i++){
				cout << wrongLetters[i] << " ";
			}
			cout << endl << endl;
			//printGuess(guess);

			if (strikes == 7){				
				cout << "Uh oh. You lost. Try again? (y/n): ";
				cin >> tryAgain;
				if (tryAgain == 'n'){
					cout << "Thanks for playing!" << endl;
					playAgain = 1;
				}
				break;
			}

			if (printGuess(guess) == 0){
				cout << "You guessed the word!! Play again? (y/n): ";
				cin >> tryAgain;
				if (tryAgain == 'n'){
					cout << "Thanks for playing!" << endl;
					playAgain = 1;
				}
				else {clearScreen();}
				break;
			} 
		}
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







