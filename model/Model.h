/*************************************************************************
                           Model  -  description
                             -------------------
    début                : 31/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Interface de la classe <Model> (fichier Model.h) ----------------
#if ! defined (MODEL_H )
#define MODEL_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
using namespace std;

#include "ReadCSV.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Model>
// Cette classse implémente la partie modèle de l'architecture MVC
//------------------------------------------------------------------------

class Model 
{
//----------------------------------------------------------------- PUBLIC
public :
//------------------------------------------------------ Attributs publics

//----------------------------------------------------- Méthodes publiques
    map<string,Cleaner> GetCleaners();
    map<string,Sensor> GetSensors();
    map<string,User> GetUsers();
    map<string,Attribute> GetAttributes();
    map<string,Provider> GetProviders();
    
    void Fill();
    void DeleteSensor(string sensorId);

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Model();
    virtual ~Model();

//------------------------------------------------------------------ PRIVE
protected : 
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégé
    ReadCSV fileReader;
    map<string,Cleaner> cleaners;
    map<string,Sensor> sensors;
    map<string,User> users;
    map<string,Attribute> attributes;
    map<string,Provider> providers;

    
};
//-------------------------------- Autres définitions dépendantes de <Model>

#endif // MODEL_H