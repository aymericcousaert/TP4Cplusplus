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
    bool optionG = false;
    bool optionE = false;
    bool optionT = false;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i],"-g") == 0)
        {
            optionG = true;
            fichierDot = argv[i + 1];
        }
        else if (strcmp(argv[i],"-e") == 0)
        {
            optionE = true;
        }
        else if (strcmp(argv[i],"-t") == 0)
        {
            optionT = true;
            heure = atoi(argv[i + 1]);
        }
    }
    string ligneFichier;
    ifstream fichier("Test.log", ios::in);
    if (fichier)
    {
        while (getline(fichier, ligneFichier))
        {
            Ligne ligne = Ligne(ligneFichier);
            if (!optionE && !optionT)
            {
                inserer(ligne);
            }
            else if (!ligne.ExtensionEstImageouJs() && optionE && !optionT)
            {
                inserer(ligne);
            }
            else if (ligne.getHeure() >= heure && ligne.getHeure() < heure + 1 && optionT && !optionE)
            {
                inserer(ligne);
            }
            else if (!ligne.ExtensionEstImageouJs() && ligne.getHeure() >= heure && ligne.getHeure() < heure + 1 && optionE && optionT)
            {
                inserer(ligne);
            }
            else {}
        }
        fichier.close();
        if (optionG)
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























