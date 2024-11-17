// Include the necessary headers
#include <iostream>
#include <string>
#include <stdexcept>
#include <queue>
#include "headers/time.h"

// Use the necessary standard namespace
using namespace std ;
enum PatientType { URGENT , NORMAL };

class Patient {
private:
    string name , id ;
    char gender ; // Stored in lower
    Time arrivalTime ;
    PatientType urgent ;
public:
    Patient( string _name , string _id, char _gender , Time _arrivalTime, PatientType _urgent = NORMAL){
        name = _name;
        id = _id;
        set_gender(_gender);
        arrivalTime = _arrivalTime ;
        urgent = _urgent;
    }
    void set_gender(char g){
        g = tolower(g);
        if ( g != 'm' && g != 'f')
            throw invalid_argument("Wrong gender format, gender must be 'M' or 'F'");
        this->gender = g;
    }
    string get_name(){ return name ; }
    string get_id(){ return id ; }
    Time timeInService(){
        return (Time::getSystemTime() - arrivalTime);
    }
    PatientType is_urgent(){ return urgent ; }

};

class Scheduler {
private:
    deque<Patient*> inService;
    vector<Patient*> served, inQueue;
    queue<Patient*> urgent, normal;

public:
    void addPatient( Patient *p){
        if ( p->is_urgent() == URGENT ) {
            urgent.push(p);
            inQueue.push_back(p);
        }
        else {
            normal.push(p);
            inQueue.push_back(p);
        }
    }

    void servePatients(int numberOfPatients){
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

    void RemoveServedPatients(){
        if (inService.empty())
            return;
        while(!inService.empty() && inService.front()->timeInService() >= Time(0, 10)) {
            Patient *p = inService.front();
            inService.pop_front();
            served.push_back(p);
        }
    }

    void printStatus() {
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

    int getNumberOfWaitingPatients(){
        return urgent.size() + normal.size();
    }

};


int main() {

    Patient p1("Ahmed", "123", 'M', Time(10, 30), URGENT);
    Patient p2("Ali", "124", 'M', Time(10, 30), NORMAL);
    Patient p3("Sara", "125", 'F', Time(10, 30), URGENT);
    Patient p4("Nada", "126", 'F', Time(10, 30), NORMAL);
    Patient p5("Mohamed", "127", 'M', Time(10, 30), URGENT);
    Patient p6("Hassan", "128", 'M', Time(10, 30), NORMAL);
    Patient p7("Nour", "129", 'F', Time(10, 30), URGENT);
    Patient p8("Omar", "130", 'M', Time(10, 30), NORMAL);
    Patient p9("Hala", "131", 'F', Time(10, 30), URGENT);
    Patient p10("Yara", "132", 'F', Time(10, 30), NORMAL);

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