/*************************************************************************
                           Controller  -  description
                             -------------------
    début                : 01/06/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Réalisation de la classe <Controller> (fichier Controller.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Controller.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Controller::ViewChoice()
{
    int choice = view.Menu();
    while(choice != 0)
    {
        if(choice == 1)
        {
            view.ShowAirQualityAverage(GetAverageQuality());
        } else if(choice == 2)
        {
            view.CheckSensorQuality(IsInAverage());
        }
        choice = view.Menu();
    }
}//----- Fin de ViewChoice()

int AtmoIndex(double measures[4])
{
    int indexO3 = 0;
    if(measures[0] <= 29)
    {
        indexO3 = 1;
    } else if(measures[0] <= 54)
    {
        indexO3 = 2;
    } else if(measures[0] <= 79)
    {
        indexO3 = 3;
    } else if(measures[0] <= 104)
    {
        indexO3 = 4;
    } else if(measures[0] <= 129)
    {
        indexO3 = 5;
    } else if(measures[0] <= 149)
    {
        indexO3 = 6;
    } else if(measures[0] <= 179)
    {
        indexO3 = 7;
    } else if(measures[0] <= 209)
    {
        indexO3 = 8;
    } else if(measures[0] <= 239)
    {
        indexO3 = 9;
    } else 
    {
        indexO3 = 10;
    }

    int indexSO2 = 0;
    if(measures[1] <= 39)
    {
        indexSO2 = 1;
    } else if(measures[1] <= 79)
    {
        indexSO2 = 2;
    } else if(measures[1] <= 119)
    {
        indexSO2 = 3;
    } else if(measures[1] <= 159)
    {
        indexSO2 = 4;
    } else if(measures[1] <= 199)
    {
        indexSO2 = 5;
    } else if(measures[1] <= 249)
    {
        indexSO2 = 6;
    } else if(measures[1] <= 299)
    {
        indexSO2 = 7;
    } else if(measures[1] <= 399)
    {
        indexSO2 = 8;
    } else if(measures[1] <= 499)
    {
        indexSO2 = 9;
    } else 
    {
        indexSO2 = 10;
    }

    int indexNO2 = 0;
    if(measures[2] <= 29)
    {
        indexNO2 = 1;
    } else if(measures[2] <= 54)
    {
        indexNO2 = 2;
    } else if(measures[2] <= 84)
    {
        indexNO2 = 3;
    } else if(measures[2] <= 109)
    {
        indexNO2 = 4;
    } else if(measures[2] <= 134)
    {
        indexNO2 = 5;
    } else if(measures[2] <= 164)
    {
        indexNO2 = 6;
    } else if(measures[2] <= 199)
    {
        indexNO2 = 7;
    } else if(measures[2] <= 274)
    {
        indexNO2 = 8;
    } else if(measures[2] <= 399)
    {
        indexNO2 = 9;
    } else 
    {
        indexNO2 = 10;
    }

    int indexPM10 = 0;
    if(measures[3] <= 6)
    {
        indexPM10 = 1;
    } else if(measures[3] <= 13)
    {
        indexPM10 = 2;
    } else if(measures[3] <= 20)
    {
        indexPM10 = 3;
    } else if(measures[3] <= 27)
    {
        indexPM10 = 4;
    } else if(measures[3] <= 34)
    {
        indexPM10 = 5;
    } else if(measures[3] <= 41)
    {
        indexPM10 = 6;
    } else if(measures[3] <= 49)
    {
        indexPM10 = 7;
    } else if(measures[3] <= 64)
    {
        indexPM10 = 8;
    } else if(measures[3] <= 79)
    {
        indexPM10 = 9;
    } else 
    {
        indexPM10 = 10;
    }

    return max(indexO3,max(indexSO2,max(indexNO2,indexPM10)));
}

double Controller::GetAverageQuality()
{
    // On récupère les paramètres
    Date start = view.AskStartDate();
    Date end = view.AskEndDate();
    double latitude = view.AskLatitude();
    double longitude = view.AskLongitude();
    double radius = view.AskRadius();

    // Calcul
    double moyenne = 0;
    double  nb = 0;
    for(pair<string, Sensor> sensor : model.GetSensors())
    {
        // On test si le capteur est dans le rayon indiqué.
        if(abs(sensor.second.GetLatitude()-latitude) <= radius && abs(sensor.second.GetLongitude()-longitude) <= radius)
        {
            double measures[4] = {0,0,0,0};
            int nbOfMeasure[4] = {0,0,0,0};
            for(Measurement measure : sensor.second.GetMeasurements())
            {
                if(measure.GetTime() >= start && measure.GetTime() <= end)
                {
                    if(measure.GetAttribute() == "O3")
                    {
                        measures[0] += measure.GetValue();
                        nbOfMeasure[0] ++;
                    } else if (measure.GetAttribute() == "SO2")
                    {
                        measures[1] += measure.GetValue();
                        nbOfMeasure[1] ++;
                    } else if (measure.GetAttribute() == "NO2")
                    {
                        measures[2] += measure.GetValue();
                        nbOfMeasure[2] ++;
                    } else if (measure.GetAttribute() == "PM10")
                    {
                        measures[3] += measure.GetValue();
                        nbOfMeasure[3] ++;
                    } 
                }
            }

            for(int i = 0; i < 4; i++)
            {
                if(nbOfMeasure[i] != 0)
                {
                    measures[i] = measures[i]/nbOfMeasure[i];
                }
            }

            int index = AtmoIndex(measures);
            if(index != 0)
            {
                moyenne += index;
                nb++;
            }
        }
    }
    if(nb != 0)
    {
        moyenne = moyenne/nb;
    }
    return moyenne;
}//----- Fin de GetAverageQuality()

int Controller::IsInAverage()
{
    int choice = -1;

    // On récupère les paramètres
    string sensorId = view.AskSensorId();
    if(!(model.GetSensors().count(sensorId)))
    {
        view.ErrorSensorId(sensorId);
        choice = -1;
    } else 
    {
        map<string, Sensor>::iterator sensorIt = model.GetSensors().find(sensorId);
        Date start = view.AskStartDate();
        Date end = view.AskEndDate();
        double latitude = sensorIt->second.GetLatitude();
        double longitude = sensorIt->second.GetLongitude();

        // Calcul 
        double moyenne = 0;
        double  nb = 0;
        double moyenne_Sensor = 0;
        double  nb_Sensor = 0;
        for(pair<string, Sensor> sensor : model.GetSensors())
        {
            if(abs(sensor.second.GetLatitude()-latitude) <= 0.5 && abs(sensor.second.GetLongitude()-longitude) <= 0.5)
            {
                double measures[4] = {0,0,0,0};
                int nbOfMeasure[4] = {0,0,0,0};
                for(Measurement measure : sensor.second.GetMeasurements())
                {
                    if(measure.GetTime() >= start && measure.GetTime() <= end)
                    {
                        if(measure.GetAttribute() == "O3")
                        {
                            measures[0] += measure.GetValue();
                            nbOfMeasure[0] ++;
                        } else if (measure.GetAttribute() == "SO2")
                        {
                            measures[1] += measure.GetValue();
                            nbOfMeasure[1] ++;
                        } else if (measure.GetAttribute() == "NO2")
                        {
                            measures[2] += measure.GetValue();
                            nbOfMeasure[2] ++;
                        } else if (measure.GetAttribute() == "PM10")
                        {
                            measures[3] += measure.GetValue();
                            nbOfMeasure[3] ++;
                        } 
                    }
                }

                for(int i = 0; i < 4; i++)
                {
                    if(nbOfMeasure[i] != 0)
                    {
                        measures[i] = measures[i]/nbOfMeasure[i];
                    }
                }

                int index = AtmoIndex(measures);
                if(index != 0)
                {
                    if(sensor.first != sensorId)
                    {
                        moyenne += index;
                        nb++;
                    } else
                    {
                        moyenne_Sensor += index;
                        nb_Sensor++;
                    }
                }

            }
        }

        if(nb != 0)
        {
            moyenne = moyenne/nb;
        }

        if(nb_Sensor != 0)
        {
            moyenne_Sensor = moyenne_Sensor/nb_Sensor;
        }

        // Vérification
        if(abs(moyenne_Sensor -moyenne) <= 1)
        {
            choice = 1;
        } else 
        {
            model.DeleteSensor(sensorId);
            choice = 0;
        }
    }

    return choice;

}//---- Fin de IsInAverage()

void Controller::LoadData()
{
    model.Fill();
}//---- Fin de LoadData()

//-------------------------------------------- Constructeurs - destructeur
Controller::Controller()
:model(), view()
{
}//----- Fin de Controller() (constructeur)

Controller::~Controller()
{} //----- Fin de ~Controller() (destructeur)

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
