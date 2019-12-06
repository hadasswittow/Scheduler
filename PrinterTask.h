//
// Created by hadasswittow on 12/6/19.
//

#ifndef SCHEDULER_PRINTERTASK_H
#define SCHEDULER_PRINTERTASK_H

#include "ITask.h"
class PrinterTask : public ITask{
public:
    PrinterTask():ITask(0){};
    void run();
    unsigned long getNextRunPeriod();
    void setNextRunPeriod();
};
inline void PrinterTask::run(){

    cout<< " Hi this is a message from the printer!\n ";
    setNextRunPeriod();

}
inline void PrinterTask::setNextRunPeriod(){

    if(m_next_run_period < 200){
        m_next_run_period+= 30;
    }else{
        m_next_run_period = 0;
    }
}
inline unsigned long PrinterTask::getNextRunPeriod(){
    return m_next_run_period;
}

#endif //SCHEDULER_PRINTERTASK_H
