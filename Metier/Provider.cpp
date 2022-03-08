/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : 29/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <list>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Provider.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Provider::GetId()
{
    return id;
}//----- Fin de GetId()

list<string> Provider::GetCleaners()
{
    return cleaners;
}//----- Fin de GetCleaners()

void Provider::AddCleanerId(string my_cleaner)
{
    cleaners.push_back(my_cleaner);
}//----- Fin de AddCleanersId()

//-------------------------------------------- Constructeurs - destructeur
Provider::Provider(string my_id)
{
    id=my_id;
}//----- Fin de Provider() (constructeur)

Provider::~Provider()
{}//----- Fin de ~Provider() (destructeur)

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

