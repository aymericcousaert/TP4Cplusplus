#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>
using namespace std;

#include "Ligne.h"
#include "Classement.h"
#include "Graphe.h"

map<string, informations> mapCibles;

informations remplissage(Ligne& uneLigne)
{
    informations infos;
    infos.nbApparition = 1;
    infos.mapReferers.insert(pair<string,int>(uneLigne.getReferer(), 1));
    return infos;
}

void inserer(Ligne& l)
{
    if (mapCibles.find(l.getCible()) == mapCibles.end())
    {
        informations infos = remplissage(l);
        mapCibles.insert(pair<string,informations>(l.getCible(), infos));
    }
    else if (mapCibles[l.getCible()].mapReferers.find(l.getReferer()) == mapCibles[l.getCible()].mapReferers.end())
    {
        mapCibles[l.getCible()].mapReferers.insert(pair<string,int>(l.getReferer(),1));
        mapCibles[l.getCible()].nbApparition++;
    }
    else
    {
        mapCibles[l.getCible()].mapReferers[l.getReferer()]++;
        mapCibles[l.getCible()].nbApparition++;
    }
}

int main(int argc, char* argv[])
{
    int heure = 0;
    string fichierDot = "";
    int option = 0;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-e") == 0)
            option = 1;
        if (strcmp(argv[i], "-t") == 0)
        {
            option = 2;
            heure = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-e") == 0 && option == 2)
        {
            option = 3;
        }
        if (strcmp(argv[i], "-t") == 0 && option == 1)
        {
            option = 3;
            heure = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-g") == 0)
        {
            option = 4;
            fichierDot = argv[i + 1];
        }
    }
    string ligne;
    ifstream fichier("Test.log", ios::in);
    if (fichier)
    {
        while (getline(fichier, ligne))
        {
            Ligne l1 = Ligne(ligne);
            switch (option)
            {
                case 1: // Option -e
                    if (!l1.ExtensionEstImageouJs())
                    {
                        inserer(l1);
                    }
                case 2: // Option -t
                    if (l1.getHeure() >= heure && l1.getHeure() < heure + 1)
                    {
                        inserer(l1);
                    }
                case 3: // Option -e et -t
                    if (l1.getHeure() >= heure && l1.getHeure() < heure + 1 && !l1.ExtensionEstImageouJs())
                    {
                        inserer(l1);
                    }
                default: // Sans option ou option -g
                    inserer(l1);
            }
        }
        fichier.close();
        if (option == 4)
        {
            ofstream fichier(fichierDot, ios::out);
            if (fichier)
            {
                Graphe unGraphe;
                fichier << unGraphe << endl;
            }
            else
                cerr << "Le fichier fourni n'a pas le bon format";
        }
        Classement CiblesLesPlusVisitees = Classement();
        CiblesLesPlusVisitees.afficher();
        
    }
    else cout << "Fichier inexistant" << endl;
    
    return 0;
}























