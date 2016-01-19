#include <iostream>
#include <string>

using namespace std;

class Animal{
    private: 
        string name;
    public:
        Animal(string s){
            name = s;
        }
        ~Animal(){
            cout << "bye, " << name << endl;
        }

        virtual string noise() = 0;

        void speak(){
            cout << noise() << endl;
        }
};

class Cat : public Animal{
    public:
        Cat(string s) : Animal(s) {}
        string noise() override { return "woof"; }
};

class Cow : public Animal{
    public:
        Cow(string s) : Animal(s) {}
        string noise() override { return "mooo"; }
};

class OddCow : public Cow{
    public:
        OddCow(string s) : Cow(s) {}
        string noise() override { return "neigh"; }
};
