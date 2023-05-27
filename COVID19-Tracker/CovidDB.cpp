#include <string>
#include <iostream>
#include "DataEntry.h"
#include "CovidDB.h"
using namespace std;

bool CovidDB::add(DataEntry entry)
{
    int i = hashFunc(entry.getCountry());

    for(int j = 0; j < (int)table[i].size(); j++)
    {
        if(table[i][j].getCountry() == entry.getCountry())
        {
            string date1 = entry.getDate();
            string date2 = table[i][j].getDate();
            bool val = compareString(date1, date2);
            if(val)
            {
                table[i][j].setDate(entry.getDate());
                table[i][j].setCases(entry.getCases());
                table[i][j].setDeaths(entry.getDeaths());
                return true;
            }
            else
            {
                return false;
            }    
        }
    }
    table[i].push_back(entry);
    return true;
}

void CovidDB::remove(string country)
{
    int i = hashFunc(country);

    for(int j = 0; j < (int)table[i].size(); j++)
    {
        if(table[i][j].getCountry() == country)
        {
            table[i].erase(table[i].begin() + j);
            cout << "Deletion successful...\n";
            return;
        }
    }
    cout << "Element not found...\n";
}

int CovidDB::hashFunc(string country)
{
    int result = 0;
    for(int i = 0; i < (int)country.size(); i++)
    {
        result += country[i] * i;
    }
    result %= SIZE;
    return result;
}

bool CovidDB::compareString(string bigger, string smaller)
{
    if(bigger.substr(6, 4) > smaller.substr(6, 4))
    {
        return true;
    }
    else if(bigger.substr(6, 4) < smaller.substr(6, 4))
    {
        return false;
    }
    if(bigger.substr(0, 2) > smaller.substr(0,2))
    {
        return true;
    }
    else if(bigger.substr(0, 2) < smaller.substr(0,2))
    {
        return false;
    }
    if(bigger.substr(3, 2) > smaller.substr(3,2))
    {
        return true;
    }
    return false;
}

void CovidDB::display()
{
    for(int i = 0; i < (int)table.size(); i++)
    {
        for(int j = 0; j < (int)table[i].size(); j++)
        {
            cout << table[i][j].getCountry() << ":\n";
            cout << "Date of last entry: " << table[i][j].getDate() << endl;
            cout << "Number of cases: " << table[i][j].getCases() << endl;
            cout << "Number of deaths: " << table[i][j].getDeaths() << endl;
        }
    }
}

void CovidDB::displayEntry(string country)
{
    int i = hashFunc(country);

    for(int j = 0; j < (int)table[i].size(); j++)
    {
        if(table[i][j].getCountry() == country)
        {
            cout << table[i][j].getCountry() << ":\n";
            cout << "Date of last entry: " << table[i][j].getDate() << endl;
            cout << "Number of cases: " << table[i][j].getCases() << endl;
            cout << "Number of deaths: " << table[i][j].getDeaths() << endl;
            return;
        }
    }
    cout << "Element not found...\n";
}