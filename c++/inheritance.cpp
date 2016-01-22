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
        
        ~Animal() {
            cout << "bye, " << name << endl;
        }

        virtual string noise() = 0;

        void speak() {
            cout << noise() << endl;
        }
};

class Cow : public Animal {
    protected:
        int milk;
    public:
        Cow(string s) : Animal(s) { milk = 10; }
        string noise() override { return "mooo"; } // c++11
};

class OddCow : public Cow {
    private:
        int sprite;
    public:
        OddCow(string s) : Cow(s) { this->sprite = this->milk; }
        string noise() { return "neigh"; }
};

