#include "color.h"
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

/* DISPLAY CONNECT FOUR BOARD

_______________
|_|_|_|_|_|_|_| 5
|_|_|_|_|_|_|_| 4
|_|_|_|_|_|_|_| 3
|_|_|_|_|_|_|_| 2
|_|_|_|_|_|_|_| 1
|_|_|_|_|_|_|_| 0
 a b c d e f g
 0 1 2 3 4 5 6 --> vectorList index 

*/

void displayBoard(vector< vector<int> >& board){
	cout << "_______________";

	for (int i = 5; i >=0; i--){
		cout << endl;

		for (int index = 0; index < board.size(); index++){
			if (i < board[index].size()){ //chips exist
				if (board[index][i] == 1){ //Player 1 --> RED
					//cout << "Index: " << index << "i is: " << i >> endl;
					cout <<  "|" << BRED << "_" << RESET;
				}
				else{ //Player 2 --> YELLOW
					cout << "|" << BYELLOW << "_" << RESET;
				}
			}
			else{	//empty space in the board / no chips
				cout << "|_";
			}
		}
		cout << "|";
	}

	cout << endl << " a b c d e f g" << endl;
	
}

int updateBoard(vector< vector<int> >& board, char input, int player){
	//TAKES A INPUT OF WHAT COLUMN TO PLACE THE CHIP AND UPDATES THE VECTOR
	int tmp = 0;
	switch(input){

			case 'a':
				if (board[0].size() == 6){
					tmp = 1;
					break;
				}
				board[0].push_back(player);
				break;
			case 'b':
				if (board[1].size() == 6){
					tmp = 1;
					break;
				}
				board[1].push_back(player);
				break;
			case 'c':
				if (board[2].size() == 6){
					tmp = 1;
					break;
				}
				board[2].push_back(player);
				break;
			case 'd':
				if (board[3].size() == 6){
					tmp = 1;
					break;
				}
				board[3].push_back(player);
				break;
			case 'e':
				if (board[4].size() == 6){
					tmp = 1;
					break;
				}
				board[4].push_back(player);
				break;
			case 'f':
				if (board[5].size() == 6){
					tmp = 1;
					break;
				}
				board[5].push_back(player);
				break;
			case 'g':
				if (board[6].size() == 6){
					tmp = 1;
					break;
				}
				board[6].push_back(player);

		}

	if (tmp == 1){
		cout << "You can't add another chip here. Try again." << endl;
		return 1;
	}
	return 0;
}

int checkVertical(vector< vector<int> >& board, char input, int player){
	
	vector<int> test;
	player = (player == 1) ? 2 : 1;
	//cout << "Checking vertical" << endl;
	switch(input){

			case 'a':
				test = board[0];
				break;
			case 'b':
				test = board[1];
				break;
			case 'c':
				test = board[2];
				break;
			case 'd':
				test = board[3];
				break;
			case 'e':
				test = board[4];
				break;
			case 'f':
				test = board[5];
				break;
			case 'g':
				test = board[6];

		}

	//cout << "1. " << test[test.size()-1] << " 2. " << test[test.size()-2] << " 3. " << test[test.size()-3] << " 4. " << test[test.size()-4] << "Player" << player << endl;
	if ((test[test.size()-1] == player) && (test[test.size()-2] == player) && (test[test.size()-3] == player) && (test[test.size()-4] == player)){
		if (player == 1) {
			cout << BRED << "Player " << player << " wins!" << RESET << endl;
		}
		else{
			cout << BYELLOW << "Player " << player << " wins!" << RESET << endl;
		}
		return player;
	}		
	return 0;
}

int checkHorizontal(vector< vector<int> >& board, char input, int player){

	vector<int> test;
	player = (player == 1) ? 2 : 1;
	//cout << "Checking horizontal" << endl;
	switch(input){

			case 'a':
				test = board[0];
				break;
			case 'b':
				test = board[1];
				break;
			case 'c':
				test = board[2];
				break;
			case 'd':
				test = board[3];
				break;
			case 'e':
				test = board[4];
				break;
			case 'f':
				test = board[5];
				break;
			case 'g':
				test = board[6];

	}
	
	//find the row of most recent input
	unsigned long int row;
	//cout << "TYPE IS: " << typeid(test.size()).name() << endl; 
	//row = test.size() - 1 returned a segfault
	row = test.size();
	int tmp = row-1;

	//find the leftmost chip of this player
	for (int i = 0; i < 7; i++){
		if (board[i].size() >= row){
			if (board[i][tmp] == player){
				//check if the next three right chips are from the same player
				if ((board[i+1].size() >= row) && (board[i+2].size() >= row) && (board[i+3].size() >= row)){
					if ((board[i+1][tmp] == player) &&  (board[i+2][tmp] == player) && (board[i+3][tmp] == player)){
						if (player == 1) {
							cout << BRED << "Player " << player << " wins!" << RESET << endl;
						}
						else{
							cout << BYELLOW << "Player " << player << " wins!" << RESET << endl;
						}
						return player;
					}
				}
			}
		}
	}
	return 0;
}

int checkDiagonal(vector< vector<int> >& board, char input, int player){

	vector<int> test;
	int col, inpCol, index, count=0;
	player = (player == 1) ? 2 : 1;
	//cout << "Checking diagonal" << endl;
	switch(input){

			case 'a':
				test = board[0];
				inpCol = 0;
				break;
			case 'b':
				test = board[1];
				inpCol = 1;
				break;
			case 'c':
				test = board[2];
				inpCol = 2;
				break;
			case 'd':
				test = board[3];
				inpCol = 3;
				break;
			case 'e':
				test = board[4];
				inpCol = 4;
				break;
			case 'f':
				test = board[5];
				inpCol = 5;
				break;
			case 'g':
				test = board[6];
				inpCol = 6;

	}

	//test left diagonal /
	col = inpCol-1;
	index = test.size()-1;
	//cout << "This is col: " << col << endl;
	//cout << "This is index: " << index << endl;
	while ((col >= 0) && (board[col].size()>index-1)){
		//cout << "Passed first check. Printing board[col].size(): " << board[col].size() - 1 << endl;
		if (board[col][index-1] == player){
			//cout << "Match!" << endl;
			count ++;
			col --;
			index --;
			if (count == 3) { // if there is a diagonal
				if (player == 1) {
						cout << BRED << "Player " << player << " wins!" << RESET << endl;
				}
				else {
						cout << BYELLOW << "Player " << player << " wins!" << RESET << endl;
				}
				return player;
			}
		}
		else {
			//cout << "No Match!" << endl;
			break;
		}
	}

	col = inpCol+1;
	index = test.size()-1;
	while ((col < 7) && (board[col].size()>index)){
		//cout << "Passed first check. Printing board[col].size(): " << board[col].size() - 1 << endl;
		if (board[col][index+1] == player){
			//cout << "Match!" << endl;
			count ++;
			col ++;
			index ++;
			if (count == 3) { // if there is a diagonal
				if (player == 1) {
						cout << BRED << "Player " << player << " wins!" << RESET << endl;
				}
				else {
						cout << BYELLOW << "Player " << player << " wins!" << RESET << endl;
				}
				return player;
			}
		}
		else {
			//cout << "No Match!" << endl;
			break;
		}
	}

	//check right diagonal
	col = inpCol-1;
	index = test.size()-1;
	//cout << "This is col: " << col << endl;
	//cout << "This is index: " << index << endl;
	while ((col >= 0) && (board[col].size()>index+1)){
		//cout << "Passed first check. Printing board[col].size(): " << board[col].size() - 1 << endl;
		if (board[col][index+1] == player){
			//cout << "Match!" << endl;
			count ++;
			col --;
			index ++;
			if (count == 3) { // if there is a diagonal
				if (player == 1) {
						cout << BRED << "Player " << player << " wins!" << RESET << endl;
				}
				else {
						cout << BYELLOW << "Player " << player << " wins!" << RESET << endl;
				}
				return player;
			}
		}
		else {
			//cout << "No Match!" << endl;
			break;
		}
	}
	//cout << "TEST" << endl;
	col = inpCol+1;
	index = test.size()-1;
	//cout << "Col: " << col << " Index: " << index << endl;
	while ((col < 7) && (board[col].size()>index-1 && (index-1)>=0)){
		//cout << "Passed first check. Printing board[col].size(): " << board[col].size()<< endl;
		if (board[col][index-1] == player){
			//cout << "Match!" << endl;
			count ++;
			col ++;
			index --;
			if (count == 3) { // if there is a diagonal
				if (player == 1) {
						cout << BRED << "Player " << player << " wins!" << RESET << endl;
				}
				else {
						cout << BYELLOW << "Player " << player << " wins!" << RESET << endl;
				}
				return player;
			}
		}
		else {
			//cout << "No Match!" << endl;
			break;
		}
	}

	return 0;

}


void clearScreen2(){

    cout << string( 45, '\n' );
}

int playConnectFour(){

	vector<int> a, b, c, d, e, f, g;

	//populate columns into an array of the vectors
	vector< vector<int> > columns;
	columns.push_back(a);
	columns.push_back(b);
	columns.push_back(c);
	columns.push_back(d);
	columns.push_back(e);
	columns.push_back(f);
	columns.push_back(g);

	int player = 1; //starts with Player 1

	//INITIAL DISPLAY
	cout << endl << BOLDCYAN << "Connect Four" << RESET << endl;
	cout << "_______________" << endl;
	cout << "|_|_|_|_|_|_|_| 5" << endl;
	cout << "|_|_|_|_|_|_|_| 4" << endl;
	cout << "|_|_|_|_|_|_|_| 3" << endl;
	cout << "|_|_|_|_|_|_|_| 2" << endl;
	cout << "|_|_|_|_|_|_|_| 1" << endl;
	cout << "|_|_|_|_|_|_|_| 0" << endl;
	cout << " a b c d e f g" << endl;

	char input;
	string color = "red";
	int winV = 0, winH = 0, winD = 0;
	//if no one has won yet, win = 0; if player 1 won, win = 1; player 2 won, win = 2
	
	//MOVE
	choose: while (winH == 0 && winV == 0 && winD == 0){
	cout << "Player " << player << " (" << color << "): " ;
	cout << "Where do you want to move? (Enter a character from a - g): ";
	cin >> input;
	clearScreen2();
	if (updateBoard(columns, input, player) == 1){
		goto choose;
	}
	displayBoard(columns);
	cout << endl;
	player = (player == 1) ? 2 : 1; // if player is currently 1, then set player to 2 and vis versa
	color = (color.compare("red") == 0) ? "yellow" : "red";

	//CHECK VERTICAL 
	winV = checkVertical(columns, input, player);

	//CHECK HORIZONTAL
	winH = checkHorizontal(columns, input, player);

	//CHECK DIAGONAL
	winD = checkDiagonal(columns, input, player);
	}
	
	


	return 0;
}