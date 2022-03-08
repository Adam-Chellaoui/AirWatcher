/*************************************************************************
                           View  -  classe d'affichage
                             -------------------
    début                : 31/05/2021
    auteur               : Alexis Metwalli
*************************************************************************/

//---------- Interface de la classe <View> (fichier View.h) ----------------
#if ! defined (VIEW_H )
#define VIEW__H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

#include "./Metier/Date.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <View>
// Cette classe implémete la partie view de l'architecture MVC
//------------------------------------------------------------------------

class View
{
//----------------------------------------------------------------- PUBLIC
public :
//------------------------------------------------------ Attributs publics

//----------------------------------------------------- Méthodes publiques

    int Menu();
    // Mode d'emploi :
    // Demande quelle fonctionalité l'utilisateur veut utiliser :
    // Si 1, qualité de l'air moyen d'une zone
    // Si 2, qualité d'un capteur
    // Si 0, quitte l'application
    
    void ShowAirQualityAverage(double index);
    void CheckSensorQuality(int quality);
    string AskSensorId();
    void ErrorSensorId(string id);
    Date AskStartDate();
    Date AskEndDate();
    double AskLongitude();
    double AskLatitude();
    double AskRadius();
    bool AskDelete();
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    View();
    ~View();

//------------------------------------------------------------------ PRIVE
protected :
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégé
};

//-------------------------------- Autres définitions dépendantes de <View>

#endif // VIEW_H
