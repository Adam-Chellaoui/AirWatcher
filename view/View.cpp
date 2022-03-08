/*************************************************************************
                           View  -  classe d'affichage
                             -------------------
    début                : 31/05/2021
    auteur               : Alexis Metwalli
*************************************************************************/

//---------- Réalisation de la classe <View> (fichier View.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "View.h"
#include "./Metier/Date.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int View::Menu(){
  int choix = -1;
  while(choix == -1){
    cout<<"##############################################################################"<<endl;
    cout<<"Bienvenue sur AirWatcher, choisissez une des fonctionalitées ci dessous :"<<endl;
    cout<<"1 - Obtenez la qualité de l'air moyen d'une zone géographique"<<endl;
    cout<<"2 - Verifiez la véridicité d'un capteur donné"<<endl;
    cout<<"##############################################################################"<<endl;
    cout<<"Insérez l'indice correspondant à votre choix, tapez 0 pour quitter : ";
    cin>>choix;
    cin.ignore();
    cout<<endl;
    if(choix == 1)
    {
      return choix;
    } else if(choix == 2)
    {
      return choix;
    } else if(choix == 0)
    {
      return choix;
    } else 
    {
      cout<<"Veuillez entrer un indice correct"<<endl;
      choix = -1;
    }
  }
}

void View::ShowAirQualityAverage(double index){
  cout<<"##############################################################################"<<endl;
  if(index == 0)
  {
    cout << "Erreur : index = ";
  } else if(index <= 2)
  {
    cout << "La qualité de l'air pour cette zone sur ces dates est EXCELLENTE." << endl;
    cout << "Index = ";
  }else if(index <= 4)
  {
    cout << "La qualité de l'air pour cette zone sur ces dates est BONNE." << endl;
    cout << "Index = ";
  }else if(index == 5)
  {
    cout << "La qualité de l'air pour cette zone sur ces dates est MOYENNE." << endl;
    cout << "Index = ";
  }
  else if(index <= 7)
  {
    cout << "La qualité de l'air pour cette zone sur ces dates est MEDIOCRE." << endl;
    cout << "Index = ";
  } else if(index <= 9)
  {
    cout << "La qualité de l'air pour cette zone sur ces dates est MAUVAISE." << endl;
    cout << "Index = ";
  } else {
    cout << "La qualité de l'air pour cette zone sur ces dates est TRES MAUVAISE." << endl;
    cout << "Index = ";
  }
  cout << index << endl;
  cout << endl;
  cout << "C'est la méthode de calcul antérieure à 2020 qui est utilisée" << endl;
  cout << "Appuyez sur entrée pour revenir au menu principal" << endl;
  cout<<"##############################################################################"<<endl;
  cin.ignore();
}

void View::CheckSensorQuality(int quality){
  if(quality == 1){
    cout<<"##############################################################################"<<endl;
    cout<<"Pas de problème, votre capteur marche normalement"<<endl;
    cout << "Appuyez sur entrée pour revenir au menu principal" << endl;
    cout<<"##############################################################################"<<endl;
    cin.ignore();
  } else if(quality == 0) 
  {
    cout<<"##############################################################################"<<endl;
    cout<<"Attention les données fournies par votre capteur sont erronées !!"<<endl;
    cout<<"Le capteur a été supprimé de la base de donnée." << endl;
    cout << "Appuyez sur entrée pour revenir au menu principal" << endl;
    cout<<"##############################################################################"<<endl;
    cin.ignore();
  }
}

string View::AskSensorId(){
  string sensorId;
  cout<<"##############################################################################"<<endl;
  cout<<"Entrez l'ID du capteur : "<<endl;
  cin>>sensorId;
  cin.ignore();
  cout<<endl;
  return sensorId;
}

void View::ErrorSensorId(string id)
{
  cout<<"##############################################################################"<<endl;
  cout << "Le capteur " << id << " n'existe pas" << endl;
}

Date View::AskStartDate(){
  string date;
  while(1)
  {
    cout<<"##############################################################################"<<endl;
    cout<<"Entrez la date de debut d'analyse (yyyy-MM-dd,hh:mm:ss) : ";
    cin>>date;
    cin.ignore();
    try
    {
      Date d(date);
      return d;
    }
    catch(const exception& e)
    {
      cout << "Format incorrect";
    }
    cout<<endl;
  }
}

Date View::AskEndDate(){
  string date;
  while(1)
  {
    cout<<"##############################################################################"<<endl;
    cout<<"Entrez la date de fin d'analyse (yyyy-MM-dd,hh:mm:ss) : ";
    cin>>date;
    cin.ignore();
    try
    {
      Date d(date);
      return d;
    }
    catch(const exception& e)
    {
      cout << "Format incorrect";
    }
    cout<<endl;
  }
}

double View::AskLongitude(){
  double longitude;
  cout<<"##############################################################################"<<endl;
  cout<<"Entrez la longitude : ";
  cin>>longitude;
  cin.ignore();
  cout<<endl;
  return longitude;
}
double View::AskLatitude(){
  double lat;
  cout<<"##############################################################################"<<endl;
  cout<<"Entrez la latitude : ";
  cin>>lat;
  cin.ignore();
  cout<<endl;
  return lat;
}
double View::AskRadius(){
  double radius;
  cout<<"##############################################################################"<<endl;
  cout<<"Entrez votre rayon : ";
  cin>>radius;
  cin.ignore();
  cout<<endl;
  return radius;
}
bool View::AskDelete()
{
  char answer;
  cout <<"##############################################################################"<<endl;
  cout <<"Voulez-vous supprimer le capteur ? [o/n] : ";
  cin >> answer;
  cin.ignore();
  cout << endl;
  return answer == 'o';
}
//-------------------------------------------- Constructeurs - destructeur
View::View ()
{

#ifdef MAP
    cout << "Appel au constructeur de <View>" << endl;
#endif
} //----- Fin de View (constructeur par défaut)


View::~View ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <View>" << endl;
#endif
} //----- Fin de ~View (destructeur)


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
