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

    public:
        //void insertEdge(string from, string to);
        void insert(vector<Carrier*>& data, int choice);
        void getDataOne();
        void getDataTwo();
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
        for(int i = 0; i < data.size() - 28; i += 28){
            for(int j = i; j < i + 28; j++){
                graph[date(data[i]->month, data[i]->year)].push_back(make_pair(data[j]->airCode, data[j]->carrierNum));
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

void Graph::getDataThree(){
    for(auto iter = graph.begin(); iter != graph.end(); iter++){
        cout << iter->first << endl;
        for(int j = 0; j < graph[iter->first].size(); j++){
            cout << iter->second[j].first << ": " << iter->second[j].second << endl;
        }
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



