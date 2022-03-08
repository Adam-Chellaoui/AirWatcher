/*************************************************************************
                           Model  -  description
                             -------------------
    début                : 30/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Réalisation de la classe <Model> (fichier Model.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <map>
#include <utility>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Model.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
map<string,Cleaner> Model::GetCleaners()
{
    return cleaners;
}

map<string,Sensor> Model::GetSensors()
{
    return sensors;
}

map<string,User> Model::GetUsers()
{
    return users;
}

map<string,Attribute> Model::GetAttributes()
{
    return attributes;
}

map<string,Provider> Model::GetProviders()
{
    return providers;
}

void Model::Fill()
{
    // Provider
    providers = fileReader.ReadProviders();

    // Attributes
    attributes = fileReader.ReadAttributes();

    // Cleaners
    cleaners = fileReader.ReadCleaners();
    for(pair<string,Provider> provider : providers)
    {
        for(string cleaner : provider.second.GetCleaners())
        {
            cleaners.find(cleaner)->second.SetProvider(provider.second); 
        }
    }

    // Sensor
    sensors = fileReader.ReadSensors();
    list<Measurement> measures = fileReader.ReadMeasurements();
    for(Measurement m : measures)
    {
        sensors.find(m.GetSensorId())->second.AddMeasurement(m);
    }

    // Users
    users = fileReader.ReadUsers();

}//----- Fin de Fill()


void Model::DeleteSensor(string sensorId)
{
    sensors.erase(sensorId);
}//----- Fin de DeleteSensor()

//-------------------------------------------- Constructeurs - destructeur
Model::Model()
:fileReader("dataset")
{}//----- Fin de Model() (constructeur)

Model::~Model()
{}//----- Fin de ~Model() (destructeur)

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

