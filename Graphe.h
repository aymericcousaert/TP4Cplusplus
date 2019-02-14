/*************************************************************************
 Graphe  -  description
 -------------------
 début                : $Janvier 2019$
 copyright            : $Aymeric Cousaert, Mael Risbourg$
 e-mail               : $aymeric.cousaert@insa-lyon.fr,
 mael.risbourg@insa-lyon.fr$
 *************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------------
#if ! defined ( GRAPHE_H )
#define GRAPHE_H

//--------------------------------------------------- Interfaces utilisées
#include "Classement.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
//
//
//------------------------------------------------------------------------

class Graphe 
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
   
    //------------------------------------------------- Surcharge d'opérateurs
    friend ostream & operator<<(ostream & flux, Graphe & unGraphe);
    // Mode d'emploi :
    // Surcharge de l'opérateur <<
    // Contrat :
    // Aucun
    
    //-------------------------------------------- Constructeurs - destructeur
    Graphe(const Graphe & unGraphe);
    // Mode d'emploi (constructeur de copie) :
    // Constructeur de copie par défaut de l'objet graphe
    // Contrat :
    // Aucun
    
    Graphe();
    // Mode d'emploi :
    // Constructeur de l'objet graphe
    // Contrat :
    // Aucun
    
    virtual ~Graphe();
    // Mode d'emploi :
    // Destructeur par défaut de l'objet graphe
    // Contrat :
    // Aucun
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    map<string,string> tabNoeud;
};

//-------------------------------- Autres définitions dépendantes de <Graphe>

#endif // GRAPHE_H
