#include "../headers/patient.h"


// Constructors
Patient::Patient(string _name, string _id, char _gender, Time _arrivalTime, PatientType _urgent){
    name = _name;
    id = _id;
    set_gender(_gender);
    arrivalTime = _arrivalTime ;
    urgent = _urgent;
}

// Setters and Getters
Time Patient::timeInService(){
    return (Time::getSystemTime() - arrivalTime);
}

void Patient::set_gender(char g){
    g = tolower(g);
    if ( g != 'm' && g != 'f')
        throw invalid_argument("Wrong gender format, gender must be 'M' or 'F'");
    this->gender = g;
}

string Patient::get_name(){ return name ; }
string Patient::get_id(){ return id ; }
PatientType Patient::is_urgent(){ return urgent ; }