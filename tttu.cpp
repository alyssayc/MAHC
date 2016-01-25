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

void displayBigBoard(vector< vector<char> > board, vector<char> X_win, vector<char> O_win){

	vector<char> temp(9);
	temp[0] = *"1";
	temp[1] = *"2";
	temp[2] = *"3";
	temp[3] = *"4";
	temp[4] = *"5";
	temp[5] = *"6";
	temp[6] = *"7";
	temp[7] = *"8";
	temp[8] = *"9";
	for (int i = 0; i < 9; i++){
		if (board[i] == X_win){
			temp[i] = *"X";
		} else if (board[i] == O_win){
			temp[i] = *"O";
		}
	}
	cout << "Displaying the big board: " << endl;
	cout << "     |     |     " << endl;
	cout << "  " << temp[0] << "  |  " << temp[1] << "  |  " << temp[2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << temp[3] << "  |  " << temp[4] << "  |  " << temp[5] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << temp[6] << "  |  " << temp[7] << "  |  " << temp[8] << endl;

	cout << "     |     |     " << endl << endl;
}

void displaySmallBoard(vector<char> board, int index){ // Change this to look better and because this is a template.... 
	// First display the first row...
	cout << "Displaying small board #" << index << endl;
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

bool checkSpace(vector<char> board, int index){ // returns whether the space is open or not
	if ((board[index] == *"X") || (board[index] == *"O")){
		return false;
	} else{
		return true;
	}
}


int main(){
	// instantiate the small tic tac toe boards;
beg:cout << "Hello! Would you like to play ultimate tic-tac-toe? (y/n) ";
	string answer;
	cin >> answer;
	int tick = 0;
	// can implement a series of dialogue, an option to go back to games home?
	
	while (answer != "y"){
		if (answer == "n"){
			tick++;
			if (tick < 6){
				cout << "Oh... " << endl << "Would you like to play ultimate tic-tac-toe now? (y/n) ";
			} else{
				cout << "Please?..... (y/n)";
			}
		}
		else {
			cout << "Please enter in the format (y/n)!" << endl;
		}
		cin >> answer;
	}
	vector<char> t_0(9); vector<char> t_1(9); vector<char> t_2(9); 
	vector<char> t_3(9); vector<char> t_4(9); vector<char> t_5(9); 
	vector<char> t_6(9); vector<char> t_7(9); vector<char> t_8(9);
	// Create small tic tac toe boards for when any of them are won with X or O
	vector<char> X_won(9); vector<char> O_won(9);
	for (int i = 0; i < 9; i++){
		O_won[i] = *"o";
	}

	// Create the big tic tac toe board
	vector< vector<char> > bigBoard(9, vector<char>(9));

	// Set the values of big tic tac toe board
	bigBoard[0] = t_0; bigBoard[1] = t_1; bigBoard[2] = t_2;
	bigBoard[3] = t_3; bigBoard[4] = t_4; bigBoard[5] = t_5;
	bigBoard[6] = t_6; bigBoard[7] = t_7; bigBoard[8] = t_8;

	// instantiate the values in the small vectors to *" "
	for (int i = 0; i < 9; i++){
		bigBoard[i][0] = *"1";
		bigBoard[i][1] = *"2";
		bigBoard[i][2] = *"3";
		bigBoard[i][3] = *"4";
		bigBoard[i][4] = *"5";
		bigBoard[i][5] = *"6";
		bigBoard[i][6] = *"7";
		bigBoard[i][7] = *"8";
		bigBoard[i][8] = *"9";
		/*
		for (int j = 0; j < 9; j++){
			bigBoard[i][j] = *" ";
		}*/
	}

	//Welcome
	//Initialize values, enter names
	int bigBoardIndex, smBoardIndex;
	string Player1, Player2, temp;
	cout << "Player 1, please enter a name: ";
	cin >> Player1;//cin >> Player1;
	cout << "Is the name, " << Player1 << ", what you want? (y/n) ";
	cin >> answer;
	while (answer != "y"){
		if (answer != "n"){
			cout << "Please enter in the format (y/n)! " << endl;
		} else {
			cout << "Player 1, please enter a name: ";
			cin >> Player1;
			cout << "Is the name, " << Player1 << ", what you want? (y/n) ";
		}
		cin >> answer;
	}
	cout << "Player 2, please enter a name: ";
	cin >> Player2;//cin >> Player2;
	cout << "Is the name, " << Player2 << ", what you want? (y/n) ";
	cin >> answer;
	while (answer != "y"){
		if (answer != "n"){
			cout << "Please enter in the format (y/n)! " << endl;
		} else {
			cout << "Player 2, please enter a name: ";
			cin >> Player2;
			cout << "Is the name, " << Player2 << ", what you want? (y/n) ";
		}
		cin >> answer;
	}
	cout << endl;
	int counter = 0; // Keeps track of which player's turn it is.

	// Begin with selecting indices and marking

	displayBigBoard(bigBoard, X_won, O_won);
	cout << endl << "It is now " << Player1 << "'s turn." << endl;
	cout << "Please choose from the big board, which small board to mark in." << endl;
	// DISPLAY
	cout << "Small Board #";
	cin >> bigBoardIndex;
	// Something about are you sure, you can go back, blah blah
	displaySmallBoard(bigBoard[bigBoardIndex], bigBoardIndex);
	cout << endl << "Please choose where in Small Board #" << bigBoardIndex << " to mark." << endl;
	cin >> smBoardIndex;
	bigBoard[bigBoardIndex][smBoardIndex] = *"X";
	bigBoardIndex = smBoardIndex;
	counter++;
	do{
		displayBigBoard(bigBoard, X_won, O_won);
		//displaySmallBoard(bigBoard[bigBoardIndex], bigBoardIndex);
		temp = ((counter % 2) == 0) ? Player1 : Player2;
		cout << "It is " << temp<< "'s turn. " << endl;
		
		/*
		while (gameOverSmallBoard(bigBoard[bigBoardIndex], bigBoardIndex)){
		*/
		while (bigBoard[bigBoardIndex] == X_won || bigBoard[bigBoardIndex] == O_won){
			cout << "Small Board #" << bigBoardIndex << " has been won, please choose another small board." << endl;
			cin >> bigBoardIndex;
		}
		displaySmallBoard(bigBoard[bigBoardIndex], bigBoardIndex);
		
		//cout << "You are currently viewing Small Board #" << bigBoardIndex << endl;
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
			//cout << "Setting bigBoardIndex to -1" << endl;
			//bigBoardIndex = -1; // to reset the index
		}
		bigBoardIndex = smBoardIndex;
		counter++;
	} while(!gameOverBigBoard(bigBoard, X_won, O_won));	
	displayBigBoard(bigBoard, X_won, O_won);
	cout << "Congratulations! " << temp << " has won!" << endl;
}










