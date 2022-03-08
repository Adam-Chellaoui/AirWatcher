/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 30/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Sensor::GetId()
{
    return id;
}//----- Fin de GetId()

double Sensor::GetLatitude()
{
    return latitude;
}//----- Fin de GetLatitude()

double Sensor::GetLongitude()
{
    return longitude;
}//----- Fin de GetLongitude()

list<Measurement> Sensor::GetMeasurements()
{
    return measurements;
}//----- Fin de GetSensors()

void Sensor::AddMeasurement(Measurement my_measurement)
{
  measurements.push_back(my_measurement);
}//----- Fin de AddMeasurements() 

void Sensor::Show()
{
    cout << "======== Capteur : " << id << " ========" << endl;
    cout << "    -> Coordonées : " << latitude << ";" << longitude << " <-" << endl;
    cout << "Mesures : " << endl;
    list<Measurement>::iterator measure = measurements.begin();
    while(measure != measurements.end())
    {
        measure->Show();
        cout << endl;
        measure ++;
    }
    cout << "===================================";
}//----- Fin de Show()

//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor(string my_id, double my_latitude,double my_longitude)
{
    id=my_id;
    latitude=my_latitude;
    longitude=my_longitude;

}//----- Fin de Sensor() (constructeur)

Sensor::~Sensor()
{} //----- Fin de ~Sensor() (destructeur)

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
