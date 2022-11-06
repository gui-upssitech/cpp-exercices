#ifndef TP1_AGENDA_H
#define TP1_AGENDA_H

#include "tableau.h"
#include <string>

using namespace std;

class Agenda {

private:
    Tableau tableau;

public:
    Agenda(int taille=20);
    Agenda(const Agenda &copie);

    Agenda concat(Agenda &agenda);
    
    void afficher();
    bool ajouter(string nom, string numero);
    void supprimer(string nom, string numero);
    void supprimer(string nom);

    // Surcharge d'opérateurs
    friend ostream& operator<<(ostream& out, Agenda& agenda);
    friend Agenda operator+(Agenda ag, Entree entree);
    friend Agenda operator+=(Agenda& ag, Entree entree);
    Agenda operator=(Agenda& ag);
    Agenda operator+(Agenda& a);
    Agenda operator+=(Agenda& a);
    Entree operator[](string nom);
    friend Agenda operator-(Agenda ag, string nom);
    friend Agenda operator-=(Agenda& ag, string nom);

    bool operator==(Agenda& ag);
    bool operator!=(Agenda& ag);

    friend bool operator/(string nom, Agenda& ag);
    string* operator()(char c);
};


#endif //TP1_AGENDA_H
