#include <iostream>
using namespace std;

class Stack{
    int* tab;
    int top;
    int size;
public:
    Stack(int s=20){
        size=s;
        top=0;
        tab=new int[size];
    }

    Stack(const Stack& p){
        size=p.size;
        top=p.top;
        tab=new int[size];
        for(int i=0;i<top;i++) tab[i]=p.tab[i];
    }

    Stack& operator=(const Stack&){
        throw string("Affectation interdite");
    }

    Stack& operator<<(int n){
        if(top<size) tab[top++]=n;
        return *this;
    }

    Stack& operator>>(int& n){
        if(top>0){
            top--;
            n=tab[top];
        }
        return *this;
    }

    int operator++(int){
        return top==size;
    }

    int operator--(int){
        return top==0;
    }

    ~Stack(){ delete[] tab; }
};

int main(){
    Stack p(5);
    int n1,n2,n3=0;

    p<<1<<2<<3;
    p>>n1>>n2<<4;
}
