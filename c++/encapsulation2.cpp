#include <iostream>

using namespace std;

class Point {
    friend void changePrivate(Point &p);
    friend class PointFactory;

    public:
        Point() { m_i = 0; }
        void display() {cout << m_i << endl; }

    private:
        int m_i;
};

void changePrivate(Point &p) { p.m_i++; }

class PointFactory {
    int f_i;

    public:
        PointFactory(int i) : f_i(i) {}

        void setPoint(int i) { f_i = i; }

        Point build() {
            Point p = Point();
            p.m_i = f_i; // access private member
            return p;
        }
};

