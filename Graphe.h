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
    // type Méthode(liste des paramètres);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //------------------------------------------------- Surcharge d'opérateurs
    
    
    //-------------------------------------------- Constructeurs - destructeur
    Graphe(const Graphe & unGraphe);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    Graphe();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Graphe();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    
};

//-------------------------------- Autres définitions dépendantes de <Graphe>

#endif // GRAPHE_H


