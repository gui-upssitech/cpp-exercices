#include <iostream>
#include "entree.h"
#include "tableau.h"
#include "agenda.h"

using namespace std;

void test_entree() {
    Entree entree_vide;
    Entree entree("Noé Marzat", "+33 6 77 30 77 82");

    entree_vide.afficher();
    entree.afficher();
}

void test_tableau() {
    Tableau tableau(5);

    tableau.ajouter("Noé Marzat", "+33 6 77 30 77 82");
    tableau.ajouter("Alexis Zemb", "+33 6 77 30 77 82");
    tableau.ajouter("Noé Marzat", "+33 6 77 30 76 82");
    tableau.ajouter("Jean Kirischtein", "+33 6 77 30 77 82");

    tableau.afficher();
    cout << endl << "Tableau occupé à " << tableau.get_nb_elem() << "/" << tableau.get_taille() << endl << endl;

    tableau.supprimer("Alexis Zemb", "+33 6 77 30 77 82");
    tableau.afficher();
    cout << endl;

    tableau.supprimer("Noé Marzat");
    tableau.afficher();
}

void test_agenda() {
    Agenda agenda(5);

    agenda.ajouter("Noé Marzat", "+33 6 77 30 77 82");
    agenda.ajouter("Alexis Zemb", "+33 6 77 30 77 82");
    agenda.ajouter("Noé Marzat", "+33 6 77 30 76 82");
    agenda.ajouter("Jean Kirischtein", "+33 6 77 30 77 82");

    Agenda agenda2(agenda);

    agenda.afficher();
    cout << endl;
    agenda2.afficher();
    cout << endl;

    Agenda agenda_concat = agenda.concat(agenda2);

    cout << "Agenda concat" << endl;
    agenda_concat.afficher();
}

int main() {
    cout << "Test Entree" << endl << "===" << endl;
    test_entree();
    cout << endl;

    cout << "Test Tableau" << endl << "===" << endl;
    test_tableau();
    cout << endl;

    cout << "Test Agenda" << endl << "===" << endl;
    test_agenda();
}
