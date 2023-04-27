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
    void custom_data_selection(int month, int year, const string &airportCode, int dataNum);
    Hashtable(const vector<Carrier*>& data);
    void insert(Carrier* data);
    void remove(std::string key);
    Carrier* find(std::string key);
    void print_delays_by_airport();
    void print_delay_time_by_airport();
    void print_delays_by_cause();
    void print_delay_time_by_cause();
    void print_percentage_of_flights_delayed();


    Carrier *search(const string &airportCode, int month, int year);


private:
    vector<vector<Carrier *>> table;
    unsigned int hashFunction(const string &key) const;
    unordered_map<string, int> delays_by_airport;
    unordered_map<string, int> delay_time_by_airport;
    unordered_map<string, int> delays_by_cause;
    unordered_map<string, int> delay_time_by_cause;
    unordered_map<string, double> percentage_of_flights_delayed;



    void populate_hashtables(const vector<Carrier*>& data);
};

#endif //HASHTABLE_H