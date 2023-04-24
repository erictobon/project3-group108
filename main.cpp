#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "carrier.h"
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
        newData->airCode = airCode;
        getline(stream, airName, ',');
        newData->airName = airName;
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
    //29 different airports, 20 years of monthly data
    inputFile.close();

    
}