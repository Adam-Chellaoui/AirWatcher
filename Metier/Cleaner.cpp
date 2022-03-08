/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : 29/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Cleaner::GetId()
{
    return id;
}//----- Fin de GetId()

Date Cleaner::GetStartTime()
{
    return startTime;
}//---- Fin de GetStartTime()

Date Cleaner::GetEndTime()
{
    return endTime;
}//---- Fin de GetEndTime()

double Cleaner::GetLatitude()
{
    return latitude;
}//----- Fin de GetLattitude()

double Cleaner::GetLongitude()
{
    return longitude;
}//----- Fin de GetLongitude()

string Cleaner::GetProvider()
{
    return provider;
}//----- Fin de GetProvider();

void Cleaner::SetProvider(Provider my_provider)
{
    provider = my_provider.GetId();
}//----- Fin de SetProvider()

void Cleaner::Show()
{
    cout << id << ";" << latitude << ";" << longitude << ";";
    startTime.Show();
    cout << ";";
    endTime.Show();
    cout << ";" << provider << ";";
}//----- Fin de Show()

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner(string my_id, double my_latitude, double my_longitude, Date my_startTime, Date my_endTime)
{
    id=my_id;
    startTime=my_startTime;
    endTime=my_endTime;
    latitude=my_latitude;
    longitude=my_longitude;
}//----- Fin de Cleaner() (constructeur)

Cleaner::~Cleaner()
{} //----- Fin de ~Cleaner() (destructeur)

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
