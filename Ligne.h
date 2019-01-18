#if ! defined ( LIGNE_H )
#define LIGNE_H
#include <string>


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ligne>
//
//
//------------------------------------------------------------------------

class Ligne
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    static string decompose(char sep, string uneLigne);
    void afficher();


//------------------------------------------------- Surcharge d'opérateurs
    Ligne & operator = ( const Ligne & unLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Ligne ( const Ligne & unLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ligne (string uneLigne);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Ligne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    string ip;
    string logName;
    string authenticatedUser;
    int jour;
    string mois;
    int annee;
    int heure;
    int minute;
    int seconde;
    string decalage;
    string action;
    string cible;
    int status;
    int donnees;
    string referer;
    string navigateur;

};

//-------------------------------- Autres définitions dépendantes de <Ligne>

#endif // LIGNE_H
