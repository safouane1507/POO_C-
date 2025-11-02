#include <iostream>

using namespace std;

class Pile {
    int T[100];
    int sommet;

public:
    Pile() {
        sommet = -1;
    }

    void push(int x) {
        if (sommet < 99) {
            sommet++;
            T[sommet] = x;
        } else {
            cout << "Pile pleine" << endl;
        }
    }

    int pop() {
        if (sommet >= 0) {
            int val = T[sommet];
            sommet--;
            return val;
        } else {
            cout << "Pile vide" << endl;
            return -1;
        }
    }

    bool estVide() {
        return (sommet == -1);
    }
};

int main() {
    Pile p1, p2;

    p1.push(10);
    p1.push(20);
    p1.push(30);

    p2.push(5);
    p2.push(8);

    cout << "Depilage p1: " << p1.pop() << endl;
    cout << "Depilage p1: " << p1.pop() << endl;

    cout << "Depilage p2: " << p2.pop() << endl;

    return 0;
}