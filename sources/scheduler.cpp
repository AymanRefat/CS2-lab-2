#include "../headers/patient.h"
#include "../headers/scheduler.h"


void Scheduler::addPatient( Patient *p){
    if ( p->isUrgent() ) {
        urgent.push_back(p);
    }
    else {
        normal.push_back(p);
    }
}

void Scheduler::servePatients(int numberOfPatients) {
    if (numberOfPatients < 0)
        throw invalid_argument("Number of patients to serve should be positive");

    Patient *p = nullptr ;
    // Serve patients till the number of patients to serve is reached or there are no more patients
    while(numberOfPatients-- && (!urgent.empty() || !normal.empty())) {
        if ( MAX_TIME_PER_SERVE == inService.size() ) break ; // Maximum number of patients in service reached
        if (!urgent.empty()) {
            p = urgent.front();
            totalWaitingTime += p->getArrivalTime().getDifferenceInMinutes(Time::systemTime);
            inService.push_back(p);
            urgent.pop_front();
        } else if ( !normal.empty() ) {
            p = normal.front();
            inService.push_back(p);
            normal.pop_front();
        }
        else { return ; }
        if ( p ) totalWaitingTime += p->getArrivalTime().getDifferenceInMinutes(Time::systemTime);
    }
}

void Scheduler::removeServedPatients(){
    if (inService.empty())
        return;

    while(!inService.empty() && inService.front()->timeInService() >= MAX_TIME_PER_SERVE ) {
        Patient *p = inService.front();
        inService.pop_front();
        if ( p->isUrgent() ) ServedUrgent++ ;
        else ServedNormal++ ;
        served.push_back(p);
    }
}

void Scheduler::printStatus() {
    // Current Time of the system
    cout << "Current time: " << Time::getSystemTime() << '\n';
    cout <<"Maximum patients in service: " << MAX_TIME_PER_SERVE <<endl ;
    // Patients in service
    cout << "Patients in service "  << inService.size() << ": \n[";
    for (Patient *p : inService)
        cout << p->getId() << (p == inService.back() ? "" : ", ");
    cout << "]\n";

    // Patients in queue
    cout << "\nPatients waiting " << urgent.size() + normal.size() << ": \n[";
    for ( auto p : urgent )
        cout << p->getId() << ", " ;
    for ( auto p : normal )
        cout << p->getId() << ", ";
    cout << "]\n";


    // Patients served
    cout << "\nPatients served "<< served.size() << ": \n[";
    for (Patient *p : served)
        cout << p->getId() << (p == served.back() ? "" : ", ");
    cout << "]\n";
}


void Scheduler::printStatistics (){
    cout << "Number of urgent cases: " << ServedUrgent <<endl ;
    cout << "Number of normal cases: " << ServedNormal <<endl ;

    if (!served.empty()) {
        cout <<"Average Waiting Time : " << totalWaitingTime / double(served.size() + inService.size()) << " m"<<endl ;
    }
    else cout << "No Patients have been served." <<endl ;
}

int Scheduler::getNumberOfWaitingPatients(){
    return urgent.size() + normal.size();
}
int Scheduler::getNumberOfInservicePatients(){
    return inService.size();
}

Scheduler::~Scheduler(){
    for ( auto p : urgent ) delete p ;
    for ( auto p : normal ) delete p ;
    for ( auto p : inService ) delete p ;
    for ( auto p : served ) delete p ;
}

