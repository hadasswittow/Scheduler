//
// Created by hadasswittow on 12/6/19.
//

#ifndef SCHEDULER_PRINTERTASK_H
#define SCHEDULER_PRINTERTASK_H

#include "ITask.h"
class PrinterTask : public Task{
public:
    PrinterTask(size_t t, unsigned long interval,unsigned long start):Task(t,interval,start){};
    void runImplementation();
    unsigned long getNextRunPeriod();

};
inline void PrinterTask::runImplementation(){
    cout<< " Hi this is a message from the printer!\n ";

}
inline unsigned long PrinterTask::getNextRunPeriod(){
    if(m_times_to_run)
        return m_next_run_period;
    return 0;
}

#endif //SCHEDULER_PRINTERTASK_H
