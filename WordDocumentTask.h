//
// Created by hadasswittow on 12/6/19.
//

#ifndef SCHEDULER_WORDDOCUMENTTASK_H
#define SCHEDULER_WORDDOCUMENTTASK_H

#include "ITask.h"
class WordDocumentTask :public Task{
public:
    WordDocumentTask(size_t t, unsigned long interval, unsigned long start):Task(t,interval,start){};
    void runImplementation();
    unsigned long getNextRunPeriod();

};
inline void WordDocumentTask::runImplementation(){

    cout<< " Hi this is a message from the word document!\n ";
}
inline unsigned long WordDocumentTask::getNextRunPeriod(){
    if(m_times_to_run)
        return m_next_run_period;
    return 0;
}


#endif //SCHEDULER_WORDDOCUMENTTASK_H
