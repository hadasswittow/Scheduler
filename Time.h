//
// Created by hadasswittow on 12/5/19.
//

#ifndef SCHEDULER_TIME_H
#define SCHEDULER_TIME_H
#include <chrono>
using std::chrono::system_clock;

class Time {

public:
    Time(){ time = system_clock::now();}
    explicit Time(system_clock::time_point& _time):time(_time){};
    void now(); // change the time to now
    friend bool operator<(Time& t1,Time& t2);
    friend bool operator<=(Time& t1,Time& t2);
    friend bool operator>=(Time& t1,Time& t2);
    friend bool operator>(Time& t1,Time& t2);
    friend Time operator+(Time& t1, std::chrono::milliseconds interval);
    friend Time operator-(Time& t1, std::chrono::milliseconds interval);
private:
    system_clock::time_point time;

};
inline void Time::now(){
  time = system_clock::now();
}

inline bool operator<=(Time& t1,Time& t2 ){
    return (t1.time <= t2.time);
}
bool operator<(Time& t1,Time& t2){
    return (t1.time < t2.time);

}
bool operator>=(Time& t1,Time& t2){
    return (t1.time >= t2.time);
}
bool operator>(Time& t1,Time& t2){
    return (t1.time > t2.time);

}
Time operator+(Time& t1,std::chrono::milliseconds interval){
    system_clock::time_point t = (t1.time+interval);
    return Time(t);
}
Time operator-(Time& t1,std::chrono::milliseconds interval){
    system_clock::time_point t = (t1.time - interval);
    return Time(t);
}

#endif //SCHEDULER_TIME_H
