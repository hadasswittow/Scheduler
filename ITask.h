//
// Created by hadasswittow on 12/5/19.
//

#ifndef SCHEDULER_ITASK_H
#define SCHEDULER_ITASK_H

#include "Time.h"
#include <iostream>
using std::cout;

class ITask {
public:
    explicit ITask(size_t t, unsigned long interval): m_times_to_run(t),m_interval(interval){};
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
protected:
    Time time;
    size_t m_times_to_run;
    unsigned long m_interval;
};



#endif //SCHEDULER_ITASK_H
