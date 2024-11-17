#include "../headers/time.h"
#include <stdexcept>

// Static member initialization
Time Time::systemTime = Time(10, 30);

// Static member functions
Time Time::getSystemTime() {
    return systemTime;
}

void Time::advanceSystemTime() {
    systemTime.set_minutes(systemTime.get_minutes() + 1);
    if (systemTime.get_minutes() == 60) {
        systemTime.set_hours(systemTime.get_hours() + 1);
        systemTime.set_minutes(0);
    }
}

// Constructors
Time::Time( int _hours, int _minutes){
    set_hours(_hours);
    set_minutes(_minutes);
}

// Operators
bool Time::operator==(Time &otherTime){
    return hours == otherTime.get_hours() && minutes == otherTime.get_minutes();
}

bool Time::operator==(Time &&otherTime){
    return operator==(static_cast<Time&>(otherTime));
}

bool Time::operator!=(Time &otherTime){
    return !(*this == otherTime);
}

bool Time::operator!=(Time &&otherTime){
    return operator!=(static_cast<Time&>(otherTime));
}

bool Time::operator>(Time &otherTime){
    if ( hours > otherTime.get_hours() )
        return true;
    else if ( hours == otherTime.get_hours() && minutes > otherTime.get_minutes() )
        return true;
    return false;
}

bool Time::operator>(Time &&otherTime){
    return operator>(static_cast<Time&>(otherTime));
}

bool Time::operator>= (Time &otherTime){
    return *this > otherTime || *this == otherTime;
}

bool Time::operator>= (Time &&otherTime){
    return operator>=(static_cast<Time&>(otherTime));
}

bool Time::operator<(Time &otherTime){
    return !(*this >= otherTime);
}

bool Time::operator<(Time &&otherTime){
    return operator<(static_cast<Time&>(otherTime));
}

bool Time::operator<=(Time &otherTime){
    return !(*this > otherTime);
}

bool Time::operator<=(Time &&otherTime){
    return operator<=(static_cast<Time&>(otherTime));
}

Time Time::operator-(Time &otherTime) {
    Time biggerTime, smallerTime;
    if (*this < otherTime) {
        biggerTime = otherTime;
        smallerTime = *this;
    } else {
        biggerTime = *this;
        smallerTime = otherTime;
    }
    int newHours = biggerTime.get_hours() - smallerTime.get_hours();
    int newMinutes = biggerTime.get_minutes() - smallerTime.get_minutes();
    if (newMinutes < 0) {
        newHours--;
        newMinutes += 60;
    }
    if (*this != biggerTime) {
        newHours = -newHours;
        newMinutes = -newMinutes;
    }
    return Time(newHours, newMinutes);
}

Time Time::operator-(Time &&otherTime){
    return operator-(static_cast<Time&>(otherTime));
}


// Friend functions
std::ostream& operator<<(std::ostream &out, Time &time){
    out << time.get_hours() << ":" << time.get_minutes();
    return out;
}
std::ostream& operator<<(std::ostream &out, Time &&time){
    operator<<(out, static_cast<Time&>(time));
    return out;
}

// Setters and Getters
void Time::set_hours(int _hours){
    if ( _hours < 0 && _hours >= 24 )
        throw std::invalid_argument("Wrong time format, hours should be in range [0,24)");
    hours = _hours;
}

void Time::set_minutes(int _minutes){
    if (_minutes < 0 && _minutes >= 60) 
        throw std::invalid_argument("Wrong time format , Mintues should be between [0,60)");
    minutes = _minutes;
}

int Time::get_hours() { return hours ; }
int Time::get_minutes(){ return minutes ; }