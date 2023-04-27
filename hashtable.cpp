#include "hashtable.h"

using namespace std;
Hashtable::Hashtable(const vector<Carrier*>& data) {
    populate_hashtables(data);
}
unsigned int Hashtable::hashFunction(const string &key) const {
    unsigned int hashValue = 0;
    for (char c : key) {
        hashValue = 31 * hashValue + c;
    }
    return hashValue % table.size();
}

void Hashtable::populate_hashtables(const vector<Carrier*>& data) {
    for (Carrier *carrier : data) {
        string airport_code = carrier->airCode;
        delays_by_airport[airport_code] += carrier->delaysNum;
        delay_time_by_airport[airport_code] += carrier->totalMins;
        delays_by_cause[airport_code] += carrier->carrierNum + carrier->lateNum + carrier->aviationNum + carrier->securityNum + carrier->weatherNum;
        delay_time_by_cause[airport_code] += carrier->carrierMins + carrier->lateMins + carrier->aviationMins + carrier->securityMins + carrier->weatherMins;

        if (carrier->flightsNum != 0) {
            percentage_of_flights_delayed[airport_code] = (static_cast<double>(carrier->delaysNum) / carrier->flightsNum) * 100;
        } else {
            percentage_of_flights_delayed[airport_code] = 0.0;
        }
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
Carrier *Hashtable::search(const string &airportCode, int month, int year) {
    unsigned int index = hashFunction(airportCode);
    for (Carrier *carrier : table[index]) {
        if (carrier->airCode == airportCode && carrier->month == month && carrier->year == year) {
            return carrier;
        }
    }
    return nullptr;
}

void Hashtable::custom_data_selection(int month, int year, const string &airportCode, int dataNum) {
    Carrier* carrier = search(airportCode, month, year);
    if (carrier == nullptr) {
        cout << "No data found for the specified airport and date." << endl;
        return;
    }
    switch (dataNum) {
        case 1:
            cout << "Carrier data for " << airportCode << " in " << month << "/" << year << ":" << endl;
            cout << "Total flights: " << carrier->flightsNum << endl;
            cout << "Total minutes of delay: " << carrier->totalMins << endl;
            cout << "Number of delayed flights: " << carrier->delaysNum << endl;
            cout << "Minutes of carrier delay: " << carrier->carrierMins << endl;
            cout << "Minutes of late aircraft delay: " << carrier->lateMins << endl;
            cout << "Minutes of National Aviation System delay: " << carrier->aviationMins << endl;
            cout << "Minutes of Security delay: " << carrier->securityMins << endl;
            cout << "Minutes of Weather delay: " << carrier->weatherMins << endl;
            break;
        case 2:
            cout << "Late flight data for " << airportCode << " in " << month << "/" << year << ":" << endl;
            cout << "Total flights: " << carrier->flightsNum << endl;
            cout << "Total minutes of delay: " << carrier->lateMins << endl;
            cout << "Number of delayed flights: " << carrier->lateNum << endl;
            break;
        case 3:
            cout << "National Aviation System data for " << airportCode << " in " << month << "/" << year << ":" << endl;
            cout << "Total minutes of delay: " << carrier->aviationMins << endl;
            cout << "Number of delayed flights: " << carrier->aviationNum << endl;
            break;
        case 4:
            cout << "Security data for " << airportCode << " in " << month << "/" << year << ":" << endl;
            cout << "Total minutes of delay: " << carrier->securityMins << endl;
            cout << "Number of delayed flights: " << carrier->securityNum << endl;
            break;
        case 5:
            cout << "Weather data for " << airportCode << " in " << month << "/" << year << ":" << endl;
            cout << "Total minutes of delay: " << carrier->weatherMins << endl;
            cout << "Number of delayed flights: " << carrier->weatherNum << endl;
            break;
        case 6:
            cout << "All data for " << airportCode << " in " << month << "/" << year << ":" << endl;
            cout << "Total flights: " << carrier->flightsNum << endl;
            cout << "Total minutes of delay: " << carrier->totalMins << endl;
            cout << "Number of delayed flights: " << carrier->delaysNum << endl;
            cout << "Minutes of carrier delay: " << carrier->carrierMins << endl;
            cout << "Minutes of late aircraft delay: " << carrier->lateMins << endl;
            cout << "Minutes of National Aviation System delay: " << carrier->aviationMins << endl;
            cout << "Minutes of Security delay: " << carrier->securityMins << endl;
            cout << "Minutes of Weather delay: " << carrier->weatherMins << endl;
    }
}

