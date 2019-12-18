//
// Created by hadasswittow on 12/6/19.
//

#ifndef SCHEDULER_PRINTERTASK_H
#define SCHEDULER_PRINTERTASK_H

#include "ITask.h"
class PrinterTask : public Task{
public:
    void run();
    unsigned long getNextRunPeriod();
private:
    enum{
        INTERVAL = 1500, CYCLES = 6
    };
};
inline void PrinterTask::run(){
    cout<< " Hi this is a message from the printer!\n ";
    incCycles();

}
inline unsigned long PrinterTask::getNextRunPeriod(){
    m_timer.now();

    unsigned long next = m_timer + INTERVAL;

    cout << " -- Printer:   Next period in "<< next <<" milliseconds. "<<CYCLES - getCycles() <<" cycles left.\n";
    next = (getCycles() < CYCLES ? next: 0 );

    return next;
}

#endif //SCHEDULER_PRINTERTASK_H
