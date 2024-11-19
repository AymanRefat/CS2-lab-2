#include "../headers/time.h"

// Static member initialization
Time Time::systemTime = Time(10, 30);

// Static member functions
Time Time::getSystemTime() {
    return systemTime;
}


// Constructors
Time::Time( int _hours, int _minutes){
    set_hours(_hours);
    set_minutes(_minutes);
}

// Setters and Getters
void Time::set_hours(int _hours){
    if ( _hours < 0 || _hours >= 24 )
        throw invalid_argument("Wrong time format, hours should be in range [0,24)");
    hours = _hours;
}

void Time::set_minutes(int _minutes){
    if (_minutes < 0 || _minutes >= 60)
        throw invalid_argument("Wrong time format , Mintues should be between [0,60)");
    minutes = _minutes;
}

int Time::get_hours() const { return hours ; }
int Time::get_minutes() const{ return minutes ; }

void Time::increase_hours(int n ) {
    set_hours((hours + n)%24);
}
void Time::increase_minutes(int n ) {
    int newMinutes = minutes + n;
    increase_hours(newMinutes/60);
    set_minutes(newMinutes%60);
}

ostream& operator<<(ostream &out, Time &time){
    out << time.get_hours() << ":" << time.get_minutes();
    return out;
}
ostream& operator<<(ostream &out, Time time){
    out << time.get_hours() << ":" << time.get_minutes();
    return out;
}

int Time::get_difference_in_minutes(Time & other ) {
    // Total of First - Total of Second
    return  abs((hours * 60 + minutes) - (other.get_hours() * 60 + other.get_minutes()));
}

// Copy Constructor
Time::Time(const Time &otherTime){
    hours = otherTime.get_hours();
    minutes = otherTime.get_minutes();
}


// operators
bool Time::operator==(Time &otherTime) const{
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

bool Time::operator>(Time &otherTime) const{
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

