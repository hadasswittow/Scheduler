//
// Created by hadasswittow on 12/5/19.
//

#ifndef SCHEDULER_ITASK_H
#define SCHEDULER_ITASK_H

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
using std::cout;

class ITask {
public:

    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds

};
class Task : public ITask{
public:
    explicit Task(size_t t, unsigned long interval, unsigned long begin): m_begin_time(begin),m_times_to_run(t),m_interval(interval){};
    void run();
    virtual void runImplementation() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
    void setBeginTime(unsigned long time){m_begin_time = time;}
    unsigned long  getBeginTime(){return m_begin_time;}
    bool operator>(Task*);
    virtual ~Task(){};
protected:
    size_t m_times_to_run;
    unsigned long m_interval;
    unsigned long m_next_run_period;
    unsigned long m_begin_time;

};
inline bool Task::operator>(Task* t){
    return m_begin_time > t->m_begin_time;
}
inline void Task::run(){
    struct timeval tvalBefore, tvalAfter;  // save start time
    gettimeofday (&tvalBefore, NULL);
    runImplementation();
    gettimeofday (&tvalAfter, NULL);
    m_next_run_period = m_interval - (((tvalAfter.tv_sec - tvalBefore.tv_sec)+tvalAfter.tv_usec) - tvalBefore.tv_usec);
    gettimeofday (&tvalBefore, NULL);
    m_begin_time = tvalBefore.tv_sec + m_next_run_period;
    m_times_to_run-=1;
}



#endif //SCHEDULER_ITASK_H
