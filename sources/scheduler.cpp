#include "../headers/scheduler.h"

// Member functions
void Scheduler::addPatient( Patient *p){
    // This function should receive a POINTER not a reference to a variable.
    // We suppose that the patient is created properly as a pointer.
    if ( p->is_urgent() == PatientType::URGENT )
        urgent.push(p);
    else
        normal.push(p);
}

void Scheduler::servePatients(int numberOfPatients){
    if (numberOfPatients < 0)
        throw invalid_argument("Number of patients to serve should be positive");
    else if (numberOfPatients > getNumberOfWaitingPatients())
        throw invalid_argument("Number of patients to serve should be less than the number of patients in the queue");

    while(numberOfPatients--) {
        if (!urgent.empty()) {
            Patient *p = urgent.front();
            inService.push_back(p);
            urgent.pop();
        } else {
            Patient *p = normal.front();
            inService.push_back(p);
            normal.pop();
        }
    }
}

void Scheduler::RemoveServedPatients(){
    if (inService.empty())
        return;
    while(!inService.empty() && inService.front()->timeInService() >= Time(0, 10)) {
        Patient *p = inService.front();
        inService.pop_front();
        served.push_back(p);
    }
}

void Scheduler::printStatus() {
    // Current Time of the system
    cout << "\nCurrent time: " << Time::getSystemTime() << '\n';

    // Patients in queue

    // Printing
    queue<Patient*> tempUrgnet, tempNormal;
    cout << "\nPatients in urgent queue: \n[";
    while (!urgent.empty()) {
        cout << urgent.front()->get_id() << (urgent.size() == 1 ? "" : ", ");
        tempUrgnet.push(urgent.front());
        urgent.pop();
    }
    cout << "]\n";
    cout << "\nPatients in normal queue: \n[";
    while(!normal.empty()) {
        cout << normal.front()->get_id() << (normal.size() == 1 ? "" : ", ");
        tempNormal.push(normal.front());
        normal.pop();
    }
    cout << "]\n";
    
    // Re-adding the patients to the queues
    while(!tempUrgnet.empty()) {
        urgent.push(tempUrgnet.front());
        tempUrgnet.pop();
    }
    while(!tempNormal.empty()) {
        normal.push(tempNormal.front());
        tempNormal.pop();
    }

    // Patients in service
    cout << "\nPatients in service: \n[";
    for (Patient *p : inService)
        cout << p->get_id() << (p == inService.back() ? "" : ", ");
    cout << "]\n";

    // Patients served
    cout << "\nPatients served: \n[";
    for (Patient *p : served)
        cout << p->get_id() << (p == served.back() ? "" : ", ");
    cout << "]\n";
}

int Scheduler::getNumberOfWaitingPatients(){
    return urgent.size() + normal.size();
}

// Destructor
Scheduler::~Scheduler(){
    while(!urgent.empty()) {
        if (urgent.front() != nullptr)
            delete urgent.front();
        urgent.pop();
    }
    while(!normal.empty()) {
        if (normal.front() != nullptr)
            delete normal.front();
        normal.pop();
    }
    for (Patient *p : inService)
        delete p;
    for (Patient *p : served)
        delete p;
}