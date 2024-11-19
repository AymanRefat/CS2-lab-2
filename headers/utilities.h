#ifndef LABASSIGNMENT_UTILITIES_H
#define LABASSIGNMENT_UTILITIES_H
#include "../headers/time.h"
#include <random>

using namespace std;
enum PatientType {
    URGENT, NORMAL
};
enum Status {
    SIMPLE =100   , MODERATE = 300 , CROWDED = 700
};

int getPatientsCountBasedOnScenario();
int getRandomInt(int min, int max);
string getRandomName();
string getRandomId();
Time getRandomTime(Time &start, int mn , int mx );


int const MAX_TIME_PER_SERVE = 10 ;
int const MAX_PATIENTS = getRandomInt(5, 10);
char const genders[2] { 'f'  , 'm' } ;

#endif //LABASSIGNMENT_UTILITIES_H
