#include <iostream>
#include <string>
#include <stdexcept>
using namespace std ;

// 24-hour format
class Time{
private:
    int hours ;
    int minutes ;
public:

    Time( int _hours = 0, int _minutes = 0){
        set_hours(_hours);
        set_minutes(_minutes);
    }
    void set_hours(int _hours){
        if ( _hours < 0 && _hours >= 24 )
            throw invalid_argument("Wrong time format, hours should be in range [0,24)");
        hours = _hours;
    }
    void set_minutes(int _minutes){
        if (_minutes < 0 && _minutes >= 60) 
            throw invalid_argument("Wrong time format , Mintues should be between [0,60)");
        minutes = _minutes;
    }

};


class Patient {
    string name , ID ;
    char gender ; // Stored in lower
    Time time ;
    bool urgent ;
public:
    Patient( string _name , string _ID, char gender , Time _time, bool _urgent ) {
        name = _name;
        ID = _ID;
        set_gender(gender);
        time = _time ;
        urgent = _urgent;
    }
    void set_gender(char g){
       g = tolower(g);
       if ( g == 'm' || g == 'f'){
           this->gender = g;
       }
       else {
           throw invalid_argument("Wrong Gender, Gender should be 'M' or 'F' ");
       }
    }
    bool is_urgent(){ return urgent ; }

};

class Queue {
    queue<Patient*> urgent, normal ;


public:
    void add( Patient *p){
        if ( p->is_urgent()){
            urgent.push(p);
        }else { normal.push(p); }
    }

    // return nullptr indecating no patients left
    Patient* pop( ){
        if ( urgent.size()){
            Patient* p = urgent.front();
            urgent.pop();
            return p ;

        }else if ( normal.size()){
            Patient* p = normal.front();
            normal.pop();
            return p ;
        }
            return nullptr;
    }

};
