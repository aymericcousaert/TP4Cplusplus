#if ! defined ( INFOS_H )
#define INFOS_H
#include <string>
using namespace std;


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Infos>
//
//
//------------------------------------------------------------------------

class Infos : public Ligne
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Infos ( const Infos & unInfos );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Infos (string uneInfos);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Infos ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés


};

//-------------------------------- Autres définitions dépendantes de <Infos>

#endif // Infos_H
