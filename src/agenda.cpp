#include "agenda.h"

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