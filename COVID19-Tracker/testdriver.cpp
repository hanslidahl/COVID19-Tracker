#include "CovidDB.h"
#include "DataEntry.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
    CovidDB list = CovidDB();
    int choice = 1;
    string countryTemp;
    while(choice != 0)
    {
        cout << "1. Create the initial hash table\n2. Add a new data entry\n";
        cout << "3. Get a data entry\n4. Remove a data entry\n";
        cout << "5. Display hash table\n0. Quit the system\n";
        cout << "Choice: ";
        cin >> choice;
        while(choice < 0 || choice > 5)
        {
            cout << "Invalid: Enter choice within range: ";
            cin >> choice;
        }
        switch(choice)
        {
            case 1:
            {
                cout << "Creating initial hash table\n";
                ifstream infile;

                infile.open("CovidData.csv");
                while(infile)
                {
                    string line;
                    while(getline(infile, line))
                    {

                        stringstream ss(line);
                        string date1, country1, cases1, deaths1;
                        getline(ss, date1, ',');
                        getline(ss, country1, ',');
                        getline(ss, cases1, ',');
                        getline(ss, deaths1, ',');
                        DataEntry *entry = new DataEntry(date1, country1, cases1, deaths1);
                        list.add(*entry);
                    }
                }
                break;
            }
            case 2:
            {
                cout << "Add new entry:\n";
                DataEntry *entry = new DataEntry();
                list.add(*entry);
                break;
            }
            case 3:
            {
                cout << "Enter country to get data: ";
                cin >> countryTemp;
                list.displayEntry(countryTemp);
                break;
            }
            case 4:
            {
                cout << "Enter country to get data: ";
                cin >> countryTemp;
                list.remove(countryTemp);
                break;
            }
            case 5:
            {
                cout << "Hash Table:\n";
                list.display();
                break;
            }
            case 0:
            {
                cout << "Thanks, Goodbye!\n";
                break;
            }
        }
    }
}