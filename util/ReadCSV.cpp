/*************************************************************************
                           ReadCSV  -  description
                             -------------------
    début                : 30/01/2021
    auteur               : Alexis METWALLI
*************************************************************************/

//---------- Réalisation de la classe <ReadCSV> (fichier ReadCSV.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ReadCSV.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ReadCSV::SetMeasurementsCSV(string fileCSV)
{
  if(measurementsCSV.is_open())
  {
    measurementsCSV.close();
  }
  measurementsCSV.open(fileCSV);
}//----- Fin de SetMeasurementsCSV()

void ReadCSV::SetSensorsCSV(string fileCSV)
{
  if(sensorsCSV.is_open())
  {
    sensorsCSV.close();
  }
  sensorsCSV.open(fileCSV);
}//----- Fin de SetSensorsCSV()

void ReadCSV::SetCleanersCSV(string fileCSV)
{
  if(cleanersCSV.is_open())
  {
    cleanersCSV.close();
  }
  cleanersCSV.open(fileCSV);
}//----- Fin de SetCleanersCSV()

void ReadCSV::SetUsersCSV(string fileCSV)
{
  if(usersCSV.is_open())
  {
    usersCSV.close();
  }
  usersCSV.open(fileCSV);
}//----- Fin de SetUsersCSV()

void ReadCSV::SetProvidersCSV(string fileCSV)
{
  if(providersCSV.is_open())
  {
    providersCSV.close();
  }
  providersCSV.open(fileCSV);
}//----- Fin de SetProvidersCSV()

void ReadCSV::SetAttributesCSV(string fileCSV)
{
  if(attributesCSV.is_open())
  {
    attributesCSV.close();
  }
  attributesCSV.open(fileCSV);
}//----- Fin de SetAttributesCSV

list<Measurement> ReadCSV::ReadMeasurements(){
  list<Measurement> measurements;
  string line;
  while(std::getline(measurementsCSV,line)){
    stringstream ss(line);
    string sdate;
    std::getline(ss,sdate,';');
    Date date(sdate);
    string id;
    std::getline(ss,id,';');
    string attribute;
    std::getline(ss,attribute,';');
    string svalue;
    std::getline(ss,svalue,';');
    double value = atof(svalue.c_str());
    measurements.push_back(Measurement(date,id,attribute,value));
  }
  return measurements;
}//----- Fin de ReadMeasurements()

map<string,Sensor> ReadCSV::ReadSensors(){
  map<string,Sensor> sensors;
  string line;
  while(std::getline(sensorsCSV,line)){
    stringstream ss(line);
    string id;
    std::getline(ss,id,';');
    string slat;
    std::getline(ss,slat,';');
    double latitude = atof(slat.c_str());
    string slong;
    std::getline(ss,slong,';');
    double longitude = atof(slong.c_str());
    sensors.insert(make_pair(id,Sensor(id,latitude,longitude)));
  }
  return sensors;
}//----- Fin de ReadSensors()

map<string,Cleaner> ReadCSV::ReadCleaners(){
  map<string,Cleaner> cleaners;
  string line;
  while(std::getline(cleanersCSV,line)){
    stringstream ss(line);
    string id;
    std::getline(ss,id,';');
    string slat;
    std::getline(ss,slat,';');
    double latitude = atof(slat.c_str());
    string slong;
    std::getline(ss,slong,';');
    double longitude = atof(slong.c_str());
    string sdatedebut;
    std::getline(ss,sdatedebut,';');
    Date dateDebut(sdatedebut);
    string sdatefin;
    std::getline(ss,sdatefin,';');
    Date dateFin(sdatefin);
    cleaners.insert(make_pair(id,Cleaner(id,latitude,longitude,dateDebut,dateFin)));
  }
  return cleaners;
}//----- Fin de ReadCleaners()

map<string,User> ReadCSV::ReadUsers(){
  map<string,User> users;
  string line;
  while(std::getline(usersCSV,line)){
    stringstream ss(line);
    string id;
    std::getline(ss,id,';');
    string sensorId;
    std::getline(ss,sensorId,';');
    if(users.find(id) != users.end()){//Si l'id est déja présent dans la map
      users.find(id)->second.AddSensorId(sensorId);
    } else {
      User user(id);
      user.AddSensorId(sensorId);
      users.insert(make_pair(id,user));
    }
  }
  return users;
}//----- Fin de ReadUsers()

map<string,Provider> ReadCSV::ReadProviders(){
  map<string,Provider> providers;
  string line;
  while(std::getline(providersCSV,line)){
    stringstream ss(line);
    string id;
    std::getline(ss,id,';');
    string cleanerId;
    std::getline(ss,cleanerId,';');
    if(providers.find(id) != providers.end()){//Si l'id est déja présent dans la map
      providers.find(id)->second.AddCleanerId(cleanerId);
    } else {
      Provider provider(id);
      provider.AddCleanerId(cleanerId);
      providers.insert(make_pair(id,provider));
    }
  }
  return providers;
}//---- Fin de ReadProviders()

map<string,Attribute> ReadCSV::ReadAttributes(){
  map<string,Attribute> attributes;
  string line;
  std::getline(attributesCSV,line);//Première ligne inutile
  while(std::getline(attributesCSV,line)){
    stringstream ss(line);
    string id;
    std::getline(ss,id,';');
    string unit;
    std::getline(ss,unit,';');
    string description;
    std::getline(ss,description,';');
    attributes.insert(make_pair(id,Attribute(id,unit,description)));
  }
  return attributes;
}//----- Fin de ReadAttributes()

//-------------------------------------------- Constructeurs - destructeur
ReadCSV::ReadCSV (string folderName)
{
  measurementsCSV.open(folderName+"/measurements.csv");
  sensorsCSV.open(folderName+"/sensors.csv");
  cleanersCSV.open(folderName+"/cleaners.csv");
  usersCSV.open(folderName+"/users.csv");
  providersCSV.open(folderName+"/providers.csv");
  attributesCSV.open(folderName+"/attributes.csv");

#ifdef MAP
    cout << "Appel au constructeur de <ReadCSV>" << endl;
#endif
} //----- Fin de ReadCSV


ReadCSV::~ReadCSV ()
{
  measurementsCSV.close();
  sensorsCSV.close();
  cleanersCSV.close();
  usersCSV.close();
  providersCSV.close();
  attributesCSV.close();
#ifdef MAP
    cout << "Appel au destructeur de <ReadCSV>" << endl;
#endif
} //----- Fin de ~ReadCSV (destructeur)


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
