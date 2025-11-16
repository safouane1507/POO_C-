#include <iostream>
using namespace std;

class Test{
public:
    static int tableau[];
public:
    static int division(int indice, int diviseur){
        if(indice < 0 || indice > 9) throw string("Indice invalide");
        if(diviseur == 0) throw string("Division par zero");
        return tableau[indice] / diviseur;
    }
};

int Test::tableau[]={17,12,15,38,29,157,89,-22,0,5};

int main(){
    int x,y;
    try{
        cin>>x;
        cin>>y;
        cout<<Test::division(x,y)<<endl;
    }
    catch(string e){
        cout<<e<<endl;
        return 0;
    }
}
