using namespace std;

bool gameOverSmallBoard(vector<char>);
bool gameOverBigBoard(vector< vector<char> > , vector<char> , vector<char>);
void displayBigBoard(vector< vector<char> > , vector<char> , vector<char>);
void displaySmallBoard(vector<char> , int );
bool checkSpaceUltimate(vector<char> , int);
int playTTTU();