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
    cout << "nom: " << nom << ", numéro: " << numero << endl;
}

string Entree::get_nom() {
    return this->nom;
}

string Entree::get_numero() {
    return this->numero;
}