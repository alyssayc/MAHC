#include <iostream>

using namespace std;

class Role;

class Employee {
    private:
        int checksum;
        bool verify_data();

    protected:
        string name; 
        int salary;

    public:
        Employee(string n, int s){
            name = n;
            salary = s;
        }

        virtual void assign(Role r) = 0;
};
