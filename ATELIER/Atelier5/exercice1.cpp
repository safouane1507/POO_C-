#include <iostream>
#include <set>
#include <vector>
#include <list>
using namespace std;

bool rechercherSet(const set<int>& s, int val){
    return s.find(val) != s.end();
}

bool rechercherIter(set<int>::iterator debut, set<int>::iterator fin, int val){
    for(auto it = debut; it != fin; it++){
        if(*it == val) return true;
    }
    return false;
}

template <class It, class T>
bool rechercherTemplate(It debut, It fin, T val){
    for(It it = debut; it != fin; it++){
        if(*it == val) return true;
    }
    return false;
}

int main(){
    set<int> s;
    for(int i=1;i<=100;i++) s.insert(i);

    vector<string> v = {"a", "b", "c"};
    list<int> L = {1,2,3};
    float tab[3] = {1.1, 2.2, 3.3};

    rechercherTemplate(v.begin(), v.end(), string("b"));
    rechercherTemplate(L.begin(), L.end(), 2);
    rechercherTemplate(tab, tab+3, 2.2f);
}
