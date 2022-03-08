/*************************************************************************
                           Controller  -  description
                             -------------------
    début                : 01/06/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Interface de la classe <Controller> (fichier Controller.h) ----------------
#if ! defined (CONTROLLER_H )
#define CONTROLLER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
using namespace std;

#include "Model.h"
#include "View.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Controller>
// Cette classe implémente la partie Controller de l'architecture MVC
//------------------------------------------------------------------------

class Controller 
{
//----------------------------------------------------------------- PUBLIC
public :
//------------------------------------------------------ Attributs publics

//----------------------------------------------------- Méthodes publiques
    void ViewChoice();
    double GetAverageQuality();
    int IsInAverage();
    void LoadData();

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Controller();
    ~Controller();

//------------------------------------------------------------------ PRIVE
protected : 
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégé
    Model model;
    View view;

};
//-------------------------------- Autres définitions dépendantes de <Controller>

#endif // CONTROLLER_H