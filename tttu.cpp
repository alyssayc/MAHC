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


*/

void welcomeDialogueUlt(string gameName){
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

void initSmallBoards(vector< vector<char> > &board){
	for (int i = 0; i < 9; i++){
		board[i][0] = *"1"; board[i][1] = *"2"; board[i][2] = *"3";
		board[i][3] = *"4"; board[i][4] = *"5"; board[i][5] = *"6";
		board[i][6] = *"7"; board[i][7] = *"8"; board[i][8] = *"9";
	}	
}

void getNamesUlt(string &P1, string &P2){
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
			cout << "What?" << endl;
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
	cout << "Displaying small board #" << index + 1 << endl;
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

void displayBoard(vector< vector<char> > board){
	cout << "Displaying the board." << endl;
	cout << "     |     |      |      |     |      |      |     |" << endl;
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "   |   " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "   |   " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
	cout << "_____|_____|_____ | _____|_____|_____ | _____|_____|_____" << endl;
	cout << "     |     |      |      |     |      |      |     |" << endl;
	cout << "  " << board[0][3] << "  |  " << board[0][4] << "  |  " << board[0][5] << "   |   " << board[1][3] << "  |  " << board[1][4] << "  |  " << board[1][5] << "   |   " << board[2][3] << "  |  " << board[2][4] << "  |  " << board[2][5] << endl;
	cout << "_____|_____|_____ | _____|_____|_____ | _____|_____|_____" << endl;
	cout << "     |     |      |      |     |      |      |     |" << endl;	
	cout << "  " << board[0][6] << "  |  " << board[0][7] << "  |  " << board[0][8] << "   |   " << board[1][6] << "  |  " << board[1][7] << "  |  " << board[1][8] << "   |   " << board[2][6] << "  |  " << board[2][7] << "  |  " << board[2][8] << endl;
	cout << "     |     |      |      |     |      |      |     |     " << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "     |     |      |      |     |      |      |     |" << endl;
	cout << "  " << board[3][0] << "  |  " << board[3][1] << "  |  " << board[3][2] << "   |   " << board[4][0] << "  |  " << board[4][1] << "  |  " << board[4][2] << "   |   " << board[5][0] << "  |  " << board[5][1] << "  |  " << board[5][2] << endl;
	cout << "_____|_____|_____ | _____|_____|_____ | _____|_____|_____" << endl;
	cout << "     |     |      |      |     |      |      |     |" << endl;
	cout << "  " << board[3][3] << "  |  " << board[3][4] << "  |  " << board[3][5] << "   |   " << board[4][3] << "  |  " << board[4][4] << "  |  " << board[4][5] << "   |   " << board[5][3] << "  |  " << board[5][4] << "  |  " << board[5][5] << endl;
	cout << "_____|_____|_____ | _____|_____|_____ | _____|_____|_____" << endl;
	cout << "     |     |      |      |     |      |      |     |" << endl;	
	cout << "  " << board[3][6] << "  |  " << board[3][7] << "  |  " << board[3][8] << "   |   " << board[4][6] << "  |  " << board[4][7] << "  |  " << board[4][8] << "   |   " << board[5][6] << "  |  " << board[5][7] << "  |  " << board[5][8] << endl;
	cout << "     |     |      |      |     |      |      |     |     " << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "     |     |      |      |     |      |      |     |" << endl;
	cout << "  " << board[6][0] << "  |  " << board[6][1] << "  |  " << board[6][2] << "   |   " << board[7][0] << "  |  " << board[7][1] << "  |  " << board[7][2] << "   |   " << board[8][0] << "  |  " << board[8][1] << "  |  " << board[8][2] << endl;
	cout << "_____|_____|_____ | _____|_____|_____ | _____|_____|_____" << endl;
	cout << "     |     |      |      |     |      |      |     |" << endl;
	cout << "  " << board[6][3] << "  |  " << board[6][4] << "  |  " << board[6][5] << "   |   " << board[7][3] << "  |  " << board[7][4] << "  |  " << board[7][5] << "   |   " << board[8][3] << "  |  " << board[8][4] << "  |  " << board[8][5] << endl;
	cout << "_____|_____|_____ | _____|_____|_____ | _____|_____|_____" << endl;
	cout << "     |     |      |      |     |      |      |     |" << endl;	
	cout << "  " << board[6][6] << "  |  " << board[6][7] << "  |  " << board[6][8] << "   |   " << board[7][6] << "  |  " << board[7][7] << "  |  " << board[7][8] << "   |   " << board[8][6] << "  |  " << board[8][7] << "  |  " << board[8][8] << endl;
	cout << "     |     |      |      |     |      |      |     |     " << endl << endl;
/*
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
*/
}

bool checkSpaceUltimate(vector<char> board, int index){ // returns whether the space is open or not
	if ((board[index] == *"X") || (board[index] == *"O")){
		return false;
	} else{
		return true;
	}
}

void fillBoard(string P1, string P2, vector< vector<char> > board, vector<char> X, vector<char> O){
	int counter = 0;
	int catsGame = 0;
	int bigBoardIndex, smBoardIndex;
	string temp;
	displayBigBoard(board, X, O);
	cout << endl << "It is now " << P1 << "'s turn." << endl;
	cout << "Please choose from the big board, which small board to mark in." << endl;
	// DISPLAY
	cout << "Small Board #";
	cin >> bigBoardIndex;
	bigBoardIndex--;
	// Something about are you sure, you can go back, blah blah
	displayBoard(board);
	displaySmallBoard(board[bigBoardIndex], bigBoardIndex);
	cout << endl << "Please choose where in Small Board #" << bigBoardIndex + 1 << " to mark." << endl;
	cin >> smBoardIndex;
	smBoardIndex--;
	board[bigBoardIndex][smBoardIndex] = *"X";
	bigBoardIndex = smBoardIndex;
	counter++;
	do{
		//displayBigBoard(board, X, O);
		displayBoard(board);
		temp = ((counter % 2) == 0) ? P1 : P2;
		cout << "It is " << temp << "'s turn. " << endl;
		while (board[bigBoardIndex] == X || board[bigBoardIndex] == O){
			cout << "Small Board #" << bigBoardIndex + 1 << " has been won, please choose another small board." << endl;
			cin >> bigBoardIndex;
			bigBoardIndex--;
		}
		displaySmallBoard(board[bigBoardIndex], bigBoardIndex);
		cout << "Please choose where in Small Board #" << bigBoardIndex + 1 << " to mark." <<endl;
		cin >> smBoardIndex;
		smBoardIndex--;
		while (!checkSpaceUltimate(board[bigBoardIndex], smBoardIndex)){
			cout << "Sorry, that spot is occupied! Please choose another location: ";
			cin >> smBoardIndex;
			smBoardIndex--;
		}
		board[bigBoardIndex][smBoardIndex] = ((counter % 2) == 0) ? *"X" : *"O";
		if (gameOverSmallBoard(board[bigBoardIndex])){
			board[bigBoardIndex] = ((counter % 2) == 0) ? X : O;
			displayBigBoard(board, X, O);
		}
		bigBoardIndex = smBoardIndex;
		counter++;
	} while(!gameOverBigBoard(board, X, O));	
	displayBigBoard(board, X, O);
	cout << "Congratulations! " << temp << " has won!" << endl;
}

void playAgainUlt();

int playTTTU(){
	string game = "ultimate tic-tac-toe";
	welcomeDialogueUlt(game);

	// Initialize small board vectors
	vector<char> t_0(9); vector<char> t_1(9); vector<char> t_2(9); 
	vector<char> t_3(9); vector<char> t_4(9); vector<char> t_5(9); 
	vector<char> t_6(9); vector<char> t_7(9); vector<char> t_8(9);
	vector<char> X_won(9, *"x"); vector<char> O_won(9, *"o");
	vector< vector<char> > bigBoard(9, vector<char>(9));
	bigBoard[0] = t_0; bigBoard[1] = t_1; bigBoard[2] = t_2;
	bigBoard[3] = t_3; bigBoard[4] = t_4; bigBoard[5] = t_5;
	bigBoard[6] = t_6; bigBoard[7] = t_7; bigBoard[8] = t_8;
	initSmallBoards(bigBoard);
	string Player1, Player2;
	getNamesUlt(Player1, Player2);
	fillBoard(Player1, Player2, bigBoard, X_won, O_won);
	playAgainUlt();
	return 0;
}

void playAgainUlt(){
	cout << "Would you like to play again? (y/n)" << endl << "only (y) will let you play again :^)" << endl;
	string answer;
	cin >> answer;
	if (answer == "y"){
		playTTTU();
	}
}










