#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>
using namespace std;

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
    int indMin = 0;
    string top[10];
    int i = 0;
    for (map<string, informations>::iterator it = mapCibles.begin(); it != mapCibles.end(); ++it)
    {
        if (i < 10)
            top[i] = it->first;
        // On calcule le min
        for (int m = 0; m < 10; m++)
        {
            if (mapCibles[top[m]].nbApparition < min)
            {
                min = mapCibles[top[m]].nbApparition;
                indMin = m;
            }
        }
        if (i >= 10)
        {
            // On remplace le min il y a besoin
            cout << "min : " << min << endl;
            cout << "indice min : " << indMin << endl;
            cout << it->second.nbApparition << endl;
            if (it->second.nbApparition > min)
            {
                top[indMin] = it->first;
                cout << it->first << endl << endl;
                // On recalcule le min
                for (int m = 0; m < 10; m++)
                {
                    if (mapCibles[top[m]].nbApparition < min)
                    {
                        min = mapCibles[top[m]].nbApparition;
                        indMin = m;
                    }
                }
            }
            
        }
        
        // cout << it->first << " " << it->second.nbApparition << endl;
        i++;
    }
    for (int m = 0; m < 10; m++)
        cout << top[m] << endl;
    cout << endl;
    // On tri le top obtenu
    string topTrie[10];
    // Tableau qui permet de selectionner à quelles cibles on a encore accès (on va les éliminer au fur et à mesure que le Top 10 se remplit)
    int acces[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int max = 0;
    for (int m = 0; m < 10; m++)
        cout << acces[m] << " ";
    cout << endl;
    for (int j = 0; j < 10; j++)
    {
        max = 0;
        int id = 0;
        for (int k = 0; k < 10; k++)
        {
            if (acces[k] == 1 && mapCibles[top[k]].nbApparition > max)
            {
                max = mapCibles[top[k]].nbApparition;
                id = k;
            }
        }
        acces[id] = 0;
        topTrie[j] = top[id];
        for (int m = 0; m < 10; m++)
            cout << acces[m] << " ";
        cout << endl;
    }
    cout << "Voici le Top 10 :" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ". " << topTrie[i] << " avec " << mapCibles[topTrie[i]].nbApparition << " accès" << endl;
    }
}

int main(int argc, char* argv[])
{

    string ligne;
    ifstream fichier("Test.log", ios::in);
    if (fichier)
    {
        while (getline(fichier, ligne))
        {
            Ligne l1 = Ligne(ligne);
            // l1.afficher();
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
        
        for (map<string, informations>::iterator it = mapCibles.begin(); it != mapCibles.end(); ++it)
        {
            cout << it->first << " \t" << it->second.nbApparition << endl;
        }
        cout << endl;
        cout << endl;
        AfficherTop10();
    }
    else cout << "Fichier inexistant" << endl;

    return 0;
}























