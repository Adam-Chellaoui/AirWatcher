/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : 29/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if ! defined (CLEANER_H )
#define CLEANER__H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

#include "Date.h"
#include "Provider.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
// Cette classe implémente l'objet Cleaner en spécifiant son id, sa date de
// début, sa date de fin, ses coordonnées et le propriétaire.
//------------------------------------------------------------------------

class Cleaner
{
//----------------------------------------------------------------- PUBLIC
public :
//------------------------------------------------------ Attributs publics

//----------------------------------------------------- Méthodes publiques
    string GetId();
    Date GetStartTime();
    Date GetEndTime();
    double GetLatitude();
    double GetLongitude();
    string GetProvider();

    void SetProvider(Provider my_provider);

    void Show();

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Cleaner(string my_id, double my_latitude, double my_longitude, Date my_startTime, Date my_endTime);
    ~Cleaner();

//------------------------------------------------------------------ PRIVE
protected :
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégé
  string id;
  Date startTime;
  Date endTime;
  double latitude;
  double longitude;
  string provider;
};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // CLEANER_H
