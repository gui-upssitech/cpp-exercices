#ifndef TP1_ENTREE_H
#define TP1_ENTREE_H

#include <string>

using namespace std;

class Entree {

private:
    string nom;
    string numero;

public:
    Entree();
    Entree(string nom, string numero);
    void afficher();

    string get_nom();
    string get_numero();

    friend ostream& operator<<(ostream& out, const Entree& e);
    bool operator==(Entree& e);
    bool operator!=(Entree& e);
};


#endif //TP1_ENTREE_H
