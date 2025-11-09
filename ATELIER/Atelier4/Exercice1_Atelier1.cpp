#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Telechargeable { 
public:
    void telecharger() {
        cout << "Telechargement (via Telechargeable)..." << endl;
    }
    void afficherMessage() {
        cout << "Ceci est telechargeable." << endl;
    }
};

class Ressource { 
protected:
    int id;
    string titre;
    string auteur;
    int annee;

public:
    Ressource(int i, string t, string a, int an) : id(i), titre(t), auteur(a), annee(an) {}
    virtual ~Ressource() {}

    virtual void afficherInfos() {
        cout << "ID: " << id << ", Titre: " << titre << ", Auteur: " << auteur << ", Annee: " << annee << endl;
    }
    virtual void telecharger() {
        cout << "Telechargement (via Ressource)..." << endl;
    }

    string getTitre() const { return titre; }
    int getAnnee() const { return annee; }
    string getAuteur() const { return auteur; }
    int getId() const { return id; }

    bool operator==(const Ressource& other) const { 
        return this->id == other.id;
    }
};

class Livre : public Ressource, public Telechargeable { 
private:
    string ISBN;
public:
    Livre(int i, string t, string a, int an, string isbn) : Ressource(i, t, a, an), ISBN(isbn) {}

    void afficherInfos() override {
        cout << "[LIVRE] ID: " << id << ", Titre: " << titre << ", Auteur: " << auteur
             << ", Annee: " << annee << ", ISBN: " << ISBN << endl;
    }
    void telecharger() override {
        cout << "Telechargement du Livre: " << titre << endl;
    }
};

class Magazine : public Ressource, public Telechargeable { 
private:
    int numero;
public:
    Magazine(int i, string t, string a, int an, int num) : Ressource(i, t, a, an), numero(num) {}

    void afficherInfos() override {
        cout << "[MAGAZINE] ID: " << id << ", Titre: " << titre << ", Auteur: " << auteur
             << ", Annee: " << annee << ", Numero: " << numero << endl;
    }
    void telecharger() override {
        cout << "Telechargement du Magazine: " << titre << endl;
    }
};

class Video : public Ressource, public Telechargeable { 
private:
    int duree;
public:
    Video(int i, string t, string a, int an, int d) : Ressource(i, t, a, an), duree(d) {}

    void afficherInfos() override {
        cout << "[VIDEO] ID: " << id << ", Titre: " << titre << ", Auteur: " << auteur
             << ", Annee: " << annee << ", Duree: " << duree << "min" << endl;
    }
    void telecharger() override {
        cout << "Telechargement de la Video: " << titre << endl;
    }
};

class Mediatheque { 
private:
    vector<Ressource*> ressources;
public:
    ~Mediatheque() {
        for (Ressource* r : ressources) {
            delete r;
        }
    }

    void ajouter(Ressource* r) {
        ressources.push_back(r);
    }

    void afficher() {
        cout << "--- Contenu de la Mediatheque ---" << endl;
        for (Ressource* r : ressources) {
            r->afficherInfos();
        }
    }

    void rechercher(string titre) { 
        cout << "--- Recherche par Titre: " << titre << " ---" << endl;
        for (Ressource* r : ressources) {
            if (r->getTitre() == titre) {
                r->afficherInfos();
            }
        }
    }

    void rechercher(int annee) { 
        cout << "--- Recherche par Annee: " << annee << " ---" << endl;
        for (Ressource* r : ressources) {
            if (r->getAnnee() == annee) {
                r->afficherInfos();
            }
        }
    }

    void rechercher(string auteur, int annee) { 
        cout << "--- Recherche par Auteur: " << auteur << " et Annee: " << annee << " ---" << endl;
        for (Ressource* r : ressources) {
            if (r->getAuteur() == auteur && r->getAnnee() == annee) {
                r->afficherInfos();
            }
        }
    }
};

int main() {
    cout << "--- EXERCICE 1: MEDIATHEQUE ---" << endl; 
    Mediatheque m;
    m.ajouter(new Livre(1, "Apprendre C++", "Auteur C++", 2023, "12345"));
    m.ajouter(new Magazine(2, "Info Hebdo", "Redaction", 2024, 52));
    m.ajouter(new Video(3, "POO en 10min", "Videaste", 2024, 10));

    m.afficher();

    cout << endl << "--- Tests de Recherche ---" << endl;
    m.rechercher("Info Hebdo");
    m.rechercher(2024);
    m.rechercher("Auteur C++", 2023);

    cout << endl << "--- Tests Telechargement et Conflit ---" << endl;
    Livre* l = new Livre(4, "Test Livre", "Test Auteur", 2025, "98765");
    l->telecharger(); 

    cout << "Appel qualifie 1: ";
    l->Ressource::telecharger();
    cout << "Appel qualifie 2: ";
    l->Telechargeable::telecharger();

    cout << endl << "--- Test Comparaison ---" << endl; 
    Livre l1(10, "Livre A", "A", 2000, "111");
    Video v1(10, "Video C", "C", 2002, 30);
    Livre l2(20, "Livre B", "B", 2001, "222");

    if (l1 == v1) {
        cout << "Livre 1 (ID 10) et Video 1 (ID 10) sont egaux (meme ID)." << endl;
    }
    if (!(l1 == l2)) {
        cout << "Livre 1 (ID 10) et Livre 2 (ID 20) ne sont pas egaux." << endl;
    }

    delete l;

    return 0;
}