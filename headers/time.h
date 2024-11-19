#ifndef LABASSIGNMENT_TIME_H
#define LABASSIGNMENT_TIME_H
// Include the necessary libraries
#include <ostream>
#include <stdexcept>

// Use the necessary standard namespace
using std::ostream;
using std::invalid_argument;

// Time class
class Time {

    // Static member functions
public:
    static Time systemTime;
    static Time getSystemTime();

    // Private members
private:
    int hours, minutes;

    // Public members
public:


    // Constructors
    Time(int = 0, int = 0);


    // difference between two times in minutes
    int getDifferenceInMinutes(Time &);

    // copy constructor
    Time(const Time &);
    // comparison operators
    bool operator==(Time &) const;
    bool operator==(Time &&);
    bool operator!=(Time &);
    bool operator!=(Time &&);
    bool operator>(Time &) const;
    bool operator>(Time &&);
    bool operator>=(Time &);
    bool operator>=(Time &&);
    bool operator<(Time &);
    bool operator<(Time &&);
    bool operator<=(Time &);
    bool operator<=(Time &&);
    // Friend functions
    friend ostream& operator<<(ostream &, Time &);
    friend ostream& operator<<(ostream &, Time );
    




    // Friend functions
    friend ostream& operator<<(ostream &, Time );
    friend ostream& operator<<(ostream &, Time &);

    // Setters and Getters
    void setHours(int);
    void increaseHours(int);
    void increaseMinutes(int);
    void setMinutes(int);
    int getHours() const;
    int getMinutes() const;

};

#endif //LABASSIGNMENT_TIME_H
