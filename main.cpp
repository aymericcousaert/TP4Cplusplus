#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>

#include "Ligne.h"


typedef
struct informations
{
    int nbApparition;
    map<string, int> mapReferers;
} informations;

map<string, informations> mapCibles;


informations remplissage(Ligne& uneLigne)
{
    informations infos;
    infos.nbApparition = 1;
    infos.mapReferers.insert(pair<string,int>(uneLigne.getReferer(), 1));

    return infos;
}

void AfficherTop10()
{
    int min = 2147483647;
    string top[10];
    int i = 0;
    for (map<string, informations>::iterator it = mapCibles.begin(); it != mapCibles.end(); ++it)
    {
        if (i < 10)
        {
            top[i] = it->first;
            if (it->second.nbApparition < min)
                min = it->second.nbApparition;
        }
        else
            if (it->second.nbApparition > min) // On remplace le plus petit
            {
                for (int j = 0; j < 10; j++)
                {
                    if (mapCibles[top[j]].nbApparition == min)
                        top[j] = it->first;
                }
                //recalcule du min
                min = top[0];
                for (int j = 1; j < 10; j++)
                {
                    if (mapCibles[top[j]].nbApparition < min)
                        min = mapCibles[top[j]].nbApparition ;
                }
            }


        cout << it->first << " " << it->second.nbApparition << endl;

        i++;
    }
    int max = 0;
    for (int j = 0; j < 10; j++) {
        int id =0;
        max = 0;
        for (int k = 0; k < 10; k++)
        {
            if (mapCibles[top[j]].nbApparition > max)
            {
                max = mapCibles[top[j]].nbApparition;
                id = k;
            }
        }
        cout << top[id] << "  " << top[id].nbApparition;
        top[id] = 0;
}


}

int main(int argc, char* argv[])
{

    string ligne;
    ifstream fichier("Test.log",ios::in);
    if (fichier)
    {
        while (getline(fichier, ligne))
        {
            Ligne l1 = Ligne(ligne);
             l1.afficher();
            if (mapCibles.find(l1.getCible()) == mapCibles.end())
            {
                informations infos = remplissage(l1);
                mapCibles.insert(pair<string,informations>(l1.getCible(), infos));
            }
            else if (mapCibles[l1.getCible()].mapReferers.find(l1.getReferer()) == mapCibles[l1.getCible()].mapReferers.end())
            {
                mapCibles[l1.getCible()].mapReferers.insert(pair<string,int>(l1.getReferer(),1));
                mapCibles[l1.getCible()].nbApparition++;
            }
            else
            {
                mapCibles[l1.getCible()].mapReferers[l1.getReferer()]++;
                mapCibles[l1.getCible()].nbApparition++;
            }
        }
        fichier.close();
        AfficherTop10();
    }
    else cout << "Fichier inexistant" << endl;

    return 0;
}























