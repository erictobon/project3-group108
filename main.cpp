#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
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
    while(getline(inputFile, fileLine)){
        istringstream stream(fileLine);
        getline(stream, airCode, ',');
        getline(stream, airName, ',');
        getline(stream, buffer, ',');
        getline(stream, month, ',');
        monthNum = stoi(month);
        getline(stream, buffer, ',');
        getline(stream, year, ',');
        yearNum = stoi(year);
        getline(stream, carrier, ',');
        carrierNum = stoi(carrier);
        getline(stream, latePlane, ',');
        lateNum = stoi(latePlane);
        getline(stream, aviationSystem, ',');
        aviationNum = stoi(aviationSystem);
        getline(stream, security, ',');
        securityNum = stoi(security);
        getline(stream, weather, ',');
        weatherNum = stoi(weather);
        getline(stream, buffer, ',');
        getline(stream, buffer, ',');
        getline(stream, buffer, ',');
        getline(stream, totalDelays, ',');
        delaysNum = stoi(totalDelays);
        getline(stream, buffer, ',');
        getline(stream, buffer, ',');
        getline(stream, totalFlights, ',');
        flightsNum = stoi(totalFlights);
        getline(stream, carrierMinutes, ',');
        carrierMins = stoi(carrierMinutes);
        getline(stream, latePlaneMinutes, ',');
        lateMins = stoi(latePlaneMinutes);
        getline(stream, aviationSystemMinutes, ',');
        aviationMins = stoi(aviationSystemMinutes);
        getline(stream, securityMinutes, ',');
        securityMins = stoi(securityMinutes);
        getline(stream, totalMinutes, ',');
        totalMins = stoi(totalMinutes);
        getline(stream, weatherMinutes, ',');
        weatherMins = stoi(weatherMinutes);
        
    }
    //29 different airports, 20 years of monthly data
    inputFile.close();
}