//
// Created by hadasswittow on 12/5/19.
//

#ifndef SCHEDULER_SCHEDULER_H
#define SCHEDULER_SCHEDULER_H

#include <vector>
#include "ITask.h"
using std::vector;
class Scheduler {
public:
    void schedule();

    void addTask(ITask* task){m_tasks.push_back(task);};
private:
    vector<ITask*> m_tasks;

};
inline void Scheduler::schedule(){
    ITask* task;
    while(!m_tasks.empty()){
        task = m_tasks.front();
        m_tasks.erase(m_tasks.begin());
        task->run();
        if(task->getNextRunPeriod()>0)
            m_tasks.push_back(task);
    }
}

#endif //SCHEDULER_SCHEDULER_H
