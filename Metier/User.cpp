/*************************************************************************
                           User  -  description
                             -------------------
    début                : 30/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
using namespace std;

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string User::GetId()
{
    return id;
}//----- Fin de GetId()

int User::GetNbOfPoints()
{
    return nbOfPoints;
}//----- Fin de GetNbOfPoints()

list<string> User::GetSensors()
{
    return sensors;
}//----- Fin de GetSensors()

void User::AddSensorId(string my_sensor)
{
  sensors.push_back(my_sensor);
}//----- Fin de AddSensor()

void User::AddPoints(int points)
{
    nbOfPoints += points;
}//----- Fin de AddPoints()

void User::Show()
{
    cout << "======== User : " << id << " ========" << endl;
    cout << "    -> Nb de points : " << nbOfPoints << " <-" << endl;
    cout << "Capteurs : " << endl;
    list<string>::iterator sensor = sensors.begin();
    while(sensor != sensors.end())
    {
        cout << "     -  " << *sensor;
        cout << endl;
        sensor ++;
    }
    cout << "===================================";
}//----- Fin de Show()

//-------------------------------------------- Constructeurs - destructeur
User::User(string my_id)
{
    id=my_id;
    nbOfPoints=0;
}//----- Fin de User() (constructeur)

User::~User()
{} //----- Fin de ~User() (destructeur)

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
