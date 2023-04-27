#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <unordered_map>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "carrier.h"

class Hashtable {
public:
    Hashtable(const vector<Carrier*>& data);
    void print_delays_by_airport();
    void print_delay_time_by_airport();
    void print_delays_by_cause();
    void print_delay_time_by_cause();
    void print_percentage_of_flights_delayed();

private:
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
    unordered_map<string, double> percentage_of_flights_delayed;

    void populate_hashtables(const vector<Carrier*>& data);
};

#endif //HASHTABLE_H

Hashtable::Hashtable(const vector<Carrier*>& data) {
    populate_hashtables(data);
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
        cout << ", Weather: " << delays_by_avs[entry.first] << endl;
    }
}

void Hashtable::print_delay_time_by_cause() {
    for (const auto &entry : delay_time_by_carrier) {
        cout << entry.first << ": Carrier: " << entry.second;
        cout << ", Late Plane: " << delay_time_by_late[entry.first];
        cout << ", Aviation System: " << delay_time_by_avs[entry.first];
        cout << ", Security: " << delay_time_by_security[entry.first];
        cout << ", Weather: " << delay_time_by_avs[entry.first] << endl;
    }
}

void Hashtable::print_percentage_of_flights_delayed() {
    for (const auto &entry : percentage_of_flights_delayed) {
        cout << entry.first << ": " << fixed << setprecision(2) << entry.second << "%" << endl;
    }
}