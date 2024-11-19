// Include the necessary libraries
#include <iostream>
#include <string>
#include <stdexcept>
#include <queue>

// Include the necessary headers
#include "headers/time.h"
#include "headers/patient.h"
#include "headers/scheduler.h"
#include "utilities/enums.h"

// Use the necessary standard namespace
using namespace std ;


int main() {

    Patient p1("Ahmed", "123", 'M', Time(10, 30), PatientType::URGENT);
    Patient p2("Ali", "124", 'M', Time(10, 30), PatientType::NORMAL);
    Patient p3("Sara", "125", 'F', Time(10, 30), PatientType::URGENT);
    Patient p4("Nada", "126", 'F', Time(10, 30), PatientType::NORMAL);
    Patient p5("Mohamed", "127", 'M', Time(10, 30), PatientType::URGENT);
    Patient p6("Hassan", "128", 'M', Time(10, 30), PatientType::NORMAL);
    Patient p7("Nour", "129", 'F', Time(10, 30), PatientType::URGENT);
    Patient p8("Omar", "130", 'M', Time(10, 30), PatientType::NORMAL);
    Patient p9("Hala", "131", 'F', Time(10, 30), PatientType::URGENT);
    Patient p10("Yara", "132", 'F', Time(10, 30), PatientType::NORMAL);

    Scheduler s;
    s.addPatient(&p1);
    s.addPatient(&p2);
    s.addPatient(&p3);
    s.addPatient(&p4);
    s.addPatient(&p5);
    s.addPatient(&p6);
    s.addPatient(&p7);
    s.addPatient(&p8);
    s.addPatient(&p9);
    s.addPatient(&p10);

    s.servePatients(5);
    s.printStatus();
    for(int i = 0; i < 20; i++)
        Time::advanceSystemTime();
    s.RemoveServedPatients();
    s.printStatus();
    return 0;
}