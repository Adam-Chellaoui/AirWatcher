/*************************************************************************
                           User  -  description
                             -------------------
    début                : 30/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined (USER_H )
#define USER__H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
using namespace std;

#include "Sensor.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
// Cette classe implémente l'objet user en spécifiant son id, son nombre 
// de points et la liste de ses capteurs.
//------------------------------------------------------------------------

class User
{
//----------------------------------------------------------------- PUBLIC
public :
//------------------------------------------------------ Attributs publics

//----------------------------------------------------- Méthodes publiques
    string GetId();
    int GetNbOfPoints();
    list<string> GetSensors();

    void AddSensorId(string my_sensor);
    void AddPoints(int points);

    void Show();

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    User(string my_id);
    ~User();

//------------------------------------------------------------------ PRIVE
protected :
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégé
    string id;
    int nbOfPoints;
    list<string> sensors;

};

//-------------------------------- Autres définitions dépendantes de <User>

#endif // USER_H
