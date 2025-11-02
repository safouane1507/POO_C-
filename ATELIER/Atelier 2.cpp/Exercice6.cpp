#include <iostream>
using namespace std;

void incrementer(int* x) { (*x)++; }
void permuter(int* a, int* b) { int tmp = *a; *a = *b; *b = tmp; }

void incrementerRef(int& x) { x++; }
void permuterRef(int& a, int& b) { int tmp = a; a = b; b = tmp; }

int main() {
    int a = 5, b = 8;
    incrementer(&a);
    cout << "a = " << a << endl;

    permuter(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;

    incrementerRef(a);
    permuterRef(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}
