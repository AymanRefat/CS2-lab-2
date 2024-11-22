#include "../headers/utilities.h"



int getRandomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min , max);
    return distrib(gen);
}
string getRandomName(){
    string names[] = {"Ahmed", "Ali", "Sara", "Nada", "Mohamed", "Hassan", "Nour", "Omar", "Hala", "Yara"};
    return names[getRandomInt(0, 9)];
}
string getRandomId(){
    string id ;
    for(int i = 0; i < 10; i++)
        id += to_string(getRandomInt(0, 9));
    return id;
}

Time getRandomTime(Time &start, int mn , int mx ){
    Time end = Time(start) ;
    end.increaseMinutes(getRandomInt(mn, mx));
    return end;
}
int getPatientsCountBasedOnScenario(){
    vector<int> scenarios = {Status::SIMPLE, Status::MODERATE, Status::CROWDED};
    int count  =  scenarios[getRandomInt(0, 2)];

    return count ;
}