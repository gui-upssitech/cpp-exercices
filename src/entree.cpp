#include <iostream>
#include "entree.h"
using namespace std;

Entree::Entree() {
    this->nom = "-";
    this->numero = "-";
}

Entree::Entree(string nom, string numero) {
    this->nom = nom;
    this->numero = numero;
}

void Entree::afficher() {
    cout << *this;
}

string Entree::get_nom() {
    return this->nom;
}

string Entree::get_numero() {
    return this->numero;
}

// Opérateurs

ostream& operator<<(ostream& out, const Entree& e) {
    out << "nom: " << e.nom << ", numéro: " << e.numero;
    return out;
}

bool Entree::operator==(Entree& e) {
    return this->nom == e.nom && this->numero == e.numero;
}

bool Entree::operator!=(Entree& e) {
    return !(*this == e);
}