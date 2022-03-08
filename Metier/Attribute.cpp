/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : 29/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Réalisation de la classe <Attribute> (fichier Attribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Attribute.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Attribute::GetId()
{
    return id;
}//----- Fin de GetId()

string Attribute::GetUnit()
{
    return unit;
}//----- Fin de GetUnit()

string Attribute::GetDescription()
{
    return description;
}//----- Fin de GetDescription()

//-------------------------------------------- Constructeurs - destructeur
Attribute::Attribute(string my_id, string my_unit , string my_description)
{
    id=my_id;
    unit=my_unit;
    description=my_description;

}//----- Fin de Attribute() (constructeur)

Attribute::~Attribute()
{}//----- Fin de Attribute() (destructeur)

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

