#include "hangman.h"
#include "ttt.h"
#include "tttu.h"
#include "connectFour.h"
#include "color.h"
#include <iostream>

using namespace std;
int main() {
    int game;

    cout << string( 45, '\n' );
    cout << BOLDCYAN;
    choose: cout << " ================================== " << endl;
    cout << " | Hello! Welcome to Game Center! |" << endl; 
    cout << " ================================== " << endl << endl;
    cout << BOLDGREEN << "We have a great selection of games: " << endl << endl;
    cout << "1. Tic Tac Toe            2. Ultimate Tic Tac Toe" << endl;
    cout << "3. Hangman                4. Connect Four" << RESET << endl;
    char readyToPlay, answer;
	cout << endl << BOLDCYAN << "Which game do you want to play today? Enter a number from 1-4: ";
    cin >> game;
    cout << endl;

	switch(game){

		case 1:
			cout << "You chose to play Tic Tac Toe! Ready to play? (y/n): ";
			cin >> readyToPlay;
			if (readyToPlay == 'y'){
				clearScreen();
				playTTT();
				cout << "Would you like to return to the game center? (y/n) ";
				cin >> answer;
				if (answer == 'y'){
					clearScreen();
					goto choose;
				}
			}
			else {clearScreen(); goto choose;}
			break;
		case 2:
			cout << "You chose to play Ultimate Tic Tac Toe! Ready to play? (y/n): ";
			cin >> readyToPlay;
			if (readyToPlay == 'y'){
				clearScreen();
				playTTTU();
				cout << "Would you like to return to the game center? (y/n) ";
				cin >> answer;
				if (answer == 'y'){
					clearScreen();
					goto choose;
				} 
			}
			else {clearScreen(); goto choose;}
			break;
		case 3:
			cout << "You chose to play Hangman! Ready to play? (y/n): ";
			cin >> readyToPlay;
			if (readyToPlay == 'y'){
				clearScreen();
				playHangman();
				cout << "Would you like to return to the game center? (y/n) ";
				cin >> answer;
				if (answer == 'y'){
					clearScreen();
					goto choose;
				}
			}
			else {clearScreen(); goto choose;}
			break;
		case 4:
			cout << "You chose to play Connect Four! Ready to play? (y/n): ";
			cin >> readyToPlay;
			if (readyToPlay == 'y'){
				clearScreen();
				playConnectFour();
				cout << "Would you like to return to the game center? (y/n) ";
				cin >> answer;
				if (answer == 'y'){
					clearScreen();
					goto choose;
				}
			}
			else {clearScreen(); goto choose;}
			break;
		default:
			cout << "!!!" << endl << "Please choose one of the numbers (1, 2, 3, 4)." << endl;
			goto choose;
	}
	clearScreen();
    cout << "=============================" << endl;
	cout << "|   This was Game Center!   |" << endl;
	cout << "|    A project for 6.179    |" << endl;
	cout << "|                           |" << endl;
	cout << "|            By:            |" << endl;
	cout << "|        Alyssa Chen        |" << endl;
	cout << "|             &             |" << endl;
	cout << "|       Mitchell Hwang      |" << endl;
	cout << "|                           |" << endl;
	cout << "| Thank you for playing!!!! |" << endl;
	cout << "=============================" << endl;
}
