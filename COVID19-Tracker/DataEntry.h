#ifndef DATAENTRY_H
#define DATAENTRY_H
#include <string>
using namespace std;

class DataEntry{ 
    private: 
        string date = ""; 
        string country = ""; 
        int c_cases = 0; 
        int c_deaths = 0; 
    public:
        DataEntry();
        DataEntry(string date1, string country1, string cases1, string deaths1);
        string getDate();
        void setDate(string newDate);
        string getCountry();
        void setCountry(string newCountry);
        int getCases();
        void setCases(int newCases);
        int getDeaths();
        void setDeaths(int newDeaths);
 };

 #endif