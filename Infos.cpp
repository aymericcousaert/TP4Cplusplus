#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Infos.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Infos::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Infos::Infos ( const Infos & unInfos )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Infos>" << endl;
#endif
} //----- Fin de Infos (constructeur de copie)


Infos::Infos (string uneInfos)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Infos>" << endl;
#endif


} //----- Fin de Infos


Infos::~Infos ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Infos>" << endl;
#endif
} //----- Fin de ~Infos


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
