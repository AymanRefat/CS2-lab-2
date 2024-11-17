#ifndef PATIENT_H
#define PATIENT_H

// Include the neccessary libraries
#include <string>

// Include the necessary headers
#include "../headers/time.h"

// Use the necessary standard namespace
using std::string;

// Patient class
class Patient {

// Private members
private:
    string name , id ;
    char gender ;
    Time arrivalTime ;
    PatientType urgent ;

// Public members
public:

    // Constructors
    Patient(string , string, char, Time, PatientType = NORMAL);

    // Setters and Getters
    PatientType is_urgent();
    Time timeInService();
    void set_gender(char);
    string get_name();
    string get_id();

};

#endif // PATIENT_H