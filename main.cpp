// Include the necessary libraries
#include <iostream>
#include <string>
#include <queue>
#include "headers/patient.h"
#include "headers/scheduler.h"
#include "headers/time.h"
using namespace std ;

int main() {
    int count = get_patients_count_based_on_scenario();
    cout << "Number of Patients: " << count <<endl ;
    Scheduler s;
    vector<Patient*> patients;
    for (int i = 0; i < count; i++) {
        string name = get_random_name();
        string id = get_random_id();
        char gender = genders[get_random_int(0, 1)];
        Time arrivalTime = get_random_time(Time::systemTime, 1 , count);
        auto type = (i&1 ? PatientType::URGENT: PatientType::NORMAL);
        auto *p = new Patient( name , id , gender , arrivalTime , type ) ;
        patients.push_back(p);
    }
    // sort patients by arrival time
    std::sort(patients.begin(), patients.end(), [](Patient *a, Patient *b) {
        return a->get_arrival_time() < b->get_arrival_time();
    });

    while ( !patients.empty() || s.getNumberOfWaitingPatients() + s.getNumberOfInservicePeople() > 0 ) {
        cout << "Enter to Continue or (q) to skip the simulation:  " <<endl ;
        string input ;
        getline(cin, input);
        if ( input == "q" ) break ;

        Time::systemTime.increase_minutes(1);
        if ( !patients.empty()  ) {
            while ( !patients.empty() && patients.front()->get_arrival_time() <= Time::systemTime ){
                s.addPatient(patients.front());
                patients.erase(patients.begin());
            }
        }

        s.removeServedPatients();
        s.servePatients(get_random_int(5 , 10));
        s.printStatus();
    }

    s.printStatistics();
}