#ifndef LABASSIGNMENT_PATIENT_H
#define LABASSIGNMENT_PATIENT_H
#include <iostream>
#include <string>
#include "../headers/time.h"
#include "../headers/utilities.h"
using namespace std ;

class Patient {

// Private members
private:
    string name , id ;
    char gender ;
    Time arrivalTime ;
    PatientType type ;
// Public members
public:

    // Constructors
    Patient(string , string, char, Time, PatientType = PatientType::NORMAL);

    // Setters and Getters
    bool is_urgent();
    int timeInService();
    void set_gender(char);
    string get_name();
    string get_id();
    Time get_arrival_time();

};
#endif //LABASSIGNMENT_PATIENT_H