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
    unordered_map<string, int> delays_by_cause;
    unordered_map<string, int> delay_time_by_cause;
    unordered_map<string, double> percentage_of_flights_delayed;

    void populate_hashtables(const vector<Carrier*>& data);
};

#endif //HASHTABLE_H