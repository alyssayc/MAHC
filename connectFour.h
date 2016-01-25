#include <iostream>
#include <vector> 

using namespace std;

void displayBoard(vector< vector<int> >&);
void updateBoard(vector< vector<int> >&, char, int);
int checkVertical(vector< vector<int> >&, char, int);
int checkHorizontal(vector< vector<int> >&, char, int);
int checkDiagonal(vector< vector<int> >&, char, int);
int playConnectFour();