#include "DataEntry.h"
#include <iostream>

DataEntry::DataEntry()
{
    string temp;
    int tempVar;
    cout << "Enter name of country: ";
    cin >> temp;
    setCountry(temp);
    cout << "Enter date in MM/DD/YYYY format: ";
    cin >> temp;
    setDate(temp);
    cout << "Enter number of new cases: ";
    cin >> tempVar;
    setCases(tempVar);
    cout << "Enter number of new deaths: ";
    cin >> tempVar;
    setDeaths(tempVar);
}

DataEntry::DataEntry(string date1, string country1, string cases1, string deaths1)
{
    setDate(date1);
    setCountry(country1);
    int cases2 = stoi(cases1);
    setCases(cases2);
    int deaths2 = stoi(deaths1);
    setDeaths(deaths2);
}

string DataEntry::getDate()
{
    return date;
}

void DataEntry::setDate(string newDate)
{
    date = newDate;
}

string DataEntry::getCountry()
{
    return country;
}

void DataEntry::setCountry(string newCountry)
{
    country = newCountry;
}

int DataEntry::getCases()
{
    return c_cases;
}

void DataEntry::setCases(int newCases)
{
    c_cases += newCases;
}

int DataEntry::getDeaths()
{
    return c_deaths;
}

void DataEntry::setDeaths(int newDeaths)
{
    c_deaths += newDeaths;
}