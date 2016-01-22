#include <iostream>

/*
int mean(int a, int b){
    return (a + b) / 2;
}
double mean(double a, double b){
    return (a + b) / 2;
}
*/
template<class T>
T mean (T a, T b){
    return (a + b) / 2;
}
using namespace std;

int main(){
    int m = 1, n = 9;
    double x = 2.3, y = 1.2;

    cout << mean(m, n) << endl;
    cout << mean(x, y) << endl;

    return 0;
}
