#include <iostream>

using namespace std;

class Fichier {
    char* P;
    int longueur;

public:
    Fichier() {
        P = NULL;
        longueur = 0;
    }

    ~Fichier() {
        delete[] P;
    }

    void Creation(int L) {
        longueur = L;
        P = new char[longueur];
        cout << "Memoire allouee" << endl;
    }

    void Remplit() {
        if (P != NULL) {
            for (int i = 0; i < longueur; i++) {
                P[i] = 'A' + (i % 26);
            }
        }
    }

    void Affiche() {
        if (P != NULL) {
            for (int i = 0; i < longueur; i++) {
                cout << P[i];
            }
            cout << endl;
        }
    }
};

int main() {
    Fichier* monFichier = new Fichier();

    monFichier->Creation(15);
    monFichier->Remplit();
    monFichier->Affiche();

    delete monFichier;
    cout << "Memoire liberee" << endl;

    return 0;
}