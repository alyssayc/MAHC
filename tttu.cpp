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
     |     |      |      |     |      |    __________
     |     |      |      |     |      |   /          \
_____|_____|_____ | _____|_____|_____ |  /            \ 
     |     |      |      |     |      |  |            | 
     |     |      |      |     |      |  |            | 
_____|_____|_____ | _____|_____|_____ |  |            |
     |     |      |      |     |      |  \            /
     |     |      |      |     |      |   \__________/
     |     |      |      |     |      | 
---------------------------------------------------------
     |     |      |      |     |      |     \       /
     |     |      |      |     |      |      \     /
_____|_____|_____ | _____|_____|_____ |       \   /
     |     |      |      |     |      |        \ / 
     |     |      |      |     |      |         x 
_____|_____|_____ | _____|_____|_____ |        / \
     |     |      |      |     |      |       /   \
     |     |      |      |     |      |      /     \
     |     |      |      |     |      |     /       \

Okay instead of printing the entire board
Ill print the small version of big board
And then Ill print whatever small board they are marking in
and I will give them an image of any small board if they want.

     |     |      
     |     |     
_____|_____|_____
     |     |     
     |     |     
_____|_____|_____
     |     |      
     |     |      
     |     |      

     |     |      
     |     |     
_____|_____|_____
     |     |     
     |     |     
_____|_____|_____
     |     |      
     |     |      
     |     |      

*/


bool gameOverSmallBoard(vector<char> board){ // Returns whether the game is over or not.
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

bool gameOverBigBoard(vector< vector<char> > board, vector<char> X_win, vector<char> O_win){
	for (int i = 0; i < 3; i++){
		if ((board[3 * i] == board[3 * i + 1] && board[3 * i + 1] == board[3 * i + 2]) 
			&& (board[3 * i] == X_win || board[3 * i] == O_win)){
			return true; // If the condition is true, then there is a row that has been completed
		} else if ((board[i] == board[i + 3] && board[i + 3] == board[i + 6])
				&& (board[i] == X_win || board[i] == O_win)){
			return true;
		} 
	}
	// Now check the diagonals
	if (
		(
		(board[0] == X_win || board[0] == O_win) 
		&& (board[0] == board[4] && board[4] == board[8])
		) 
		|| 
		(
		(board[2] == X_win || board[2] == O_win) 
		&& (board[2] == board[4] && board[4] == board[6])
		)
		)
	{
		return true;
	}
	return false;
}
/*
bool gameOverBigBoard(vector< vector<char> > board){
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
}*/

// Not converted
/*
void displayBoard(vector< vector<char> > board){ // Change this to look better and because this is a template.... 
	// First display the first row...

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
}*/

// finished converting

bool checkSpace(vector<char> board, int index){ // returns whether the space is open or not
	if ((board[index] == *"X") || (board[index] == *"O")){
		return false;
	} else{
		return true;
	}
}


int main(){
	// instantiate the small tic tac toe boards;
	vector<char> t_0(9); vector<char> t_1(9); vector<char> t_2(9); 
	vector<char> t_3(9); vector<char> t_4(9); vector<char> t_5(9); 
	vector<char> t_6(9); vector<char> t_7(9); vector<char> t_8(9);
	// Create small tic tac toe boards for when any of them are won with X or O
	vector<char> X_won(9); vector<char> O_won(9);

	// Create the big tic tac toe board
	vector< vector<char> > bigBoard(9, vector<char>(9));

	// Set the values of big tic tac toe board
	bigBoard[0] = t_0; bigBoard[1] = t_1; bigBoard[2] = t_2;
	bigBoard[3] = t_3; bigBoard[4] = t_4; bigBoard[5] = t_5;
	bigBoard[6] = t_6; bigBoard[7] = t_7; bigBoard[8] = t_8;

	// instantiate the values in the small vectors to *" "
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			bigBoard[i][j] = *" ";
		}
	}

	//Welcome
	//Initialize values, enter names
	int bigBoardIndex, smBoardIndex;
	string Player1, Player2, temp;
	cout << "Player 1, please enter a name: ";
	cin >> Player1;
	cout << "Player 2, please enter a name: ";
	cin >> Player2;
	int counter = 0; // Keeps track of which player's turn it is.

	// Begin with selecting indices and marking

	// DISPLAY
	cout << endl << "It is now " << Player1 << "'s turn." << endl;
	cout << "Please choose from the big board, which small board to mark in." << endl;
	// DISPLAY
	cout << "Small Board #";
	cin >> bigBoardIndex;
	// Something about are you sure, you can go back, blah blah
	cout << endl << "Please choose where in Small Board #" << bigBoardIndex << " to mark." << endl;
	cin >> smBoardIndex;
	bigBoard[bigBoardIndex][smBoardIndex] = *"X";
	bigBoardIndex = smBoardIndex;
	do{
		// DISPLAY
		temp = ((counter % 2) == 0) ? Player1 : Player2;
		cout << "It is " << temp << "'s turn. " << endl;
		
		/*
		while (gameOverSmallBoard(bigBoard[bigBoardIndex], bigBoardIndex)){
		*/
		if (bigBoardIndex == -1){
			cout << "Small Board #" << bigBoardIndex << " has been won, please choose another small board." << endl;
			cin >> bigBoardIndex;
		}
		// DISPLAY
		cout << "You are currently viewing Small Board #" << bigBoardIndex << endl;
		//cout << "Would you like to view another small board? (y/n)" ;
		//DISPLAY
		cout << "Please choose where in Small Board #" << bigBoardIndex << " to mark." <<endl;
		cin >> smBoardIndex;
		while (!checkSpace(bigBoard[bigBoardIndex], smBoardIndex)){
			cout << "Sorry, that spot is occupied! Please choose another location: ";
			cin >> smBoardIndex;
		}
		bigBoard[bigBoardIndex][smBoardIndex] = ((counter % 2) == 0) ? *"X" : *"O";
		if (gameOverSmallBoard(bigBoard[bigBoardIndex])){
			bigBoard[bigBoardIndex] = ((counter % 2) == 0) ? X_won : O_won;
			bigBoardIndex = -1; // to reset the index
		} else{
			bigBoardIndex = smBoardIndex;
		}
		counter++;
	} while(!gameOverBigBoard(bigBoard, X_won, O_won));

	/*
	int index;
	string Player1, Player2, temp;
	cout << "Hello there! Welcome to Ultimate Tic Tac Toe!!!!!" << endl                     << "Player 1, please enter a name: ";
	cin >> Player1;
	cout << "Player 2, please enter a name: ";
	cin >> Player2;
	cout << endl << "Currently, it is" << Player1 << "'s turn. " << endl;
	int stttIndex = -1; // Small Tic Tac Toe Index
	// corresponds to which board in bigBoard will be altered
	// maybe add on stuff here like if same name, blah blah would you like a name? blah blah change name keep name blah blah
	int counter = 0; // token to keep track of who's turn it is
	do{
		if (stttIndex == -1 || gameOverSmallBoard(bigBoard[stttIndex])){ // checks if a small board is finished
			cout << "Please choose which small tic tac toe board to mark it." << endl;
			cin >> stttIndex;
			cout << "Please choose where in the small tic tac toe board to mark in." << endl;
			cin >> index;
		} else{
			// display board
			temp = ((counter % 2) == 0) ? Player1 : Player2;
			cout << "It is " << temp << "'s turn. " << endl;
			cout << "Please choose where in the small tic tac toe board to mark in." << endl;
			cin >> index;
		}
		while (!checkSpace(bigBoard[stttIndex], index)){
			cout << "Sorry, that spot is occupied! Please choose another location: ";
			cin index;
		}
		bigBoard[stttIndex][index] = ((counter % 2) == 0) ? *"X" : *"O";
		counter++;
		stttIndex = index;
	} while(!gameOverBigBoard(bigBoard));
	// display board
	if (gameOverBigBoard(bigBoard)){
		cout << "Congratulations! " << temp << " has won!" << endl;
	} else{
		cout << "It's a tie!" << endl;
	}
	*/
	
}










