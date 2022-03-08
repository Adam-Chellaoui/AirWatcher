/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : 29/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined (PROVIDER_H )
#define PROVIDER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
// Cette classe permet d'implémenter l'objet Provider tout en prévoyant
// un éventuel ajout dans le futur d'attributs à cet objet.
//------------------------------------------------------------------------

class Provider 
{
//----------------------------------------------------------------- PUBLIC
public :
//------------------------------------------------------ Attributs publics

//----------------------------------------------------- Méthodes publiques
    string GetId();
    list<string> GetCleaners();
    void AddCleanerId(string my_cleaner);

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Provider(string my_id);
    ~Provider();

//------------------------------------------------------------------ PRIVE
protected : 
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégé
    string id;
    list<string> cleaners;
};
//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // PROVIDER_H