#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Client; 
class CompteBancaire; 
class AgentBancaire; 
class Banque; 

class Client { 
private:
    int idClient;
    string nom;
    string CIN;

public:
    Client(int id, string n, string c) : idClient(id), nom(n), CIN(c) {}

    void afficher() const {
        cout << "Client: " << nom << " (ID: " << idClient << ", CIN: " << CIN << ")" << endl;
    }

    friend class AgentBancaire;
    friend class Banque;
};

class CompteBancaire { 
private:
    int numeroCompte; 
    double solde; 
    string codeSecret; 
    Client& clientProprietaire; 

public:
    CompteBancaire(int num, double s, string code, Client& client)
        : numeroCompte(num), solde(s), codeSecret(code), clientProprietaire(client) {}

    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << "Depot de " << montant << " effectue. Nouveau solde: " << solde << endl;
        }
    }

    bool retirer(double montant) {
        if (montant > 0 && solde >= montant) {
            solde -= montant;
            cout << "Retrait de " << montant << " effectue. Nouveau solde: " << solde << endl;
            return true;
        } else {
            cout << "Retrait de " << montant << " impossible. Solde insuffisant." << endl;
            return false;
        }
    }

    double getSolde() const {
        return solde;
    }
    int getNumeroCompte() const {
        return numeroCompte;
    }
    Client& getClient() const {
        return clientProprietaire;
    }

    friend class AgentBancaire; 
    friend class Banque; 
};

class AgentBancaire { 
public:
    void consulterCodeSecret(const CompteBancaire& compte) {
        cout << "Code secret (confidentiel) du compte " << compte.numeroCompte
             << " est: " << compte.codeSecret << endl;
    }

    void effectuerTransfert(CompteBancaire& source, CompteBancaire& dest, double montant) {
        cout << "--- Tentative de Transfert (Agent) ---" << endl;
        if (montant > 0 && source.solde >= montant) {
            source.solde -= montant;
            dest.solde += montant;
            cout << "Transfert de " << montant << " du compte " << source.numeroCompte
                 << " vers " << dest.numeroCompte << " reussi." << endl;
        } else {
            cout << "Transfert impossible. Solde insuffisant." << endl;
        }
    }
};

class Banque { 
private:
    vector<Client> clients;
    vector<CompteBancaire> comptes;
public:
    void ajouterClient(int id, string nom, string CIN) {
        clients.emplace_back(id, nom, CIN);
    }

    void ajouterCompte(int num, double s, string code, int idClient) {
        Client* clientTrouve = nullptr;
        for (Client& c : clients) {
            if (c.idClient == idClient) {
                clientTrouve = &c;
                break;
            }
        }

        if (clientTrouve != nullptr) {
            comptes.emplace_back(num, s, code, *clientTrouve);
            cout << "Compte " << num << " cree pour " << clientTrouve->nom << endl;
        } else {
            cout << "Erreur: Client " << idClient << " non trouve." << endl;
        }
    }

    CompteBancaire* getCompte(int numCompte) {
         for (CompteBancaire& c : comptes) {
            if (c.getNumeroCompte() == numCompte) {
                return &c;
            }
        }
        return nullptr;
    }

    void afficherRapportAudit() { 
        cout << "--- RAPPORT D'AUDIT INTERNE (CONFIDENTIEL) ---" << endl;
        for (const CompteBancaire& compte : comptes) {
            cout << "Compte: " << compte.numeroCompte << endl;
            cout << "  Proprietaire: " << compte.clientProprietaire.nom << " (CIN: " << compte.clientProprietaire.CIN << ")" << endl;
            cout << "  Solde: " << compte.solde << endl;
            cout << "  Code Secret: " << compte.codeSecret << " (NE PAS DIVULGUER)" << endl;
            cout << "--------------------" << endl;
        }
    }
};

int main() {
    cout << endl << endl << "--- EXERCICE 2: BANQUE ---" << endl; 
    
    Banque maBanque;
    maBanque.ajouterClient(1, "Ahmed Alami", "A123"); 
    maBanque.ajouterClient(2, "Fatima Bennis", "B456");

    maBanque.ajouterCompte(1001, 5000, "1234", 1); 
    maBanque.ajouterCompte(1002, 2000, "5678", 2);

    CompteBancaire* compteAhmed = maBanque.getCompte(1001);
    CompteBancaire* compteFatima = maBanque.getCompte(1002);

    if (compteAhmed && compteFatima) {
        cout << endl << "--- Operations Publiques ---" << endl;
        compteAhmed->deposer(1000); 
        compteFatima->retirer(500); 
        
        cout << endl << "--- Operations Agent ---" << endl;
        AgentBancaire agent;
        agent.consulterCodeSecret(*compteAhmed);
        agent.effectuerTransfert(*compteAhmed, *compteFatima, 1500); 
    }

    cout << endl << "--- Audit Final ---" << endl;
    maBanque.afficherRapportAudit(); 

    return 0;
}