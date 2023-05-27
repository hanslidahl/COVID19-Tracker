#ifndef COVIDDB_H
#define COVIDDB_H
#include <vector>
#include "DataEntry.h"
using namespace std;
const int SIZE = 17;

class CovidDB
{
    private:
        vector<vector<DataEntry>> table;
        bool compareString(string bigger, string smaller);
    public:
        CovidDB()
        { table = vector<vector<DataEntry>> (SIZE); }
        bool add(DataEntry entry);
        DataEntry get();
        void remove(string country);
        int hashFunc(string country);
        void display();
        void displayEntry(string country);
};

#endif