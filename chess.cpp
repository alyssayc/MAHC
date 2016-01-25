#include "color.h"
#include <iostream>

using namespace std;

void displayBoard (char*)
int main() {
    cout << RED << "Chess Board!" << RESET << endl;

    //make board
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string numbers = "87654321";
    string num[9];

    for (int row =0 ; row < 10; row++){
    	for (int col = 0; col < 8; col++){
    		
    		/* CHESS DISPLAY

    		     A     B     C     D     E     F     G     H
    		   _______________________________________________
    		  |     |     |     |     |     |     |     |     | 5 spaces, |
    		 8|  R  |  K  |  B  |  Q  |  K  |  B  |  K  |  R  |
    		  |_____|_____|_____|_____|_____|_____|_____|_____|
    		  |     |     |     |     |     |     |     |     | 
    		 7|  P  |  P  |  P  |  P  |  P  |  P  |  P  |  P  |
    		  |_____|_____|_____|_____|_____|_____|_____|_____|
    		  |     |     |     |     |     |     |     |     | 
    		 6|     |     |     |     |     |     |     |     |
    		  |_____|_____|_____|_____|_____|_____|_____|_____|
    		  |     |     |     |     |     |     |     |     | 
    		 5|     |     |     |     |     |     |     |     |
    		  |_____|_____|_____|_____|_____|_____|_____|_____|
    		  |     |     |     |     |     |     |     |     | 
    		 4|     |     |     |     |     |     |     |     |
    		  |_____|_____|_____|_____|_____|_____|_____|_____|
			  |     |     |     |     |     |     |     |     | 
    		 3|     |     |     |     |     |     |     |     |
    		  |_____|_____|_____|_____|_____|_____|_____|_____|
    		  |     |     |     |     |     |     |     |     | 
    		 2|  P  |  P  |  P  |  P  |  P  |  P  |  P  |  P  |
    		  |_____|_____|_____|_____|_____|_____|_____|_____|
    		  |     |     |     |     |     |     |     |     | 
    		 1|  R  |  K  |  B  |  K  |  Q  |  B  |  K  |  R  |
    		  |_____|_____|_____|_____|_____|_____|_____|_____|

    		*/



    		if (row == 0) {
    			if (col == 0) {
    				cout << " ";
    			}

    			cout << " " << alphabet[col] << " ";
    		}

    		else if (row == 1) {
    			if (col == 0) {
    				cout << endl << " ";
    			}

    			cout  << " __";
    			//cout << "Row, Col" << row<<col<<endl;
    		}
    		
    		else {
    			if (col == 0) {
    				cout << endl << (row-1);
    			}
    			cout << "|" << "__";

    		}


    	}
    	
    }
    cout << endl;




    return 0;
}