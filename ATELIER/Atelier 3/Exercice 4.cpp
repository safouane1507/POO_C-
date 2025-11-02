#include <iostream>
#include <string>

using namespace std;
class Client {
    int id;
    string nom;
    string prenom;

public:
    Client() {
        id = 0;
        nom = "";
        prenom = "";
    }

    Client(int i, string n, string p) {
        id = i;
        nom = n;
        prenom = p;
    }

    Client(const Client& C) {
        id = C.id;
        nom = C.nom;
        prenom = C.prenom;
    }

    ~Client() {
    }

    void afficher() {
        cout << "   Client (ID " << id << "): " << prenom << " " << nom << endl;
    }
};
class Compte {
    int numero;
    float solde;
    Client* client;

public:
    static int totalComptes;

    Compte() {
        numero = 0;
        solde = 0;
        client = NULL;
        totalComptes++;
    }

    Compte(int n, float s, Client* c) {
        numero = n;
        solde = s;
        client = new Client(*c); 
        totalComptes++;
    }

    Compte(const Compte& C) {
        numero = C.numero;
        solde = C.solde;
        client = new Client(*(C.client)); 
        totalComptes++;
    }

    ~Compte() {
        delete client;
        totalComptes--;
    }

    void afficher() {
        cout << "Compte " << numero << " - Solde: " << solde << " DHS" << endl;
        if (client != NULL) {
            client->afficher();
        }
    }

    static void afficherTotalComptes() {
        cout << "--- Nombre total de comptes: " << totalComptes << " ---" << endl;
    }

    float getSolde() {
        return solde;
    }

    void setSolde(float s) {
        solde = s;
    }
};

int Compte::totalComptes = 0;
inline float calculInteret(float solde, float taux) {
    return solde * (1.0 + taux);
}
int main() {
    Compte::afficherTotalComptes();

    Client c1(1, "ALAMI", "Ahmed");
    Client c2(2, "BOUZID", "Fatima");

    cout << "\nCreation des comptes:" << endl;
    Compte* cp1 = new Compte(100, 5000, &c1);
    Compte* cp2 = new Compte(101, 10000, &c2);

    cp1->afficher();
    cp2->afficher();
    Compte::afficherTotalComptes();

    cout << "\nTest de copie:" << endl;
    Compte cp3 = *cp1;
    cp3.afficher();
    Compte::afficherTotalComptes();

    cout << "\nSuppression de cp1:" << endl;
    delete cp1;
    Compte::afficherTotalComptes();

    cout << "\nCalcul des interets pour cp2:" << endl;
    float nouveauSolde = calculInteret(cp2->getSolde(), 0.05);
    cp2->setSolde(nouveauSolde);
    cp2->afficher();

    cout << "\nSuppression des comptes restants:" << endl;
    delete cp2;

    cout << "\nFin du programme" << endl;
    return 0;
}