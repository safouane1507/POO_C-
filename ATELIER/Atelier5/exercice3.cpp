#include <iostream>
using namespace std;

class vect{
protected:
    int nelem;
    int* adr;
public:
    vect(int n){
        nelem=n;
        adr=new int[n];
    }
    ~vect(){ delete[] adr; }
    int& operator[](int i){ return adr[i]; }
};

class vectok : public vect{
public:
    vectok(int n):vect(n){}
    vectok(const vectok& v):vect(v.nelem){
        for(int i=0;i<nelem;i++) adr[i]=v.adr[i];
    }
    vectok operator=(const vectok& v){
        if(this!=&v){
            delete[] adr;
            nelem=v.nelem;
            adr=new int[nelem];
            for(int i=0;i<nelem;i++) adr[i]=v.adr[i];
        }
        return *this;
    }
    int taille(){ return nelem; }
};

int main(){
    vectok a(3);
    a[0]=1; a[1]=2; a[2]=3;

    vectok b=a;
    vectok c(3);
    c=b;
}
