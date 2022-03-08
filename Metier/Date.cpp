/*************************************************************************
                           Date  -  description
                             -------------------
    début                : 29/05/2021
    auteur               : Damien-Joseph RISPAL
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream> 
using namespace std;

//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int Date::GetYear()
{
    return year;
}//----- Fin de GetYear()

int Date::GetMonth()
{
    return month;
}//----- Fin de GetMonth()

int Date::GetDay()
{
    return day;
}//----- Fin de GetDay()

int Date::GetHour()
{
    return hour;
}//----- Fin de GetHour()

int Date::GetMinute()
{
    return minute;
}//----- Fin de GetMinute()

int Date::GetSecond()
{
    return second;
}//----- Fin de GetSecond()

void Date::Show()
{
    cout << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second;    
}

bool Date::operator <=(const Date & date)
{
    if(year > date.year) return false;
    else if(year == date.year)
    {
        if(month > date.month) return false;
        else if(month == date.month)
        {
            if(day > date.day) return false;
            else if(day == date.day)
            {
                if(hour > date.hour) return false;
                else if(hour == date.hour)
                {
                    if(minute > date.minute) return false;
                    else if(minute == date.minute)
                    {
                        if(second > date.second) return false;
                        return true;
                    }
                    return true;
                }
                return true;
            }
            return true;
        }
        return true;
    }
    return true;
}//----- Fin de operator <=

bool Date::operator >=(const Date & date)
{
    if(year < date.year) return false;
    else if(year == date.year)
    {
        if(month < date.month) return false;
        else if(month == date.month)
        {
            if(day < date.day) return false;
            else if(day == date.day)
            {
                if(hour < date.hour) return false;
                else if(hour == date.hour)
                {
                    if(minute < date.minute) return false;
                    else if(minute == date.minute)
                    {
                        if(second < date.second) return false;
                        return true;
                    }
                    return true;
                }
                return true;
            }
            return true;
        }
        return true;
    }
    return true;
} //----- Fin de operator >=

//-------------------------------------------- Constructeurs - destructeur
Date::Date()
{
    year = 0;
    month = 0;
    day = 0;
    hour = 0;
    minute = 0;
    second = 0;
} //----- Fin de Date() (constructeur par défaut)

Date::Date(string dateString)
{
    year=stoi(dateString.substr(0,4));
    month=stoi(dateString.substr(5,2));
    day=stoi(dateString.substr(8,2));
    hour=stoi(dateString.substr(11,2));
    minute=stoi(dateString.substr(14,2));
    second=stoi(dateString.substr(17,2)); 
} //----- Fin de Date() (constructeur)

Date::~Date()
{} //----- Fin de ~Date() (Destructeur)

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
