#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <unordered_map>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "carrier.h"
#include "graph.h"

class Hashtable {
public:
    Hashtable(const vector<Carrier*>& data);
    void print_delays_by_airport();
    void print_delay_time_by_airport();
    void print_delays_by_cause();
    void print_delay_time_by_cause();
    void print_total_by_cause();
    void print_total_minutes_by_cause();
    void print_percentage_of_flights_delayed();
    void print_search_value(string airCode, string date, int dataNum);

private:
    string hashFunction(int month, int year);
    unordered_map<string, int> delays_by_airport;
    unordered_map<string, int> delay_time_by_airport;
    unordered_map<string, int> delays_by_carrier;
    unordered_map<string, int> delays_by_late;
    unordered_map<string, int> delays_by_avs;
    unordered_map<string, int> delays_by_security;
    unordered_map<string, int> delays_by_weather;
    unordered_map<string, int> delay_time_by_carrier;
    unordered_map<string, int> delay_time_by_late;
    unordered_map<string, int> delay_time_by_avs;
    unordered_map<string, int> delay_time_by_security;
    unordered_map<string, int> delay_time_by_weather;
    unordered_map<string, vector<pair<string, Carrier*>>> specific_data;
    unordered_map<string, double> percentage_of_flights_delayed;

    void populate_hashtables(const vector<Carrier*>& data);
};

#endif //HASHTABLE_H

Hashtable::Hashtable(const vector<Carrier*>& data) {
    populate_hashtables(data);
}

string Hashtable::hashFunction(int month, int year){
    Graph g;
    string date = g.date(month, year);
    return date;
}

void Hashtable::populate_hashtables(const vector<Carrier*>& data) {
    for (Carrier *carrier : data) {
        string airport_code = carrier->airCode;
        delays_by_airport[airport_code] += carrier->delaysNum;
        delay_time_by_airport[airport_code] += carrier->totalMins;
        delays_by_carrier[airport_code] += carrier->carrierNum;
        delays_by_late[airport_code] += carrier->lateNum;
        delays_by_avs[airport_code] += carrier->aviationNum;
        delays_by_security[airport_code] += carrier->securityNum;
        delays_by_weather[airport_code] += carrier->weatherNum;
        delay_time_by_carrier[airport_code] += carrier->carrierMins;
        delay_time_by_late[airport_code] += carrier->lateMins;
        delay_time_by_avs[airport_code] += carrier->aviationMins;
        delay_time_by_security[airport_code] += carrier->securityMins;
        delay_time_by_weather[airport_code] += carrier->weatherMins;
        percentage_of_flights_delayed[airport_code] = (static_cast<double>(carrier->delaysNum) / carrier->flightsNum) * 100;
        specific_data[hashFunction(carrier->month, carrier->year)].push_back(make_pair(airport_code, carrier));
    }
}

void Hashtable::print_delays_by_airport() {
    for (const auto &entry : delays_by_airport) {
        cout << entry.first << ": " << entry.second << " delays" << endl;
    }
}

void Hashtable::print_delay_time_by_airport() {
    for (const auto &entry : delay_time_by_airport) {
        cout << entry.first << ": " << entry.second << " minutes" << endl;
    }
}

void Hashtable::print_delays_by_cause() {
    for (const auto &entry : delays_by_carrier) {
        cout << entry.first << ": Carrier: " << entry.second;
        cout << ", Late Plane: " << delays_by_late[entry.first];
        cout << ", National Aviation System: " << delays_by_avs[entry.first];
        cout << ", Security: " << delays_by_security[entry.first];
        cout << ", Weather: " << delays_by_weather[entry.first] << endl;
    }
}

void Hashtable::print_delay_time_by_cause() {
    for (const auto &entry : delay_time_by_carrier) {
        cout << entry.first << ": Carrier: " << entry.second;
        cout << ", Late Plane: " << delay_time_by_late[entry.first];
        cout << ", Aviation System: " << delay_time_by_avs[entry.first];
        cout << ", Security: " << delay_time_by_security[entry.first];
        cout << ", Weather: " << delay_time_by_weather[entry.first] << endl;
    }
}

void Hashtable::print_total_by_cause(){
    int numCarrier = 0;
    int numLate = 0;
    int numAviation = 0;
    int numSecurity = 0;
    int numWeather = 0;
    for (const auto &entry : delays_by_carrier) {
        numCarrier += entry.second;
        numLate += delays_by_late[entry.first];
        numAviation += delays_by_avs[entry.first];
        numSecurity += delays_by_security[entry.first];
        numWeather += delays_by_weather[entry.first];
    }
    cout << "Carrier: " << numCarrier;
    cout << ", Late Plane: " << numLate;
    cout << ", Aviation System: " << numAviation;
    cout << ", Security: " << numSecurity;
    cout << ", Weather: " << numWeather << endl;
}

void Hashtable::print_total_minutes_by_cause(){
    int numCarrier = 0;
    int numLate = 0;
    int numAviation = 0;
    int numSecurity = 0;
    int numWeather = 0;
    for (const auto &entry : delay_time_by_carrier) {
        numCarrier += entry.second;
        numLate += delay_time_by_late[entry.first];
        numAviation += delay_time_by_avs[entry.first];
        numSecurity += delay_time_by_security[entry.first];
        numWeather += delay_time_by_weather[entry.first];
    }
    cout << "Carrier: " << numCarrier;
    cout << ", Late Plane: " << numLate;
    cout << ", Aviation System: " << numAviation;
    cout << ", Security: " << numSecurity;
    cout << ", Weather: " << numWeather << endl;
}

void Hashtable::print_percentage_of_flights_delayed() {
    for (const auto &entry : percentage_of_flights_delayed) {
        cout << entry.first << ": " << fixed << setprecision(2) << entry.second << "%" << endl;
    }
}

void Hashtable::print_search_value(string airCode, string date, int dataNum){
    for(auto iter = specific_data.begin(); iter != specific_data.end(); iter++){
        for (int i = 0; i < iter->second.size(); i++){
            if (iter->first == date && iter->second[i].first == airCode){
                switch (dataNum) {
                    case 1:
                        cout << "Carrier data for " << airCode << " from " << date << ":" << endl;
                        cout << "Number of carrier delays: " << iter->second[i].second->carrierNum << endl;
                        cout << "Minutes of carrier delay: " << iter->second[i].second->carrierMins << endl;
                        break;
                    case 2:
                        cout << "Late flight data for " << airCode << " from " << date << ":" << endl;
                        cout << "Number of late aircraft delays: " << iter->second[i].second->lateNum << endl;
                        cout << "Minutes of late aircraft delay: " << iter->second[i].second->lateMins << endl;
                        break;
                    case 3:
                        cout << "National Aviation System data for " << airCode << " from " << date << ":" << endl;
                        cout << "Number of National Aviation System delays: " << iter->second[i].second->aviationNum << endl;
                        cout << "Minutes of National Aviation System delay: " << iter->second[i].second->aviationMins << endl;
                        break;
                    case 4:
                        cout << "Security data for " << airCode << " from " << date << ":" << endl;
                        cout << "Number of security delays: " << iter->second[i].second->securityNum << endl;
                        cout << "Minutes of security delay: " << iter->second[i].second->securityMins << endl;
                        break;
                    case 5:
                        cout << "Weather data for " << airCode << " from " << date << ":" << endl;
                        cout << "Number of weather delays: " << iter->second[i].second->weatherNum << endl;
                        cout << "Minutes of weather delay: " << iter->second[i].second->weatherMins << endl;
                        break;
                    case 6:
                        cout << "All data for " << airCode << " from " << date << ":" << endl;
                        cout << "Number of carrier delays: " << iter->second[i].second->carrierNum << endl;
                        cout << "Minutes of carrier delay: " << iter->second[i].second->carrierMins << endl;
                        cout << "Number of late aircraft delays: " << iter->second[i].second->lateNum << endl;
                        cout << "Minutes of late aircraft delay: " << iter->second[i].second->lateMins << endl;
                        cout << "Number of National Aviation System delays: " << iter->second[i].second->aviationNum << endl;
                        cout << "Minutes of National Aviation System delay: " << iter->second[i].second->aviationMins << endl;
                        cout << "Number of security delays: " << iter->second[i].second->securityNum << endl;
                        cout << "Minutes of security delay: " << iter->second[i].second->securityMins << endl;
                        cout << "Number of weather delays: " << iter->second[i].second->weatherNum << endl;
                        cout << "Minutes of weather delay: " << iter->second[i].second->weatherMins << endl;
                        break;
                }
            }
        }
    }
}