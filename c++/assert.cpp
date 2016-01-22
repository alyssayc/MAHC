#include <cassert>
#include <iostream>

using namespace std;

int main(){
    assert(2+2==4);
    cout << "first assert passed\n\n";

    assert(2+2==5);
    cout << "second assert passed\n\n";
}
