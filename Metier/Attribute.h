/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : 29/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Interface de la classe <Attribute> (fichier Attribute.h) ----------------
#if ! defined (ATTRIBUTE_H )
#define ATTRIBUTE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribute>
// Cette classe implémente l'objet attribute
//------------------------------------------------------------------------

class Attribute 
{
//----------------------------------------------------------------- PUBLIC
public :
//------------------------------------------------------ Attributs publics

//----------------------------------------------------- Méthodes publiques
    string GetId();
    string GetUnit();
    string GetDescription();

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Attribute(string my_id, string my_unit, string my_description);
    ~Attribute();

//------------------------------------------------------------------ PRIVE
protected : 
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégé
    string id;
    string unit;
    string description;
};
//-------------------------------- Autres définitions dépendantes de <Attribute>

#endif // ATTRIBUTE_H