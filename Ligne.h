/*************************************************************************
 Ligne  -  description
 -------------------
 début                : $Janvier 2019$
 copyright            : $Aymeric Cousaert, Mael Risbourg$
 e-mail               : $aymeric.cousaert@insa-lyon.fr,
                         mael.risbourg@insa-lyon.fr$
 *************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ------------
#if ! defined (LIGNE_H)
#define LIGNE_H
#include <string>
using namespace std;


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
const string EXTENSIONS[9] {".jpg", ".png", ".gif", ".jpeg", ".bmp", ".tif", ".ico", ".css", ".js"};
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ligne>
// Une ligne représente une requête du journal de logs, ses attributs sont
// les diférents éléments qui la composent
//------------------------------------------------------------------------

class Ligne
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    static string decompose(char const sep, string uneLigne);
    // Mode d'emploi :
    // Retourne le sous string de uneLigne qui va du début jusqu'à la première apparition de sep
    // Contrat :
    // Aucun
    
    void afficher() const;
    // Mode d'emploi :
    // Affiche les attributs d'une ligne
    // Contrat :
    // Aucun
    
    string getCible();
    // Mode d'emploi :
    // Retourne la Cible
    // Contrat :
    // Aucun
    
    string getReferer();
    // Mode d'emploi :
    // Retourne le Referer
    // Contrat :
    // Aucun
    
    int getHeure();
    // Mode d'emploi :
    // Retourne l'Heure
    // Contrat :
    // Aucun
    
    bool ExtensionEstImageouJs();
    // Mode d'emploi :
    // Retourne Vrai si la cible de la requête a une extension image ou js, Faux sinon
    // Contrat :
    // Aucun
    
    string getExtension() const;
    // Mode d'emploi :
    // Retourne L'extension
    // Contrat :
    // Aucun
    
    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Ligne(const Ligne & unLigne);
    // Mode d'emploi (constructeur de copie) :
    // Constructeur de copie par défaut de l'objet Ligne
    // Contrat :
    // Aucun
    
    Ligne(string uneLigne);
    // Mode d'emploi :
    // Constructeur de l'objet Ligne
    // Contrat :
    // Aucun
    
    virtual ~Ligne();
    // Mode d'emploi :
    // Destructeur par défaut de l'objet ligne
    // Contrat :
    // Aucun
    
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
    string extension;
    int status;
    string donnees;
    string referer;
    string navigateur;
    
};

//-------------------------------- Autres définitions dépendantes de <Ligne>

#endif // LIGNE_H
