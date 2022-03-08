/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : 29/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Réalisation de la classe <Measurement> (fichier Measurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Measurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Measurement::GetSensorId()
{
    return sensorId;
}//----- Fin de GetSensorId()

Date Measurement::GetTime()
{
    return time;
}//---- Fin de GetTime()

string Measurement::GetAttribute()
{
    return attribute;
}//----- Fin de GetAttribute()

double Measurement::GetValue()
{
    return value;
}//----- Fin de GetValue()

void Measurement::Show()
{
    time.Show();
    cout << ";" << sensorId << ";" << attribute << ";" << value << ";";
}//----- Fin de Show()

//-------------------------------------------- Constructeurs - destructeur
Measurement::Measurement(Date my_time, string my_sensorId, string my_attribute, double my_value)
{
    time=my_time;
    sensorId=my_sensorId;
    attribute=my_attribute;
    value=my_value;
}//----- Fin de Measurement() (constructeur)

Measurement::~Measurement() 
{} //----- Fin de ~Measurement() (destructeur)

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
