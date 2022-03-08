/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 30/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined (SENSOR_H )
#define SENSOR__H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
using namespace std;

#include "Measurement.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
// Cette classe implémente l'objet sensor. Elle spécifie son id, sa position
// et ses mesures.
//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC
public :
//------------------------------------------------------ Attributs publics

//----------------------------------------------------- Méthodes publiques
    string GetId();
    double GetLatitude();
    double GetLongitude();
    list<Measurement> GetMeasurements();

    void AddMeasurement(Measurement my_measurement);

    void Show();

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Sensor(string my_id, double my_latitude,double my_longitude);
    ~Sensor();

//------------------------------------------------------------------ PRIVE
protected :
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégé
    string id;
    double latitude;
    double longitude;
    list<Measurement> measurements;

};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H
