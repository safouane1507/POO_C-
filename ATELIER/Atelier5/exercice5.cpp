#include <iostream>
using namespace std;

template <class T>
T carre(T x){
    return x*x;
}

int main(){
    cout<<carre(5)<<endl;
    cout<<carre(2.5)<<endl;
}
