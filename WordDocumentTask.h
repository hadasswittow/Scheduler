//
// Created by hadasswittow on 12/6/19.
//

#ifndef SCHEDULER_WORDDOCUMENTTASK_H
#define SCHEDULER_WORDDOCUMENTTASK_H

#include "ITask.h"
class WordDocumentTask :public ITask{
public:
    WordDocumentTask():ITask(0){};
    void run();
    unsigned long getNextRunPeriod();
    void setNextRunPeriod();

};
inline void WordDocumentTask::run(){

    cout<< " Hi this is a message from the word document!\n ";
    setNextRunPeriod();

}
inline void WordDocumentTask::setNextRunPeriod(){

    if(m_next_run_period < 200){
        m_next_run_period+= 50;
    }else{
        m_next_run_period = 0;
    }
}
inline unsigned long WordDocumentTask::getNextRunPeriod(){
    return m_next_run_period;
}


#endif //SCHEDULER_WORDDOCUMENTTASK_H
