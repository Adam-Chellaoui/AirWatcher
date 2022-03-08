 /*************************************************************************
                           LectureCSV  -  description
                             -------------------
    début                : 30/01/2021
    auteur               : Alexis METWALLI
*************************************************************************/

//---------- Interface de la classe <ReadCSV> (fichier ReadCSV.h) ----------------
#if ! defined ( READCSV_H )
#define READCSV_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <list>
using namespace std;

#include "./Metier/Date.h"
#include "./Metier/Attribute.h"
#include "./Metier/Provider.h"
#include "./Metier/Cleaner.h"
#include "./Metier/User.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ReadCSV>
// Cette classe permet de lire les fichiers CSV
//------------------------------------------------------------------------

class ReadCSV
{
//----------------------------------------------------------------- PUBLIC
public:
//------------------------------------------------------ Attributs publics
//----------------------------------------------------- Méthodes publiques
  void SetMeasurementsCSV(string fileCSV);
  void SetSensorsCSV(string fileCSV);
  void SetCleanersCSV(string fileCSV);
  void SetUsersCSV(string fileCSV);
  void SetProvidersCSV(string fileCSV);
  void SetAttributesCSV(string fileCSV);

  list<Measurement> ReadMeasurements();
  map<string,Sensor> ReadSensors();
  map<string,Cleaner> ReadCleaners();
  map<string,User> ReadUsers();
  map<string,Provider> ReadProviders();
  map<string,Attribute> ReadAttributes();

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
  ReadCSV (string folderName);
  // folderName est le nom du dossier qui contient les fichiersCSV

  virtual ~ReadCSV ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
ifstream measurementsCSV;
ifstream sensorsCSV;
ifstream cleanersCSV;
ifstream usersCSV;
ifstream providersCSV;
ifstream attributesCSV;
//----------------------------------------------------- Attributs protégé

};

//-------------------------------- Autres définitions dépendantes de <ReadCSV>

#endif // READCSV_H
