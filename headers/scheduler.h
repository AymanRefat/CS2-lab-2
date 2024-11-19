#ifndef SCHDULER_H
#define SCHDULER_H

// Include the neccessary libraries
#include <deque>
#include <vector>
#include <queue>
#include <iostream>

// Include the necessary headers
#include "../headers/time.h"
#include "../headers/patient.h"
#include "../utilities/enums.h"

// Use the necessary standard namespace
using std::deque;
using std::vector;
using std::queue;
using std::cout;

// Scheduler class
class Scheduler {

// Private members
private:
    deque<Patient*> inService;
    vector<Patient*> served;
    queue<Patient*> urgent, normal;

// Public members
public:

    // Member functions
    void addPatient(Patient*);
    void servePatients(int);
    void RemoveServedPatients();

    // Helper functions
    void printStatus();

    // Getters and Setters
    int getNumberOfWaitingPatients();
};


#endif // SCHDULER_H