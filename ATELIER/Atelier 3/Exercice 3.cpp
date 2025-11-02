#include <iostream>

using namespace std;

struct element {
    int data;
    element* next;
};

class liste {
    element* premier;

public:
    liste() {
        premier = NULL;
    }

    ~liste() {
        while (premier != NULL) {
            supprimerDebut();
        }
    }

    void ajouterDebut(int val) {
        element* nouveau = new element;
        nouveau->data = val;
        nouveau->next = premier;
        premier = nouveau;
    }

    void supprimerDebut() {
        if (premier != NULL) {
            element* temp = premier;
            premier = premier->next;
            delete temp;
        }
        else {
            cout << "Liste deja vide" << endl;
        }
    }

    void afficherListe() {
        element* courant = premier;
        while (courant != NULL) {
            cout << courant->data << " -> ";
            courant = courant->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    liste L;

    L.ajouterDebut(10);
    L.ajouterDebut(20);
    L.ajouterDebut(30);
    L.afficherListe();

    L.supprimerDebut();
    L.afficherListe();

    L.supprimerDebut();
    L.supprimerDebut();
    L.afficherListe();

    return 0;
}