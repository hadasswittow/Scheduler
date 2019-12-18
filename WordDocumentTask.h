//
// Created by hadasswittow on 12/6/19.
//

#ifndef SCHEDULER_WORDDOCUMENTTASK_H
#define SCHEDULER_WORDDOCUMENTTASK_H

#include "ITask.h"
class WordDocumentTask :public Task{
public:
    void run();
    unsigned long getNextRunPeriod();
private:
    enum{
        INTERVAL = 1000, CYCLES = 8
    };

};inline void WordDocumentTask::run(){
    cout<< " Hi this is a message from the WordDocumentTask!\n ";
    incCycles();

}
inline unsigned long WordDocumentTask::getNextRunPeriod(){
    m_timer.now();

    unsigned long next = m_timer + INTERVAL;

    cout << " -- WordDocument:   Next period in "<< next <<" milliseconds. "<<CYCLES - getCycles() <<" cycles left.\n";
    next = (getCycles() < CYCLES ? next: 0 );

    return next;
}

#endif //SCHEDULER_WORDDOCUMENTTASK_H
