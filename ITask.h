//
// Created by hadasswittow on 12/5/19.
//

#ifndef SCHEDULER_ITASK_H
#define SCHEDULER_ITASK_H

#include <iostream>
using std::cout;

class ITask {
public:
    explicit ITask(unsigned long n): m_next_run_period(n){};
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
protected:
    unsigned long m_next_run_period;
};



#endif //SCHEDULER_ITASK_H
