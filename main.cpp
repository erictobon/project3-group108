#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "carrier.h"
#include "graph.h"
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
    ifstream inputFile("airlines.csv");
    //get the line with the headers
    string firstLine;
    getline(inputFile, firstLine);
    string fileLine;
    vector<Carrier*> data;
    while(getline(inputFile, fileLine)){
        Carrier* newData;
        istringstream stream(fileLine);
        getline(stream, airCode, ',');
        //newData->airCode = airCode;
        getline(stream, airName, ',');
        //newData->airName = airName;
        getline(stream, buffer, ',');
        getline(stream, month, ',');
        monthNum = stoi(month);
        newData->month = monthNum;
        getline(stream, buffer, ',');
        getline(stream, year, ',');
        yearNum = stoi(year);
        newData->year = yearNum;
        getline(stream, carrier, ',');
        carrierNum = stoi(carrier);
        newData->carrierNum = carrierNum;
        getline(stream, latePlane, ',');
        lateNum = stoi(latePlane);
        newData->lateNum = lateNum;
        getline(stream, aviationSystem, ',');
        aviationNum = stoi(aviationSystem);
        newData->aviationNum = aviationNum;
        getline(stream, security, ',');
        securityNum = stoi(security);
        newData->securityNum = securityNum;
        getline(stream, weather, ',');
        weatherNum = stoi(weather);
        newData->weatherNum = weatherNum;
        getline(stream, buffer, ',');
        getline(stream, buffer, ',');
        getline(stream, buffer, ',');
        getline(stream, totalDelays, ',');
        delaysNum = stoi(totalDelays);
        newData->delaysNum = delaysNum;
        getline(stream, buffer, ',');
        getline(stream, buffer, ',');
        getline(stream, totalFlights, ',');
        flightsNum = stoi(totalFlights);
        newData->flightsNum = flightsNum;
        getline(stream, carrierMinutes, ',');
        carrierMins = stoi(carrierMinutes);
        newData->carrierMins = carrierMins;
        getline(stream, latePlaneMinutes, ',');
        lateMins = stoi(latePlaneMinutes);
        newData->lateMins = lateMins;
        getline(stream, aviationSystemMinutes, ',');
        aviationMins = stoi(aviationSystemMinutes);
        newData->aviationMins = aviationMins;
        getline(stream, securityMinutes, ',');
        securityMins = stoi(securityMinutes);
        newData->securityMins = securityMins;
        getline(stream, totalMinutes, ',');
        totalMins = stoi(totalMinutes);
        newData->totalMins = totalMins;
        getline(stream, weatherMinutes, ',');
        weatherMins = stoi(weatherMinutes);
        newData->weatherMins = weatherMins;
        data.push_back(newData);
    }
    inputFile.close();
    //29 different airports, 15 years of monthly data
    cout << "What would you like to view? (Input a number)" << endl;
    cout << "1. Delays by airport" << endl;
    cout << "2. Delays by cause" << endl;
    cout << "3. Delays by percentage of flights delayed" << endl;
    cout << "4. Exit" << endl;
    int choice;
    cin >> choice;
    while(true){
        if (choice == 1){
            cout << "How would you like to view the data? (Input a number)" << endl;
            cout << "1. Total number of delays" << endl;
            cout << "2. Total delay time in minutes" << endl;
            int option;
            cin >> option;
            if (option == 1){
                //print total number of delays
                Graph g;
                g.insertEdge(data, 1);
                g.getData();
            }
            if (option == 2){
                //print total delay time
            }
        } 
        else if (choice == 2){
            cout << "What data would you like to view? (Input a number)" << endl;
            cout << "1. By airport" << endl;
            cout << "2. All airports" << endl;
            int airport;
            cin >> airport;
            cout << "How would you like to view the data? (Input a number)" << endl;
            cout << "1. Total number of delays" << endl;
            cout << "2. Total delay time in minutes" << endl;
            int option;
            cin >> option;
            if (airport == 1){
                //use airport data
                if (option == 1){
                    //print total number of delays
                }
                if (option == 2){
                    //print total delay time
                }
            }
            if (airport == 2){
                //compile data from all airports
                if (option == 1){
                    //print total number of delays
                }
                if (option == 2){
                    //print total delay time
                }
            }
        }
        else if (choice == 3){
            //show percentage of flights delayed by airport
        }
        else if (choice == 4){
            break;
        }
    }
}