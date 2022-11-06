#ifndef TP1_TABLEAU_H
#define TP1_TABLEAU_H

#include "entree.h"
#include <string>

class Tableau {
private:
    int taille, nb_elem;
    Entree *entrees;

public:
    Tableau(int taille = 20);
    Tableau(const Tableau &copie);
    ~Tableau();

    void afficher();
    bool ajouter(string nom, string numero);
    void supprimer(string nom, string numero);
    void supprimer(string nom);

    int get_nb_elem();
    int get_taille();
    Entree get(int i);

    friend ostream& operator<<(ostream& out, const Tableau& t);
    Entree operator[](int i);
    bool operator==(Tableau& t);
    bool operator!=(Tableau& t);
};


#endif //TP1_TABLEAU_H
