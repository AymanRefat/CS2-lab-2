#include "../headers/scheduler.h"

// Member functions
void Scheduler::addPatient( Patient *p){
    if ( p->is_urgent() == PatientType::URGENT ) {
        urgent.push(p);
        inQueue.push_back(p);
    }
    else {
        normal.push(p);
        inQueue.push_back(p);
    }
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
    cout << "Current time: " << Time::getSystemTime() << '\n';

    // Patients in service
    cout << "Patients in service: \n[";
    for (Patient *p : inService)
        cout << p->get_id() << (p == inService.back() ? "" : ", ");
    cout << "]\n";

    // Patients in queue
    cout << "\nPatients waiting: \n[";
    for (Patient *p : inQueue)
        cout << p->get_id() << (p == inQueue.back() ? "" : ", ");
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