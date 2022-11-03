#include <iostream>
#include "tableau.h"
using namespace std;

// Constructeurs & destructeurs

Tableau::Tableau(int taille) {
    this->taille = taille;
    this->nb_elem = 0;
    this->entrees = new Entree[taille];
}

Tableau::Tableau(const Tableau &copie) {
    this->taille = copie.taille;
    this->nb_elem = copie.nb_elem;

    this->entrees = new Entree[taille];
    for(int i = 0; i < nb_elem; i++) {
        this->entrees[i] = copie.entrees[i];
    }
}

Tableau::~Tableau() {
    delete[] this->entrees;
}

// Class methods

bool Tableau::ajouter(std::string nom, std::string numero) {
    if(nb_elem == taille) return false;

    Entree entree(nom, numero);
    entrees[nb_elem++] = entree;
    return true;
}

void Tableau::supprimer(std::string nom, std::string numero) {
    for (int i = 0; i < nb_elem; i++) {
        if(entrees[i].get_nom() == nom && entrees[i].get_numero() == numero) {
            entrees[i] = entrees[--nb_elem];
        }
    }
}

void Tableau::supprimer(std::string nom) {
    for (int i = 0; i < nb_elem; i++) {
        if(entrees[i].get_nom() == nom) {
            entrees[i] = entrees[--nb_elem];
            i--; // On retourne en arrière pour vérifier que l'élément remplacé n'est pas a supprimer
        }
    }
}

void Tableau::afficher() {
    cout << "Tableau" << endl;
    for (int i = 0; i < nb_elem; i++) {
        entrees[i].afficher();
    }
}

// Getters

int Tableau::get_nb_elem() {
    return this->nb_elem;
}

int Tableau::get_taille() {
    return this->taille;
}

Entree Tableau::get(int i) {
    return this->entrees[i];
}