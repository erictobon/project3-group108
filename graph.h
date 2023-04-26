#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "carrier.h"
using namespace std;

class Graph{
    private:
        map<string, vector<pair<string, int>>> graph;
        map<string, vector<pair<string, int>>> carrierGraph;
        map<string, vector<pair<string, int>>> lateGraph;
        map<string, vector<pair<string, int>>> systemGraph;
        map<string, vector<pair<string, int>>> securityGraph;
        map<string, vector<pair<string, int>>> weatherGraph;


    public:
        //void insertEdge(string from, string to);
        void insert(vector<Carrier*>& data, int choice);
        void getDataOne();
        void getDataTwo();
        void getDataFour();
        void getDataThree();
        string date(int month, int year);
};

void Graph::insert(vector<Carrier*>& data, int choice){
    if (choice == 1){
        for (int i = 0; i < data.size(); i++){
            if (i == data.size()-1){
                graph[data[i]->airCode].push_back(make_pair(data[0]->airCode, data[i]->delaysNum));
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
        for(int i = 0; i < data.size() - 29; i += 29){
            for(int j = i; j < i + 29; j++){
                carrierGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->carrierNum));
                lateGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->lateNum));
                systemGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->aviationNum));
                securityGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->securityNum));
                weatherGraph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->weatherNum));
            }
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

void Graph::getDataFour(){
    int totalCarrier;
    int totalLate;
    int totalAviation;
    int totalSecurity;
    int totalWeather;
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
        cout << "Carrier Delays " << carrierResults[iter->first] << endl;
        cout << "Late Aircraft Delays: " << lateResults[iter->first] << endl;
        cout << "National Aviation System Delays: " << aviationResults[iter->first] << endl;
        cout << "Security Delays: " << securityResults[iter->first] << endl;
        cout << "Weather Delays: " << weatherResults[iter->first] << endl;
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



