#include "hangman.h"
//#include "ttt.h"
//#include "tttu.h"
#include "connectFour.h"
#include "color.h"
#include <iostream>

using namespace std;
int main() {
    int game;

    cout << string( 45, '\n' );
    cout << BOLDCYAN;
    cout << " ================================== " << endl;
    cout << " | Hello! Welcome to Game Center! |" << endl; 
    cout << " ================================== " << endl << endl;
    cout << BOLDGREEN << "We have a great selection of games: " << endl << endl;
    cout << "1. Tic Tac Toe            2. Ultimate Tic Tac Toe" << endl;
    cout << "3. Hangman                4. Connect Four" << RESET << endl;
    cout << endl << BOLDCYAN << "Which game do you want to play today? ";
    cin >> game;
    cout << endl;
    char readyToPlay;

	switch(game){

		case 1:
			break;
		case 2:
			break;
		case 3:
			cout << "You chose to play Hangman! Ready to play? (y/n): ";
			cin >> readyToPlay;
			if (readyToPlay == 'y'){
				clearScreen();
				playHangman();
			}
			break;
		case 4:
			cout << "You chose to play Connect Four! Ready to play? (y/n): ";
			cin >> readyToPlay;
			if (readyToPlay == 'y'){
				clearScreen();
				playConnectFour();
			}
			break;
	}

    return 0;
}
