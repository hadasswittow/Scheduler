//
// Created by hadasswittow on 12/5/19.
//

#ifndef SCHEDULER_TIME_H
#define SCHEDULER_TIME_H
#include <chrono>
using std::chrono::system_clock;

class Time {

public:
    Time(unsigned long time = 0):m_curTime(time){};
    void now(); // change the time to now
    unsigned long getTickCount() const;
    unsigned long getTimeInMill() const;
    int operator()(){return m_curTime;}
    friend bool operator<(Time& t1,Time& t2);
    friend bool operator<=(Time& t1,Time& t2);
    friend bool operator>=(Time& t1,Time& t2);
    friend bool operator>(Time& t1,Time& t2);
    friend unsigned long operator+(Time& t1, unsigned long interval);
    friend unsigned long operator-(Time& t1, unsigned long interval);
private:
    unsigned long m_curTime;
    system_clock::time_point time;

};
inline void Time::now(){
    m_curTime = getTickCount();
}

inline bool operator<=(Time& t1,Time& t2 ){
    return t1.m_curTime <= t2.getTimeInMill();
}
inline bool operator<(Time& t1,Time& t2){
    return t1.m_curTime < t2.getTimeInMill();

}
inline bool operator>=(Time& t1,Time& t2){
    return t1.m_curTime >= t2.getTimeInMill();
}
inline bool operator>(Time& t1,Time& t2){
    return t1.m_curTime > t2.getTimeInMill();

}

inline unsigned long operator+(Time& t1,unsigned long interval){
    return t1.m_curTime + interval;
}
inline unsigned long operator-(Time& t1,unsigned long interval){
   return t1.m_curTime - interval;
}
inline unsigned long Time::getTickCount()const {
    struct timespec now = { 0 };
    if(clock_gettime(CLOCK_MONOTONIC,&now)){
        return 0;
    }
    return static_cast<unsigned long>(now.tv_sec * 1000 + now.tv_nsec / 1000000);
}
inline unsigned long Time::getTimeInMill()const {
    return m_curTime;
}
#endif //SCHEDULER_TIME_H
