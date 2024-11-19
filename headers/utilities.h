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

int get_patients_count_based_on_scenario();
int get_random_int(int min, int max);
string get_random_name();
string get_random_id();
Time get_random_time(Time &start, int mn , int mx );


int const MAX_TIME_PER_SERVE = 10 ;
int const MAX_PATIENTS = get_random_int(5, 10);
char const genders[2] { 'f'  , 'm' } ;

#endif //LABASSIGNMENT_UTILITIES_H
