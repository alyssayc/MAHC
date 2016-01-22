#include <string>
#include <iostream>
#include <set>

using namespace std;

class Employee{
    protected:
        string name;
        string title;
        int salary;
        Employee * boss;
        set< Employee * > underlings;
    
    public:
        Employee(string n, int s){
            name = n;
            title = "none";
            salary = s;
            boss = NULL;
        }

        string getTitle() { return title; }

        void assignUnder(Employee * new_boss){
            this->unassign();
            this->boss = new_boss;
            this->boss->addUnderling(this);
        }
    private:
        void removeUnderling(Employee * pe) { underlings.erase(pe); }

        void unassign() {
            boss->removeUnderling(this);
            boss = NULL;
        }
        void addUnderling(Employee * e) {this->underlings.insert(e); }

};
