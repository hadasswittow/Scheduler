//
// Created by hadasswittow on 12/5/19.
//

#ifndef SCHEDULER_ITASK_H
#define SCHEDULER_ITASK_H

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include "Time.h"
using std::cout;

class ITask {
public:

    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds

};

// Also an abstract class
class Task : public ITask{
public:
    explicit Task(): m_cycles(0){};
    virtual ~Task(){};

    unsigned long getCycles(){return m_cycles;}
    unsigned long incCycles(){return ++m_cycles;}

protected:

    Time m_timer;
    unsigned long m_cycles;

};



#endif //SCHEDULER_ITASK_H
