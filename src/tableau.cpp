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
    // On subsitiue les éléments à supprimer par le dernier élément de la liste, 
    // puis on diminue le nombre d'éléments présents dans la liste
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
    cout << *this;
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

ostream& operator<<(ostream& out, const Tableau& t) {
    out << "Tableau" << endl;
    for (int i = 0; i < t.nb_elem; i++) {
        out << t.entrees[i] << endl;
    }
    return out;
}

bool Tableau::operator==(Tableau& t) {
    if(taille != t.taille) return false;
    if(nb_elem != t.nb_elem) return false;

    for(int i = 0; i < nb_elem; i++) {
        if(entrees[i] != t.entrees[i]) return false;
    }

    return true;
}

bool Tableau::operator!=(Tableau& t) {
    return !(*this == t);
}

Entree Tableau::operator[](int i) {
    return entrees[i];
}