// Include the necessary libraries
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include "headers/patient.h"
#include "headers/scheduler.h"
#include "headers/time.h"

using namespace std;

int main() {
    // Get the number of patients based on the scenario
    int patientCount = getPatientsCountBasedOnScenario();
    cout << "Number of Patients: " << patientCount << endl;

    // Initialize the scheduler
    Scheduler scheduler;

    // Create a vector to store patient pointers
    vector<Patient*> patients;

    // Generate patients and add them to the vector
    for (int i = 0; i < patientCount; i++) {
        string name = getRandomName();
        string id = getRandomId();
        char gender = genders[getRandomInt(0, 1)];
        Time arrivalTime = getRandomTime(Time::systemTime, 1, patientCount);
        PatientType type = (i % 2 == 0) ? PatientType::NORMAL : PatientType::URGENT;

        // Create a new patient and add to the vector
        Patient* patient = new Patient(name, id, gender, arrivalTime, type);
        patients.push_back(patient);
    }

    // Sort patients by arrival time
    sort(patients.begin(), patients.end(), [](Patient* a, Patient* b) {
        return a->getArrivalTime() < b->getArrivalTime();
    });

    // Simulation loop
    while (!patients.empty() || scheduler.getNumberOfWaitingPatients() + scheduler.getNumberOfInservicePatients() > 0) {
        cout << "Enter to Continue or (q) to skip the simulation: " << endl;
        string input;
        getline(cin, input);
        if (input == "q") break;

        // Increase system time by 1 minute
        Time::systemTime.increaseMinutes(1);

        // Add patients to the scheduler as they arrive
        while (!patients.empty() && patients.front()->getArrivalTime() <= Time::systemTime) {
            scheduler.addPatient(patients.front());
            patients.erase(patients.begin());
        }

        // Remove served patients and serve new patients
        scheduler.removeServedPatients();
        scheduler.servePatients(getRandomInt(5, 10));
        scheduler.printStatus();
    }

    // Print final statistics
    scheduler.printStatistics();

    // Clean up dynamically allocated memory
    for (Patient* patient : patients) {
        delete patient;
    }

    return 0;
}