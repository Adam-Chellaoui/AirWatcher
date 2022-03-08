/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : 29/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Interface de la classe <Measurement> (fichier Measurement.h) ----------------
#if ! defined (MEASUREMENT_H )
#define MEASUREMENT__H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

#include "Date.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurement>
// Cette classe implémente une mesure en spécifiant la date de la mesure,
// l'id du capteur correspondant, son attribut et sa valeur.
//------------------------------------------------------------------------

class Measurement 
{
//----------------------------------------------------------------- PUBLIC
public :
//------------------------------------------------------ Attributs publics

//----------------------------------------------------- Méthodes publiques
    string GetSensorId();
    Date GetTime();
    string GetAttribute();
    double GetValue();

    void Show();
    // Mode d'emploi :
    // Affiche la mesure que contient this sous le format :
    // time;sensorId;attribute;value;

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Measurement(Date my_time, string my_sensorId, string my_attribute, double my_value);
    ~Measurement();

//------------------------------------------------------------------ PRIVE
protected : 
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégé
    Date time;
    string sensorId;
    string attribute;
    double value;
};

//-------------------------------- Autres définitions dépendantes de <Measurement>

#endif // MEASUREMENT_H