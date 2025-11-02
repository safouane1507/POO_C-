#include <iostream>
#include <cmath>
using namespace std;

class Vecteur3d {
public:
    float x, y, z;
    Vecteur3d(float a = 0, float b = 0, float c = 0) { x = a; y = b; z = c; }
    void afficher() { cout << "(" << x << "," << y << "," << z << ")" << endl; }
    Vecteur3d somme(Vecteur3d v) { return Vecteur3d(x + v.x, y + v.y, z + v.z); }
    float produitScalaire(Vecteur3d v) { return x * v.x + y * v.y + z * v.z; }
    bool coincide(Vecteur3d v) { return(x == v.x && y == v.y && z == v.z); }
    float norme() { return sqrt(x * x + y * y + z * z); }
    Vecteur3d normax(Vecteur3d v) { return(this->norme() >= v.norme() ? *this : v); }
};

int main() {
    Vecteur3d v1(1, 2, 3), v2(3, 4, 5);
    cout << "v1="; v1.afficher();
    cout << "v2="; v2.afficher();
    cout << "Somme:"; v1.somme(v2).afficher();
    cout << "Produit scalaire=" << v1.produitScalaire(v2) << endl;
    cout << "Coincide?" << (v1.coincide(v2) ? "Oui" : "Non") << endl;
    cout << "Norme v1=" << v1.norme() << endl;
    cout << "Vecteur avec plus grande norme:"; v1.normax(v2).afficher();
    return 0;
}
