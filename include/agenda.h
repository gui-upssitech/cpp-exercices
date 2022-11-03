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

};


#endif //TP1_AGENDA_H
