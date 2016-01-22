#include <iostream>
#include <string>
#include <vector>

using namespace std;

// THE BOARD SHOULD BE AN ARRAY OF SIZE 10 (including '\0')
// IT SHOULD VISUALLY LOOK SOMETHING LIKE THIS 
//  	0  1  2
// 		3  4  5
//		6  7  8

bool gameOver(char* board){ // Returns whether the game is over or not.
	// Should be a 3x3 board in this instance
	/*
	if (strlen(board) != 9){
		cout << strlen(board) << endl;
		cout << "Sorry, but I do believe that this is not a standard tic-tac-toe board size! " << endl;
		return true; // should exit the loop
	} */
	// Check win conditions vertically and horizontally
	for (int i = 0; i < 3; i++){
		if ((board[3 * i] == board[3 * i + 1] && board[3 * i + 1] == board[3 * i + 2]) 
			&& (board[3 * i] != *" " && board[3 * i + 1] != *" " && board[3 * i + 2] != *" ")){
			cout << "a" << "i" << endl;
			return true; // If the condition is true, then there is a row that has been completed
		} else if ((board[i] == board[i + 3] && board[i + 3] == board[i + 6])
				&& (board[i] != *" " && board[i + 3] != *" " && board[i + 6] != *" ")){
			cout << "b" << "i" << endl;
			return true;
		} 
	}
	// Now check the diagonals
	if (((board[0] != *" " && board[4] != *" " && board[8] != *" ") && (board[0] == board[4] && board[4] == board[8])) 
		|| ((board[2] != *" " && board[4] != *" " && board[6] != *" ") && (board[2] == board[4] && board[4] == board[6]))){
		cout << "c" << endl;
		return true;
	}
	return false;
}

void displayBoard(char* board){
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

int main(){
	/*
	cout << "Hello! Would you like to play tic-tac-toe? (y/n) ";
	string answer;
	cin >> answer;
	//int counter = 0;
	// can implement a series of dialogue, an option to go back to games home?
	
	while (answer != "y"){
		if (answer == "n"){
			counter++;
			if (counter < 6){}
				cout << "Oh... " << endl << "Would you like to play tic-tac-toe now? (y/n) ";
			}
		}
		else {
			cout << "Please enter in the format (y/n)!" << endl;
		}
		cin >> answer;
	}
	*/
	char spaces[10];
	for (int i = 0; i < 9; i++){
		spaces[i] = *" ";
	}
	int index;
	string Player1, Player2, temp;
	cout << "Player 1, please enter a name: ";
	cin >> Player1;
	cout << "Player 2, please enter a name: ";
	cin >> Player2;
	cout << endl;
	// maybe add on stuff here like if same name, blah blah would you like a name? blah blah change name keep name blah blah
	int counter = 0; // token to keep track of who's turn it is
	do{
		displayBoard(spaces);
		temp = ((counter % 2) == 0) ? Player1 : Player2;
		cout << "It is " << temp << "'s turn. " << endl;
		cout << "Please choose the number corresponding to the square you would like to mark: ";
		cin >> index;
		if (!checkSpace(spaces, index)){
			do{
				cout << "Sorry, that spot is occupied! Please choose another location: ";
				cin >> index;
			} while (!checkSpace(spaces, index));
		} 
		spaces[index] = ((counter % 2) == 0) ? *"X" : *"O";
		counter++;
	} while (!gameOver(spaces));
	displayBoard(spaces);
	cout << "Congratulations! " << temp << " has won!" << endl;
}