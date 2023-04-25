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
        void insertEdge(vector<Carrier*>& data, int choice);
        void getData();
};

void Graph::insertEdge(vector<Carrier*>& data, int choice){
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
}

void Graph::getData(){
    int num = 0;
    for (auto iter = graph.begin(); iter != graph.end(); iter++){
        for (int j = 0; j < graph[iter->first].size(); j++){
            num += iter->second[j].second;
        }
        cout << iter->first + ": ";
        cout << num << endl;
    }
}