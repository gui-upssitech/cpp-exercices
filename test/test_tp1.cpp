#include <iostream>
#include "entree.h"
#include "tableau.h"
#include "agenda.h"

using namespace std;

void test_entree() {
    Entree entree_vide;
    Entree entree("Noé Marzat", "+33 6 77 30 77 82");

    cout << "Test entrée vide" << endl;
    entree_vide.afficher();
    cout << endl;
    cout << "Test entrée peuplée" << endl;
    entree.afficher();
    cout << endl;
}

void test_tableau() {
    Tableau tableau(5);

    tableau.ajouter("Noé Marzat", "+33 6 77 30 77 82");
    tableau.ajouter("Alexis Zemb", "+33 6 77 30 77 82");
    tableau.ajouter("Noé Marzat", "+33 6 77 30 76 82");
    tableau.ajouter("Jean Kirischtein", "+33 6 77 30 77 82");

    cout << "On peuple le tableau" << endl;
    tableau.afficher();

    cout << endl << "On vérifie l'occupation du tableau" << endl;
    cout << "Tableau occupé à " << tableau.get_nb_elem() << "/" << tableau.get_taille() << endl << endl;

    cout << "On supprime Alexis Zemb avec le numéro +33 6 77 30 77 82" << endl;
    tableau.supprimer("Alexis Zemb", "+33 6 77 30 77 82");
    tableau.afficher();
    cout << endl;

    cout << "On supprime toutes les occurences de Noé Marzat" << endl;
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

    cout << "On créé et on clone un agenda" << endl;
    agenda.afficher();
    cout << endl;
    agenda2.afficher();
    cout << endl;

    Agenda agenda_concat = agenda.concat(agenda2);

    cout << "Concaténation des deux agendas" << endl;
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
