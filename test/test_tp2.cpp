#include <iostream>
#include "entree.h"
#include "agenda.h"

using namespace std;

void test_agenda() {
    Agenda agenda(5);

    // Test opérateur << & opérateur + avec Entree
    cout << "Test opérateur << & opérateur + avec Entree" << endl << "===" << endl;
    agenda += Entree("Noé Marzat", "+33 6 77 30 77 82");
    agenda += Entree("Alexis Zemb", "+33 6 77 30 77 82");
    agenda += Entree("Noelle Marzat", "+33 6 77 30 76 82");
    agenda += Entree("Jean Kirischtein", "+33 6 77 30 77 82");
    cout << agenda << endl;
    
    // Test opérateur + avec Agenda
    cout << "Test opérateur + avec Agenda" << endl << "===" << endl;
    Agenda agenda2(agenda);
    Agenda agenda_concat = agenda + agenda2;
    cout << agenda_concat << endl;

    // Test opérateur ==
    cout << "Test opérateur ==" << endl << "===" << endl;
    if (agenda == agenda2) {
        cout << "Agenda égaux" << endl;
    } else {
        cout << "Agenda différents" << endl;
    }
    cout << endl;

    // Test opérateur []
    cout << "Test opérateur []" << endl << "===" << endl;
    cout << agenda["Noé Marzat"] << endl << endl;
    
    // Test opérateur /
    cout << "Test opérateur /" << endl << "===" << endl;
    if ("Noé Marzat" / agenda) {
        cout << "Noé Marzat est dans l'agenda" << endl;
    } else {
        cout << "Noé Marzat n'est pas dans l'agenda" << endl;
    }
    cout << endl;
    
    // Test opérateur ()
    cout << "Test opérateur ()" << endl << "===" << endl;
    string* tab = agenda('N');
    int  i = 0;
    while (tab[i] != "") {
        cout << tab[i++] << endl;
    }
    cout << endl;

    // Test opérateur -
    cout << "Test opérateur -" << endl << "===" << endl;
    agenda -= "Noé Marzat";
    cout << agenda << endl;

    // Test opérateur / (à nouveau)
    cout << "On teste à nouveau l'opérateur /" << endl << "===" << endl;
    if ("Noé Marzat" / agenda) {
        cout << "Noé Marzat est dans l'agenda" << endl;
    } else {
        cout << "Noé Marzat n'est pas dans l'agenda" << endl;
    }
    cout << endl;

    // Test opérateur !=
    cout << "Test opérateur !=" << endl << "===" << endl;
    if (agenda != agenda2) {
        cout << "Agenda différents" << endl;
    } else {
        cout << "Agenda égaux" << endl;
    }
}

int main() {
    test_agenda();
}