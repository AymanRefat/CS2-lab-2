#ifndef LABASSIGNMENT_SCHEDULER_H
#define LABASSIGNMENT_SCHEDULER_H

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <deque>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "patient.h"
#include "time.h"

class Scheduler {
private:
    std::deque<Patient*> urgent, normal, inService; // Waiting queues
    std::vector<Patient*> served;                  // List of served patients
    int ServedUrgent = 0, ServedNormal = 0;        // Counters for served patients
    double totalWaitingTime = 0;                 // Total waiting time

public:
    // Add a patient to the appropriate queue
    void addPatient(Patient *p);

    // Serve a specified number of patients
    void servePatients(int numberOfPatients);

    // Remove patients who have completed their service
    void removeServedPatients();

    // Print the current status of the scheduler
    void printStatus();

    // Print statistics about served patients
    void printStatistics();

    // Get the number of patients waiting in the queue
    int getNumberOfWaitingPatients();

    // Get the number of patients currently in service
    int getNumberOfInservicePatients();

    // Destructor to clean up dynamically allocated memory
    ~Scheduler();
};

#endif // SCHEDULER_H
#endif //LABASSIGNMENT_SCHEDULER_H
