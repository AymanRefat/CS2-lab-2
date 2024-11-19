#include "../headers/time.h"

// Static member initialization
Time Time::systemTime = Time(10, 30);

// Static member functions
Time Time::getSystemTime() {
    return systemTime;
}


// Constructors
Time::Time( int _hours, int _minutes){
    setHours(_hours);
    setMinutes(_minutes);
}

// Setters and Getters
void Time::setHours(int _hours){
    if ( _hours < 0 || _hours >= 24 )
        throw invalid_argument("Wrong time format, hours should be in range [0,24)");
    hours = _hours;
}

void Time::setMinutes(int _minutes){
    if (_minutes < 0 || _minutes >= 60)
        throw invalid_argument("Wrong time format , Mintues should be between [0,60)");
    minutes = _minutes;
}

int Time::getHours() const { return hours ; }
int Time::getMinutes() const{ return minutes ; }

void Time::increaseHours(int n ) {
    setHours((hours + n)%24);
}
void Time::increaseMinutes(int n ) {
    int newMinutes = minutes + n;
    increaseHours(newMinutes/60);
    setMinutes(newMinutes%60);
}

ostream& operator<<(ostream &out, Time &time){
    out << time.getHours() << ":" << time.getMinutes();
    return out;
}
ostream& operator<<(ostream &out, Time time){
    out << time.getHours() << ":" << time.getMinutes();
    return out;
}

int Time::getDifferenceInMinutes(Time & other ) {
    // Total of First - Total of Second
    return  abs((hours * 60 + minutes) - (other.getHours() * 60 + other.getMinutes()));
}

// Copy Constructor
Time::Time(const Time &otherTime){
    hours = otherTime.getHours();
    minutes = otherTime.getMinutes();
}


// operators
bool Time::operator==(Time &otherTime) const{
    return hours == otherTime.getHours() && minutes == otherTime.getMinutes();
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
    if ( hours > otherTime.getHours() )
        return true;
    else if ( hours == otherTime.getHours() && minutes > otherTime.getMinutes() )
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

