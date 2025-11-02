#include <iostream>
using namespace std;

void compterAppels() {
    static int compteur = 0;
    compteur++;
    cout << "appel numero " << compteur << endl;
}

int main() {
    compterAppels();
    compterAppels();
    compterAppels();
    return 0;
}