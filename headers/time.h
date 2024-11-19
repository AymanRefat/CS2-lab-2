#ifndef TIME_H
#define TIME_H

// Include the necessary libraries
#include <ostream>
#include <stdexcept>

// Use the necessary standard namespace
using std::ostream;
using std::invalid_argument;

// Time class
class Time {
  // Static member to store the system time
  private:

  // Static member functions
  public:
    static Time systemTime;
    static void initializeTime();
    static Time getSystemTime();
    static void advanceSystemTime();

  // Private members
  private:
    int hours, minutes;

  // Public members
  public:

    // Constructors
    Time(int = 0, int = 0);

    // Operators
    bool operator==(Time &);
    bool operator==(Time &&);
    bool operator!=(Time &);
    bool operator!=(Time &&);
    bool operator>(Time &);
    bool operator>(Time &&);
    bool operator>=(Time &);
    bool operator>=(Time &&);
    bool operator<(Time &);
    bool operator<(Time &&therTime);
    bool operator<=(Time &);
    bool operator<=(Time &&);
    Time operator-(Time &);
    Time operator-(Time &&);

    // Friend functions
    friend ostream& operator<<(ostream &, Time &);
    friend ostream& operator<<(ostream &, Time &&);
    
    // Setters and Getters
    void set_hours(int);
    void set_minutes(int);
    int get_hours() const;
    int get_minutes() const;

};

#endif // TIME_H
