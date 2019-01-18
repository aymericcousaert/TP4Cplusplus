#include iostream
#include <string>
#include fstream

#include "Ligne.h"

int main(int argc, char *argv[])
{
    string ligne;
    ifstream fichier("test.log",ios::in)
    getline(fichier, ligne);
    Ligne l1 = Ligne(ligne);
    l1.afficher();
    fichier.close();
    return 0;
}
