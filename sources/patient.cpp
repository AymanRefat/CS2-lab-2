#include "../headers/patient.h"

// Constructors
Patient::Patient(string _name, string _id, char _gender, Time _arrivalTime, PatientType _type ){
    name = _name;
    id = _id;
    setGender(_gender);
    arrivalTime = _arrivalTime ;
    type = _type ;
}

int  Patient::timeInService(){
    return (Time::getSystemTime().getDifferenceInMinutes(arrivalTime));
}

void Patient::setGender(char g){
    g = tolower(g);
    if ( g != 'm' && g != 'f')
        throw invalid_argument("Wrong gender format, gender must be 'M' or 'F'");
    this->gender = g;
}

string Patient::getName(){ return name ; }
string Patient::getId(){ return id ; }
bool Patient::isUrgent(){ return type == PatientType::URGENT ; }

Time Patient::getArrivalTime(){
    return arrivalTime;
}
