#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "carrier.h"
#include "hashtable.h"
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
    string unused;
    ifstream inputFile("airlines.csv");
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

    while(true){
        cout << "What would you like to view? (Input a number)" << endl;
        cout << "1. Delays by airport" << endl;
        cout << "2. Delays by cause" << endl;
        cout << "3. Delays by percentage of flights delayed" << endl;
        cout << "4. Search Specifics" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1){
            cout << "How would you like to view the data? (Input a number)" << endl;
            cout << "1. Total number of delays" << endl;
            cout << "2. Total delay time in minutes" << endl;
            int option;
            cin >> option;
            if (option == 1){
                //print total number of delays
                string structure;
                cout << "Which data structure would you like to use? (Type graph or hash)" << endl;
                cin >> structure;
                if (structure == "graph"){
                    Graph g;
                    g.insert(data, 1);
                    g.getDataOne();
                }
                if (structure == "hash"){
                    hashtable.print_delays_by_airport();
                }
            }
            if (option == 2){
                //print total delay time
                string structure;
                cout << "Which data structure would you like to use? (Type graph or hash)" << endl;
                cin >> structure;
                if (structure == "graph"){
                    Graph g;
                    g.insert(data, 2);
                    g.getDataTwo();
                }
                if (structure == "hash"){
                    hashtable.print_delay_time_by_airport();
                }
            }
        } 
        else if (choice == 2){
            cout << "What data would you like to view? (Input a number)" << endl;
            cout << "1. Individually by airport" << endl;
            cout << "2. Combined between all airports" << endl;
            int airport;
            cin >> airport;

            cout << "How would you like to view the data? (Input a number)" << endl;
            cout << "1. Number of delays" << endl;
            cout << "2. Delay time in minutes" << endl;
            int option;
            cin >> option;

            if (airport == 1){
                //use airport data
                if (option == 1){
                    //print number of delays
                    string structure;
                    cout << "Which data structure would you like to use? (Type graph or hash)" << endl;
                    cin >> structure;
                    if (structure == "graph"){
                        Graph g;
                        g.insert(data, 3);
                        g.getDataThree();
                    }
                    if (structure == "hash"){
                        hashtable.print_delays_by_cause();
                    }
                }
                if (option == 2){
                    //print delay time
                    string structure;
                    cout << "Which data structure would you like to use? (Type graph or hash)" << endl;
                    cin >> structure;
                    if (structure == "graph"){
                        Graph g;
                        g.insert(data, 4);
                        g.getDataFive();
                    }
                    if (structure == "hash"){
                        hashtable.print_delay_time_by_cause();
                    }
                }
            }
            if (airport == 2){
                //compile data from all airports
                if (option == 1){
                    //print number of delays
                    string structure;
                    cout << "Which data structure would you like to use? (Type graph or hash)" << endl;
                    cin >> structure;
                    if (structure == "graph"){
                        Graph g;
                        g.insert(data, 3);
                        g.getDataFour();
                    }
                }
                if (option == 2){
                    //print total delay time
                }
            }
        }
        else if (choice == 3){
            //show percentage of flights delayed by airport
            string structure;
            cout << "Which data structure would you like to use? (Type graph or hash)" << endl;
            cin >> structure;
            if(structure == "hash"){
                hashtable.print_percentage_of_flights_delayed();
            }
            else{
                Graph g;
                g.insert(data, 1);
                g.insert(data, 5);
                g.getDataSeven();
            }
        }
        else if (choice == 4){
            Graph g;
            g.insert(data, 3);
            g.insert(data, 4);
            string date;
            cout << "Enter the month and year of the data you wish to see (MM/YYYY)" << endl;
            cin >> date;
            string airportCode;
            cout << "Enter the 3 letter code of the airport" << endl;
            cin >> airportCode;
            int dataNum;
            cout << "Which data would you like to see?" << endl;
            cout << "1. Carrier Data" << endl;
            cout << "2. Late Flight Data" << endl;
            cout << "3. National Aviation System Data" << endl;
            cout << "4. Security Data" << endl;
            cout << "5. Weather Data" << endl;
            cout << "6.  Data" << endl;
            cin >> dataNum;
            g.search(date, airportCode, dataNum);
        }
        else if(choice == 5){
            break;
        }
    }
}