#include "../headers/utilities.h"



int get_random_int(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min , max);
    return distrib(gen);
}
string get_random_name(){
    string names[] = {"Ahmed", "Ali", "Sara", "Nada", "Mohamed", "Hassan", "Nour", "Omar", "Hala", "Yara"};
    return names[get_random_int(0, 9)];
}
string get_random_id(){
    string id ;
    for(int i = 0; i < 10; i++)
        id += to_string(get_random_int(0, 9));
    return id;
}

Time get_random_time(Time &start, int mn , int mx ){
    Time end = Time(start) ;
    end.increase_minutes(get_random_int(mn, mx));
    return end;
}
int get_patients_count_based_on_scenario(){
    vector<int> scenarios = {Status::SIMPLE, Status::MODERATE, Status::CROWDED};
    int count  =  scenarios[get_random_int(0, 2)];

    return count ;
}