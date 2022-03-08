/*************************************************************************
                           Date  -  description
                             -------------------
    début                : 29/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#if ! defined (DATE_H )
#define DATE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Date>
// Date implémente un objet Date et des méthodes qui faciliteront l'usage 
// de durée et de dates dans le projet
//------------------------------------------------------------------------

class Date 
{
//----------------------------------------------------------------- PUBLIC
public :
//------------------------------------------------------ Attributs publics

//----------------------------------------------------- Méthodes publiques
    // Getter
    int GetYear();
    int GetMonth();
    int GetDay();
    int GetHour();
    int GetMinute();
    int GetSecond();

    void Show();
    // Mode d'emploi :
    // Affiche l'objet pointé par this sur le console
    // dans le format : AAAA-MM-DD HH:MM:SS

//------------------------------------------------- Surcharge d'opérateurs
    bool operator <=(const Date & date);
    bool operator >=(const Date & date);

//-------------------------------------------- Constructeurs - destructeur
    Date();
    Date(string dateString);
    ~Date();

//------------------------------------------------------------------ PRIVE
protected : 
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégé
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};
//-------------------------------- Autres définitions dépendantes de <Date>

#endif // DATE_H