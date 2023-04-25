#include "hashtable.h"

using namespace std;
Hashtable::Hashtable(const vector<Carrier*>& data) {
    populate_hashtables(data);
}

void Hashtable::populate_hashtables(const vector<Carrier*>& data) {
    for (Carrier *carrier : data) {
        string airport_code = carrier->airCode;
        delays_by_airport[airport_code] += carrier->delaysNum;
        delay_time_by_airport[airport_code] += carrier->totalMins;
        delays_by_cause[airport_code] += carrier->carrierNum + carrier->lateNum + carrier->aviationNum + carrier->securityNum + carrier->weatherNum;
        delay_time_by_cause[airport_code] += carrier->carrierMins + carrier->lateMins + carrier->aviationMins + carrier->securityMins + carrier->weatherMins;
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
    for (const auto &entry : delays_by_cause) {
        cout << entry.first << ": " << entry.second << " delays" << endl;
    }
}

void Hashtable::print_delay_time_by_cause() {
    for (const auto &entry : delay_time_by_cause) {
        cout << entry.first << ": " << entry.second << " minutes" << endl;
    }
}

void Hashtable::print_percentage_of_flights_delayed() {
    for (const auto &entry : percentage_of_flights_delayed) {
        cout << entry.first << ": " << fixed << setprecision(2) << entry.second << "%" << endl;
    }
}

