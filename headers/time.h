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
    int get_difference_in_minutes(Time &);

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
    void set_hours(int);
    void increase_hours(int);
    void increase_minutes(int);
    void set_minutes(int);
    int get_hours() const;
    int get_minutes() const;

};

#endif //LABASSIGNMENT_TIME_H
