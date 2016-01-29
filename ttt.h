#include <string>
using namespace std;

void welcomeDialogue(string);
void initBoard(char*);
void getNames(string &, string &);

bool gameOver(char*);
void displayTTT(char*);
bool checkSpace(char* , int);
int playTTT();