#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "carrier.h"
#include "hashtable.h"
using namespace std;

int main(){
    //initialize storage variables
    string airCode;
    string airName;
    string month;
    string year;
    string carrier;
    string latePlane;
    string aviationSystem;
    string security;
    string weather;
    string totalDelays;
    string totalFlights;
    string carrierMinutes;
    string latePlaneMinutes;
    string aviationSystemMinutes;
    string securityMinutes;
    string totalMinutes;
    string weatherMinutes;
    int monthNum;
    int yearNum;
    int carrierNum;
    int lateNum;
    int aviationNum;
    int securityNum;
    int weatherNum;
    int delaysNum;
    int flightsNum;
    int carrierMins;
    int lateMins;
    int aviationMins;
    int securityMins;
    int totalMins;
    int weatherMins;
    string buffer;
    string unused;
    ifstream inputFile("/Users/daligrimaux/CLionProjects/untitled45/airlines.csv");
    //get the line with the headers
    string firstLine;
    getline(inputFile, firstLine);
    string fileLine;
    vector<Carrier*> data;
    while(getline(inputFile, fileLine)){
        Carrier* newData = new Carrier();
        istringstream stream(fileLine);
        getline(stream, buffer, '\"');
        getline(stream, airCode, '\"');
        newData->airCode = airCode;
        getline(stream, buffer, '\"');
        getline(stream, airName, '\"');
        newData->airName = airName;
        getline(stream, buffer, '\"');
        getline(stream, unused, '\"');
        getline(stream, buffer, '\"');
        getline(stream, month, '\"');
        monthNum = stoi(month);
        newData->month = monthNum;
        getline(stream, buffer, '\"');
        getline(stream, unused, '\"');
        getline(stream, buffer, '\"');
        getline(stream, year, '\"');
        yearNum = stoi(year);
        newData->year = yearNum;
        getline(stream, buffer, '\"');
        getline(stream, carrier, '\"');
        carrierNum = stoi(carrier);
        newData->carrierNum = carrierNum;
        getline(stream, buffer, '\"');
        getline(stream, latePlane, '\"');
        lateNum = stoi(latePlane);
        newData->lateNum = lateNum;
        getline(stream, buffer, '\"');
        getline(stream, aviationSystem, '\"');
        aviationNum = stoi(aviationSystem);
        newData->aviationNum = aviationNum;
        getline(stream, buffer, '\"');
        getline(stream, security, '\"');
        securityNum = stoi(security);
        newData->securityNum = securityNum;
        getline(stream, buffer, '\"');
        getline(stream, weather, '\"');
        weatherNum = stoi(weather);
        newData->weatherNum = weatherNum;
        getline(stream, buffer, '\"');
        getline(stream, unused, '\"');
        getline(stream, buffer, '\"');
        getline(stream, unused, '\"');
        getline(stream, buffer, '\"');
        getline(stream, unused, '\"');
        getline(stream, buffer, '\"');
        getline(stream, totalDelays, '\"');
        delaysNum = stoi(totalDelays);
        newData->delaysNum = delaysNum;
        getline(stream, buffer, '\"');
        getline(stream, unused, '\"');
        getline(stream, buffer, '\"');
        getline(stream, unused, '\"');
        getline(stream, buffer, '\"');
        getline(stream, totalFlights, '\"');
        flightsNum = stoi(totalFlights);
        newData->flightsNum = flightsNum;
        getline(stream, buffer, '\"');
        getline(stream, carrierMinutes, '\"');
        carrierMins = stoi(carrierMinutes);
        newData->carrierMins = carrierMins;
        getline(stream, buffer, '\"');
        getline(stream, latePlaneMinutes, '\"');
        lateMins = stoi(latePlaneMinutes);
        newData->lateMins = lateMins;
        getline(stream, buffer, '\"');
        getline(stream, aviationSystemMinutes, '\"');
        aviationMins = stoi(aviationSystemMinutes);
        newData->aviationMins = aviationMins;
        getline(stream, buffer, '\"');
        getline(stream, securityMinutes, '\"');
        securityMins = stoi(securityMinutes);
        newData->securityMins = securityMins;
        getline(stream, buffer, '\"');
        getline(stream, totalMinutes, '\"');
        totalMins = stoi(totalMinutes);
        newData->totalMins = totalMins;
        getline(stream, buffer, '\"');
        getline(stream, weatherMinutes, '\"');
        weatherMins = stoi(weatherMinutes);
        newData->weatherMins = weatherMins;
        data.push_back(newData);
    }
    inputFile.close();
    //29 different airports, 15 years of monthly data
    Hashtable hashtable(data);

    while (true) {
        cout << "What would you like to view? (Input a number)" << endl;
        cout << "1. Delays by airport" << endl;
        cout << "2. Delays by cause" << endl;
        cout << "3. Delays by percentage of flights delayed" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "How would you like to view the data? (Input a number)" << endl;
            cout << "1. Total number of delays" << endl;
            cout << "2. Total delay time in minutes" << endl;
            int option;
            cin >> option;

            if (option == 1) {
                // Print total number of delays
                hashtable.print_delays_by_airport();
            } else if (option == 2) {
                // Print total delay time
                hashtable.print_delay_time_by_airport();
            }
        } else if (choice == 2) {
            cout << "How would you like to view the data? (Input a number)" << endl;
            cout << "1. Total number of delays" << endl;
            cout << "2. Total delay time in minutes" << endl;
            int option;
            cin >> option;

            if (option == 1) {
                // Print total number of delays by cause
                hashtable.print_delays_by_cause();
            } else if (option == 2) {
                // Print total delay time by cause
                hashtable.print_delay_time_by_cause();
            }
        } else if (choice == 3) {
            // Show percentage of flights delayed by airport
            hashtable.print_percentage_of_flights_delayed();
        } else if (choice == 4) {
            break;
        }
    }
}