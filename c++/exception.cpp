#include <exception>
#include <iostream>

using namespace std;

class NotFoundException : public exception{
    virtual const char* what() const throw(){
        return "the value does not exist in the array";
    }
} nfex;

template<class T>
int find(T * arr, T val, int size){
    for (int i = 0; i < size; i++){
        if (arr[i] == val){
            return i;
        }
    }
    throw nfex;
}

int main(){
    int x[] = {8, 6, 7, 5, 3, 0, 9};
    int num_to_find;
    scanf("%d", &num_to_find);
    try{
        cout << find(x, num_to_find, 7) << '\n';
    } catch (exception &e) {
        cout << e.what() << 'n';
    }
}
