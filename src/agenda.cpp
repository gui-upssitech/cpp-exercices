#include "agenda.h"
#include <iostream>

// Constructor
Agenda::Agenda(int taille): tableau(taille) {}
Agenda::Agenda(const Agenda &copie): tableau(copie.tableau) {}

// Utility functions

bool Agenda::ajouter(std::string nom, std::string numero) {
    return tableau.ajouter(nom, numero);
}

void Agenda::afficher() {
    tableau.afficher();
}

void Agenda::supprimer(std::string nom) {
    tableau.supprimer(nom);
}

void Agenda::supprimer(std::string nom, std::string numero) {
    tableau.supprimer(nom, numero);
}

Agenda Agenda::concat(Agenda &agenda) {
    // On commence par créer un agenda dont la taille est la somme de la taille des 2 agendas à concatener
    int taille = tableau.get_taille() + agenda.tableau.get_taille();
    Agenda agenda_concat(taille);

    // On ajoute les éléments de l'agenda 1
    for(int i = 0; i < tableau.get_nb_elem(); i++) {
        Entree entree = tableau.get(i);
        agenda_concat.ajouter(entree.get_nom(), entree.get_numero());
    }

    // On ajoute les éléments de l'agenda 2
    for(int i = 0; i < agenda.tableau.get_nb_elem(); i++) {
        Entree entree = agenda.tableau.get(i);
        agenda_concat.ajouter(entree.get_nom(), entree.get_numero());
    }

    // On retourne la concaténation des deux agendas
    return agenda_concat;
}

// Opérateurs
// ==================================================

ostream& operator<<(ostream& out, Agenda& agenda) {
    out << agenda.tableau;
    return out;
}

Agenda operator+(Agenda ag, Entree entree) {
    ag.ajouter(entree.get_nom(), entree.get_numero());
    return Agenda(ag);
}

Agenda operator+=(Agenda& ag, Entree entree) {
    ag.ajouter(entree.get_nom(), entree.get_numero());
    return ag;
}

Agenda Agenda::operator=(Agenda& ag) {
    return Agenda(ag);
}

Agenda Agenda::operator+(Agenda& ag) {
    return this->concat(ag);
}

Agenda Agenda::operator+=(Agenda& ag) {
    return this->concat(ag);
}

Entree Agenda::operator[](string nom) {
    for(int i = 0; i < tableau.get_nb_elem(); i++) {
        if(tableau[i].get_nom() == nom) return tableau[i];
    }
    return Entree();
}

Agenda operator-(Agenda ag, string nom) {
    ag.supprimer(nom);
    return ag;
}

Agenda operator-=(Agenda& ag, string nom) {
    ag.supprimer(nom);
    return ag;
}

bool Agenda::operator==(Agenda& ag) {
    return tableau == ag.tableau;
}

bool Agenda::operator!=(Agenda& ag) {
    return tableau != ag.tableau;
}

bool operator/(string nom, Agenda& ag) {
    for(int i = 0; i < ag.tableau.get_nb_elem(); i++) {
        if(ag.tableau[i].get_nom() == nom) return true;
    }
    return false;
}

string* Agenda::operator()(char c) {
    string* res = new string[tableau.get_nb_elem() + 1];
    int j = 0;

    for(int i = 0; i < tableau.get_nb_elem(); i++) {
        if(tableau[i].get_nom().at(0) == c) res[j++] = tableau[i].get_nom();
    }
    res[j] = "";

    return res;
}