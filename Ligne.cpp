#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ligne.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ligne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Ligne::decompose(char sep, string uneLigne)
{
    int i = 0;
    char a = uneLigne[i];
    string retour = "";
    while (a != sep)
    {
        retour += a;
        a = uneLigne[++i];
    }
    return retour;
}

void Ligne::afficher()
{
    cout << "Le referer est " << referer << " et l'heure est " << heure << endl;
}

//------------------------------------------------- Surcharge d'opérateurs
Ligne & Ligne::operator = ( const Ligne & unLigne )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Ligne::Ligne ( const Ligne & unLigne )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ligne>" << endl;
#endif
} //----- Fin de Ligne (constructeur de copie)


Ligne::Ligne (string uneLigne)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif
    ip = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, ip.size() + 1, "");
    logName = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, logName.size() + 1, "");
    authenticatedUser = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, authenticatedUser.size() + 2, "");
    jour = decompose('/', uneLigne);
    uneLigne = uneLigne.replace(0, jour.size() + 1, "");
    jour = stoi(jour);
    mois = decompose('/', uneLigne);
    uneLigne = uneLigne.replace(0, mois.size() + 1, "");
    annee = decompose('/', uneLigne);
    uneLigne = uneLigne.replace(0, annee.size() + 2, "");
    annee = stoi(annee);
    heure = decompose(':', uneLigne);
    uneLigne = uneLigne.replace(0, heure.size() + 1, "");
    heure = stoi(heure);
    minute = decompose(':', uneLigne);
    uneLigne = uneLigne.replace(0, minute.size() + 1, "");
    minute = stoi(minute);
    seconde = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, seconde.size() + 1, "");
    seconde = stoi(seconde);
    decalage = decompose(']', uneLigne);
    uneLigne = uneLigne.replace(0, decalage.size() + 3, "");
    action = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, action.size() + 1, "");
    cible = decompose('"', uneLigne);
    uneLigne = uneLigne.replace(0, cible.size() + 2, "");
    status = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, status.size() + 1, "");
    status = stoi(status);
    donnees = decompose(' ', uneLigne);
    uneLigne = uneLigne.replace(0, donnees.size() + 2, "");
    donnees = stoi(donnees);
    referer = decompose('"', uneLigne);
    uneLigne = uneLigne.replace(0, referer.size() + 3, "");
    navigateur = decompose('"', uneLigne);
    uneLigne = uneLigne.replace(0, navigateur.size() + 1, "");

} //----- Fin de Ligne


Ligne::~Ligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
