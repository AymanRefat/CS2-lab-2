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

    Patient *p1 = new Patient("Ahmed", "123", 'M', Time(10, 30), PatientType::URGENT);
    Patient *p2 = new Patient("Ali", "124", 'M', Time(10, 30), PatientType::NORMAL);
    Patient *p3 = new Patient("Sara", "125", 'F', Time(10, 30), PatientType::URGENT);
    Patient *p4 = new Patient("Nada", "126", 'F', Time(10, 30), PatientType::NORMAL);
    Patient *p5 = new Patient("Mohamed", "127", 'M', Time(10, 30), PatientType::URGENT);
    Patient *p6 = new Patient("Hassan", "128", 'M', Time(10, 30), PatientType::NORMAL);
    Patient *p7 = new Patient("Nour", "129", 'F', Time(10, 30), PatientType::URGENT);
    Patient *p8 = new Patient("Omar", "130", 'M', Time(10, 30), PatientType::NORMAL);
    Patient *p9 = new Patient("Hala", "131", 'F', Time(10, 30), PatientType::URGENT);
    Patient *p10 = new Patient("Yara", "132", 'F', Time(10, 30), PatientType::NORMAL);

    Scheduler s;
    s.addPatient(p1);
    s.addPatient(p2);
    s.addPatient(p3);
    s.addPatient(p4);
    s.addPatient(p5);
    s.addPatient(p6);
    s.addPatient(p7);
    s.addPatient(p8);
    s.addPatient(p9);
    s.addPatient(p10);

    s.servePatients(5);
    s.printStatus();
    for(int i = 0; i < 20; i++)
        Time::advanceSystemTime();
    s.RemoveServedPatients();
    s.printStatus();
    return 0;
}