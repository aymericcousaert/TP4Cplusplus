/*************************************************************************
 Classement  -  description
 -------------------
 début                : $Janvier 2019$
 copyright            : $Aymeric Cousaert, Mael Risbourg$
 e-mail               : $aymeric.cousaert@insa-lyon.fr,
                         mael.risbourg@insa-lyon.fr$
 *************************************************************************/

//---------- Interface de la classe <Classement> (fichier Classement.h) --
#if ! defined (CLASSEMENT_H)
#define CLASSEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <set>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef
struct informations
{
    int nbApparition;
    map<string, int> mapReferers;
} informations;

extern map<string, informations> mapCibles;

//------------------------------------------------------------------------
// Rôle de la classe <Classement>
// Cette classe constitue le classement des cibles les plus visitées
//
//------------------------------------------------------------------------

class Classement 
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    void afficher() const;
    // Mode d'emploi :
    // Affiche le classement
    // Contrat :
    // Aucun
    
    //------------------------------------------------- Surcharge d'opérateurs
    
    //-------------------------------------------- Constructeurs - destructeur
    Classement(const Classement & unClassement);
    // Mode d'emploi (constructeur de copie) :
    // Constructeur de copie par défaut de l'objet classement
    // Contrat :
    // Aucun
    
    Classement();
    // Mode d'emploi :
    // Constructeur de l'objet classement
    // Contrat :
    // Aucun
    
    virtual ~Classement();
    // Mode d'emploi :
    // Destructeur par défaut de l'objet classement
    // Contrat :
    // Aucun
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    string top[10];
};

//-------------------------------- Autres définitions dépendantes de <Classement>

#endif // CLASSEMENT_H
