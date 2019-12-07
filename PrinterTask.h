//
// Created by hadasswittow on 12/6/19.
//

#ifndef SCHEDULER_PRINTERTASK_H
#define SCHEDULER_PRINTERTASK_H

#include "ITask.h"
class PrinterTask : public ITask{
public:
    PrinterTask(size_t t, unsigned long interval):ITask(t,interval){};
    void run();
    unsigned long getNextRunPeriod();
};
inline void PrinterTask::run(){

    cout<< " Hi this is a message from the printer!\n ";
    m_times_to_run-=1;

}
inline unsigned long PrinterTask::getNextRunPeriod(){
    if(m_times_to_run)
        return m_interval;
    return 0;
}

#endif //SCHEDULER_PRINTERTASK_H
