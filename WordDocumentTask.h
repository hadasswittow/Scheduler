//
// Created by hadasswittow on 12/6/19.
//

#ifndef SCHEDULER_WORDDOCUMENTTASK_H
#define SCHEDULER_WORDDOCUMENTTASK_H

#include "ITask.h"
class WordDocumentTask :public ITask{
public:
    WordDocumentTask(size_t t, unsigned long interval):ITask(t,interval){};
    void run();
    unsigned long getNextRunPeriod();

};
inline void WordDocumentTask::run(){

    cout<< " Hi this is a message from the word document!\n ";
    m_times_to_run-=1;
}
inline unsigned long WordDocumentTask::getNextRunPeriod(){
    if(m_times_to_run)
        return m_interval;
    return 0;
}


#endif //SCHEDULER_WORDDOCUMENTTASK_H
