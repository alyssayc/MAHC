#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "hangman.h"

using namespace std;

void welcomeDialogue(string gameName){
	cout << "Hello! Would you like to play " << gameName << "? (y/n) ";
	string answer;
	cin >> answer;
	int tick = 0;
	
	while (answer != "y"){
		if (answer == "n"){
			tick++;
			if (tick < 6){
				cout << "Oh... " << endl << "Would you like to play " << gameName << " now? (y/n) ";
			} else if (tick < 10){
				cout << "Please?..... (y/n)";
			} else{
				cout << "Good choice! Let's start " << gameName << endl;
				break;
			}
		}
		else {
			cout << "Please enter in the format (y/n)!" << endl;
		}
		cin >> answer;
	}
}

void initBoard(char* board){
	board[0] = *"1"; board[1] = *"2"; board[2] = *"3";
	board[3] = *"4"; board[4] = *"5"; board[5] = *"6";
	board[6] = *"7"; board[7] = *"8"; board[8] = *"9";
}

void getNames(string &P1, string &P2){
	string player, resp;// holds the string for what player
	// loop through the players
	for (int iterator = 1; iterator < 3; iterator++) {
    	cout << "Player " << iterator << ", please enter a name: ";
    	cin >> player;
    	cout << "Is the name, " << player << ", what you want? (y/n) ";
    	cin >> resp;
    	while (resp != "y"){
			if (resp != "n"){
				cout << "Please enter in the format (y/n)! " << endl;
			} else {	
				cout << "Player " << iterator << ", please enter a name: ";
				cin >> player;
				cout << "Is the name, " << player << ", what you want? (y/n) ";
			}
			cin >> resp;
		}
		if (iterator == 1){
			P1 = player;
		} else if (iterator == 2){
			P2 = player;
		}
	}
}

bool gameOver(char* board){ // Returns whether the game is over or not.
	for (int i = 0; i < 3; i++){
		if ((board[3 * i] == board[3 * i + 1] && board[3 * i + 1] == board[3 * i + 2]) 
			&& (board[3 * i] != *" " && board[3 * i + 1] != *" " && board[3 * i + 2] != *" ")){
			return true; // If the condition is true, then there is a row that has been completed
		} else if ((board[i] == board[i + 3] && board[i + 3] == board[i + 6])
				&& (board[i] != *" " && board[i + 3] != *" " && board[i + 6] != *" ")){
			return true;
		} 
	}
	// Now check the diagonals
	if (((board[0] != *" " && board[4] != *" " && board[8] != *" ") && (board[0] == board[4] && board[4] == board[8])) 
		|| ((board[2] != *" " && board[4] != *" " && board[6] != *" ") && (board[2] == board[4] && board[4] == board[6]))){
		return true;
	}
	return false;
}

void displayTTT(char* board){ // Change this to look better and because this is a template.... 
	cout << "     |     |     " << endl;
	cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;

	cout << "     |     |     " << endl << endl;
	// Displays the current board... 
	// Can implement color maybe....
}

bool checkSpace(char* board, int index){ // returns whether the space is open or not
	if ((board[index] == *"X") || (board[index] == *"O")){
		return false;
	} else{
		return true;
	}
}

void fillBoard(string P1, string P2, char* board){
	int counter = 0; // token to keep track of who's turn it is
	int catsGame = 0;
	int index;
	string temp;
	do{
		clearScreen();
		displayTTT(board);
		temp = ((counter % 2) == 0) ? P1 : P2;
		cout << "It is " << temp << "'s turn. " << endl;
		cout << "Please choose the number corresponding to the square you would like to mark: ";
num:	cin >> index;
		while (index > 9 || index < 1){
			cout << "Please choose a number from 1-9 corresponding to the square you want to mark: ";
			cin >> index;
		}
		while (!checkSpace(board, index - 1)){
			cout << "Sorry, that spot is occupied! Please choose another location: ";
			goto num;
		} 
		board[index - 1] = ((counter % 2) == 0) ? *"X" : *"O";
		counter++; catsGame++;
	} while (!gameOver(board) && catsGame < 9);

	clearScreen();
	displayTTT(board);
	if (gameOver(board)){
		cout << "Congratulations! " << temp << " has won!" << endl;
	} else{
		cout << "It's a tie!" << endl;
	}
}

void playAgain();

int playTTT(){
	string game = "tic-tac-toe";
	welcomeDialogue(game);
	string Player1, Player2;
	char spaces[10];
	initBoard(spaces);
	getNames(Player1, Player2);
	fillBoard(Player1, Player2, spaces);
	playAgain();
	return 0;
}

void playAgain(){
	cout << "Would you like to play again? (y/n)" << endl << "only (y) will let you play again :^)" << endl;
	string answer;
	cin >> answer;
	if (answer == "y"){
		clearScreen();
		playTTT();
	}
}

