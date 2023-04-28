#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "carrier.h"
#include <cmath>
#include <random>
#pragma once
using namespace std;

class Graph{
    private:
        map<string, vector<pair<string, int>>> graph;
        map<string, vector<pair<string, int>>> carrierGraph;
        map<string, vector<pair<string, int>>> lateGraph;
        map<string, vector<pair<string, int>>> systemGraph;
        map<string, vector<pair<string, int>>> securityGraph;
        map<string, vector<pair<string, int>>> weatherGraph;
        map<string, vector<pair<string, int>>> carrierTimeGraph;
        map<string, vector<pair<string, int>>> lateTimeGraph;
        map<string, vector<pair<string, int>>> systemTimeGraph;
        map<string, vector<pair<string, int>>> securityTimeGraph;
        map<string, vector<pair<string, int>>> weatherTimeGraph;
        map<string, vector<pair<string, int>>> totalGraph;

    public:
        void insert(vector<Carrier*>& data, int choice);
        void getDataOne();
        void getDataTwo();
        void getDataThree();
        void getDataFour();
        void getDataFive();
        void getDataSix();
        void getDataSeven();
        void search(string date, string airportCode, int dataNum);
        int findIndex(string date, string airportCode);
        string date(int month, int year);
};

void Graph::insert(vector<Carrier*>& data, int choice){
    if (choice == 1){
        for (int i = 0; i < data.size(); i++){
            if (i == data.size()-1){
                graph[data[i]->airCode].push_back(make_pair(data[0]->airCode, data[i]->delaysNum));
                continue;
            }
            graph[data[i]->airCode].push_back(make_pair(data[i+1]->airCode, data[i]->delaysNum));
        }
    }
    if(choice == 2){
        for (int i = 0; i < data.size(); i++){
            if (i == data.size()-1){
                graph[data[i]->airCode].push_back(make_pair(data[0]->airCode, data[i]->totalMins));
            }
            graph[data[i]->airCode].push_back(make_pair(data[i+1]->airCode, data[i]->totalMins));
        }
    }
    if(choice == 3){
        for(int i = 0; i < data.size(); i += 29){
            for(int j = i; j < i + 29; j++){
                carrierGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->carrierNum));
                lateGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->lateNum));
                systemGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->aviationNum));
                securityGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->securityNum));
                weatherGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->weatherNum));
            }
        }
    }
    if(choice == 4){
        for(int i = 0; i < data.size(); i+=29){
            for(int j = i; j < i + 29; j++){
                carrierTimeGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->carrierMins));
                lateTimeGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->lateMins));
                systemTimeGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->aviationMins));
                securityTimeGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->securityMins));
                weatherTimeGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->weatherMins));
            }
        }
    }
    if(choice == 5){
        for (int i = 0; i < data.size(); i++){
            if (i == data.size()-1){
                totalGraph[data[i]->airCode].push_back(make_pair(data[0]->airCode, data[i]->flightsNum));
                continue;
            }
            totalGraph[data[i]->airCode].push_back(make_pair(data[i+1]->airCode, data[i]->flightsNum));
        }
    }
}

void Graph::getDataOne(){
    for (auto iter = graph.begin(); iter != graph.end(); iter++){
    int num = 0;
        for (int j = 0; j < graph[iter->first].size(); j++){
            num += iter->second[j].second;
        }
        cout << iter->first + ": ";
        cout << num << endl;
    }
}

void Graph::getDataTwo(){
    for (auto iter = graph.begin(); iter != graph.end(); iter++){
        int time = 0;
        for (int j = 0; j < graph[iter->first].size(); j++){
            time += iter->second[j].second;
        }
        cout << iter->first << ": " << time << endl;
    }
}

void Graph::getDataThree(){
    map<string, int> carrierResults;
    map<string, int> lateResults;
    map<string, int> aviationResults;
    map<string, int> securityResults;
    map<string, int> weatherResults;

    for(auto iter = carrierGraph.begin(); iter != carrierGraph.end(); iter++){
        for(int j = 0; j < carrierGraph[iter->first].size(); j++){
            carrierResults[iter->second[j].first] += iter->second[j].second;
        }
    }
    for(auto iter = lateGraph.begin(); iter != lateGraph.end(); iter++){
        for(int j = 0; j < lateGraph[iter->first].size(); j++){
            lateResults[iter->second[j].first] += iter->second[j].second;
        }
    }
    for(auto iter = systemGraph.begin(); iter != systemGraph.end(); iter++){
        for(int j = 0; j < systemGraph[iter->first].size(); j++){
            aviationResults[iter->second[j].first] += iter->second[j].second;
        }
    }
    for(auto iter = securityGraph.begin(); iter != securityGraph.end(); iter++){
        for(int j = 0; j < securityGraph[iter->first].size(); j++){
            securityResults[iter->second[j].first] += iter->second[j].second;
        }
    }
    for(auto iter = weatherGraph.begin(); iter != weatherGraph.end(); iter++){
        for(int j = 0; j < weatherGraph[iter->first].size(); j++){
            weatherResults[iter->second[j].first] += iter->second[j].second;
        }
    }

    for(auto iter = carrierResults.begin(); iter != carrierResults.end(); iter++){
        cout << iter->first << ":" << endl;
        cout << "Carrier Delays: " << carrierResults[iter->first] << endl;
        cout << "Late Aircraft Delays: " << lateResults[iter->first] << endl;
        cout << "National Aviation System Delays: " << aviationResults[iter->first] << endl;
        cout << "Security Delays: " << securityResults[iter->first] << endl;
        cout << "Weather Delays: " << weatherResults[iter->first] << endl;
    }
}

void Graph::getDataFive(){
    map<string, int> carrierNumResults;
    map<string, int> lateNumResults;
    map<string, int> aviationNumResults;
    map<string, int> securityNumResults;
    map<string, int> weatherNumResults;

    for(auto iter = carrierTimeGraph.begin(); iter != carrierTimeGraph.end(); iter++){
        for(int j = 0; j < carrierTimeGraph[iter->first].size(); j++){
            carrierNumResults[iter->second[j].first] += iter->second[j].second;
        }
    }
    for(auto iter = lateTimeGraph.begin(); iter != lateTimeGraph.end(); iter++){
        for(int j = 0; j < lateTimeGraph[iter->first].size(); j++){
            lateNumResults[iter->second[j].first] += iter->second[j].second;
        }
    }
    for(auto iter = systemTimeGraph.begin(); iter != systemTimeGraph.end(); iter++){
        for(int j = 0; j < systemTimeGraph[iter->first].size(); j++){
            aviationNumResults[iter->second[j].first] += iter->second[j].second;
        }
    }
    for(auto iter = securityTimeGraph.begin(); iter != securityTimeGraph.end(); iter++){
        for(int j = 0; j < securityTimeGraph[iter->first].size(); j++){
            securityNumResults[iter->second[j].first] += iter->second[j].second;
        }
    }
    for(auto iter = weatherTimeGraph.begin(); iter != weatherTimeGraph.end(); iter++){
        for(int j = 0; j < weatherTimeGraph[iter->first].size(); j++){
            weatherNumResults[iter->second[j].first] += iter->second[j].second;
        }
    }

    for(auto iter = carrierNumResults.begin(); iter != carrierNumResults.end(); iter++){
        cout << iter->first << ":" << endl;
        cout << "Carrier Delays in Minutes: " << carrierNumResults[iter->first] << endl;
        cout << "Late Aircraft Delays in Minutes: " << lateNumResults[iter->first] << endl;
        cout << "National Aviation System Delays in Minutes: " << aviationNumResults[iter->first] << endl;
        cout << "Security Delays in Minutes: " << securityNumResults[iter->first] << endl;
        cout << "Weather Delays in Minutes: " << weatherNumResults[iter->first] << endl;
    }
}

void Graph::getDataFour(){
    int totalCarrier = 0;
    int totalLate = 0;
    int totalAviation = 0;
    int totalSecurity = 0;
    int totalWeather = 0;
    for(auto iter = carrierGraph.begin(); iter != carrierGraph.end(); iter++){
        for(int j = 0; j < carrierGraph[iter->first].size(); j++){
            totalCarrier += iter->second[j].second;
        }
    }
    for(auto iter = lateGraph.begin(); iter != lateGraph.end(); iter++){
        for(int j = 0; j < lateGraph[iter->first].size(); j++){
            totalLate += iter->second[j].second;
        }
    }
    for(auto iter = systemGraph.begin(); iter != systemGraph.end(); iter++){
        for(int j = 0; j < systemGraph[iter->first].size(); j++){
            totalAviation += iter->second[j].second;
        }
    }
    for(auto iter = securityGraph.begin(); iter != securityGraph.end(); iter++){
        for(int j = 0; j < securityGraph[iter->first].size(); j++){
            totalSecurity += iter->second[j].second;
        }
    }
    for(auto iter = weatherGraph.begin(); iter != weatherGraph.end(); iter++){
        for(int j = 0; j < weatherGraph[iter->first].size(); j++){
            totalWeather += iter->second[j].second;
        }
    }

    cout << "Delays by Carrier: " << totalCarrier << endl;
    cout << "Delays by Late Aircraft: " << totalLate << endl;
    cout << "Delays by National Aviation System: " << totalAviation << endl;
    cout << "Delays by Security: " << totalSecurity << endl;
    cout << "Delays by Weather: " << totalWeather << endl;
}

void Graph::getDataSix(){
    int totalCarrierMins = 0;
    int totalLateMins = 0;
    int totalAviationMins = 0;
    int totalSecurityMins = 0;
    int totalWeatherMins = 0;

    for(auto iter = carrierTimeGraph.begin(); iter != carrierTimeGraph.end(); iter++){
        for(int j = 0; j < carrierTimeGraph[iter->first].size(); j++){
            totalCarrierMins += iter->second[j].second;
        }
    }
    for(auto iter = lateTimeGraph.begin(); iter != lateTimeGraph.end(); iter++){
        for(int j = 0; j < lateTimeGraph[iter->first].size(); j++){
            totalLateMins += iter->second[j].second;
        }
    }
    for(auto iter = systemTimeGraph.begin(); iter != systemTimeGraph.end(); iter++){
        for(int j = 0; j < systemTimeGraph[iter->first].size(); j++){
            totalAviationMins += iter->second[j].second;
        }
    }
    for(auto iter = securityTimeGraph.begin(); iter != securityTimeGraph.end(); iter++){
        for(int j = 0; j < securityTimeGraph[iter->first].size(); j++){
            totalSecurityMins += iter->second[j].second;
        }
    }
    for(auto iter = weatherTimeGraph.begin(); iter != weatherTimeGraph.end(); iter++){
        for(int j = 0; j < weatherTimeGraph[iter->first].size(); j++){
            totalWeatherMins += iter->second[j].second;
        }
    }

    cout << "Delays by Carrier: " << totalCarrierMins << endl;
    cout << "Delays by Late Aircraft: " << totalLateMins << endl;
    cout << "Delays by National Aviation System: " << totalAviationMins << endl;
    cout << "Delays by Security: " << totalSecurityMins << endl;
    cout << "Delays by Weather: " << totalWeatherMins << endl;
}

void Graph::getDataSeven(){
    for(auto iter = graph.begin(); iter != graph.end(); iter++){
        double dnum = 0;
        double tnum = 0;
        for (int j = 0; j < graph[iter->first].size(); j++){
            dnum += iter->second[j].second;
        }
        for(int i = 0; i < totalGraph[iter->first].size(); i++){
            tnum += totalGraph[iter->first][i].second;
        }
        cout << iter->first + ": ";
        cout << (dnum/tnum) * 100  << endl;
    }
}


string Graph::date(int month, int year){
    string date;
    if(month == 1){
        date += "1/";
    }
    else if(month == 2){
        date += "2/";
    }
    else if(month == 3){
        date += "3/";
    }
    else if(month == 4){
        date += "4/";
    }
    else if(month == 5){
        date += "5/";
    }
    else if(month == 6){
        date += "6/";
    }
    else if(month == 7){
        date += "7/";
    }
    else if(month == 8){
        date += "8/";
    }
    else if(month == 9){
        date += "9/";
    }
    else if(month == 10){
        date += "10/";
    }
    else if(month == 11){
        date += "11/";
    }
    else if(month == 12){
        date += "12/";
    }

    date += to_string(year);

    return date;
}

void Graph::search(string date, string airportCode, int dataNum){
    if(dataNum == 1){
        cout << "Carrier data for " << airportCode << " from " << date << endl;
        cout << "Carrier Delay Number: " << carrierGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "Carrier Delay in Minutes: " << carrierTimeGraph[date][findIndex(date, airportCode)].second << endl;
    }
    else if(dataNum == 2){
        cout << "Late flight data for " << airportCode << " from " << date << endl;
        cout << "Late Flight Delay Number: " << lateGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "Late Flight Delay in Minutes: " << lateTimeGraph[date][findIndex(date, airportCode)].second << endl;
    }
    else if(dataNum == 3){
        cout << "National Aviation System data for " << airportCode << " from " << date << endl;
        cout << "National Aviation System Delay Number: " << systemGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "National Aviation System Delay in Minutes: " << systemTimeGraph[date][findIndex(date, airportCode)].second << endl; 
    }
    else if(dataNum == 4){
        cout << "Security data for " << airportCode << " from " << date << endl;
        cout << "Security Delay Number: " << securityGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "Security Delay in Minutes: " << securityTimeGraph[date][findIndex(date, airportCode)].second << endl; 
    }
    else if(dataNum == 5){
        cout << "Weather data for " << airportCode << " from " << date << endl;
        cout << "Weather Delay Number: " << weatherGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "Weather Delay in Minutes: " << weatherTimeGraph[date][findIndex(date, airportCode)].second << endl;
    }
    else if(dataNum == 6){
        cout << "All Data for " << airportCode << " from " << date << endl;
        cout << "Carrier Delay Number: " << carrierGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "Carrier Delay in Minutes: " << carrierTimeGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "Late Flight Delay Number: " << lateGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "Late Flight Delay in Minutes: " << lateTimeGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "National Aviation System Delay Number: " << systemGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "National Aviation System Delay in Minutes: " << systemTimeGraph[date][findIndex(date, airportCode)].second << endl; 
        cout << "Security Delay Number: " << securityGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "Security Delay in Minutes: " << securityTimeGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "Weather Delay Number: " << weatherGraph[date][findIndex(date, airportCode)].second << endl;
        cout << "Weather Delay in Minutes: " << weatherTimeGraph[date][findIndex(date, airportCode)].second << endl;
    }

}

int Graph::findIndex(string date, string airportCode){
    int index = 0;
    for(int i = 0; i < carrierGraph[date].size(); i++){
        if(carrierGraph[date][i].first == airportCode){
            index = i;
        }
    }

    return index;
}

