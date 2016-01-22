#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Something like this....
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
_____|_____|_____ | _____|_____|_____ | _____|_____|_____
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
_____|_____|_____ | _____|_____|_____ | _____|_____|_____
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
---------------------------------------------------------
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
_____|_____|_____ | _____|_____|_____ | _____|_____|_____
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
_____|_____|_____ | _____|_____|_____ | _____|_____|_____
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
---------------------------------------------------------
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
_____|_____|_____ | _____|_____|_____ | _____|_____|_____
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
_____|_____|_____ | _____|_____|_____ | _____|_____|_____
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
     |     |      |      |     |      |      |     |     
*/

// Not converted
bool gameOver(vector<char> board){ // Returns whether the game is over or not.
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

// Not converted
void displayBoard(vector< vector<char> > board){ // Change this to look better and because this is a template.... 
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

// finished converting
bool checkSpace(vector<char> board, int index){ // returns whether the space is open or not
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
	int tick = 0;
	// can implement a series of dialogue, an option to go back to games home?
	
	while (answer != "y"){
		if (answer == "n"){
			tick++;
			if (tick < 6){
				cout << "Oh... " << endl << "Would you like to play tic-tac-toe now? (y/n) ";
			}
		}
		else {
			cout << "Please enter in the format (y/n)!" << endl;
		}
		cin >> answer;
	}
    */


	vector<char> t_0(9); vector<char> t_1(9); vector<char> t_2(9); 
	vector<char> t_3(9); vector<char> t_4(9); vector<char> t_5(9); 
	vector<char> t_6(9); vector<char> t_7(9); vector<char> t_8(9);
	vector< vector<char> > bigBoard(9, vector<char>(9));
	bigBoard[0] = t_0; bigBoard[1] = t_1; bigBoard[2] = t_2;
	bigBoard[3] = t_3; bigBoard[4] = t_4; bigBoard[5] = t_5;
	bigBoard[6] = t_6; bigBoard[7] = t_7; bigBoard[8] = t_8;
	int index;
	string Player1, Player2, temp;
	cout << "Hello there! Welcome to Ultimate Tic Tac Toe!!!!!" << endl << "Player 1, please enter a name: ";
	cin >> Player1;
	cout << "Player 2, please enter a name: ";
	cin >> Player2;
	cout << endl << "Currently, it is" << Player1 << "'s turn. " << endl << "Please choose the number of the small tic-tac-toe board you would like make a move in." << endl;
	int stttIndex; // Small Tic Tac Toe Index
	cin >> stttIndex; // corresponds to which board in bigBoard will be altered
	// maybe add on stuff here like if same name, blah blah would you like a name? blah blah change name keep name blah blah
	int counter = 0; // token to keep track of who's turn it is
	do{
		temp = ((counter % 2) == 0) ? Player1 : Player2;
		cout << "It is " << temp << "'s turn. " << endl;
		cout << "You are marking in small tic tac toe board #" << stttIndex << endl;
		cout << "Please choose the # of the square in this stttb that you want to mark: ";
		cin >> index;
		if (!checkSpace(bigBoard[stttIndex], index)){
			do{
				cout << "Sorry, that spot is occupied! Please choose another location: ";
				cin >> index;
			} while (!checkSpace(bigBoard[stttIndex], index));
		}

	} while (false);
}










