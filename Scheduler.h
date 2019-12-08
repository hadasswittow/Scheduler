//
// Created by hadasswittow on 12/5/19.
//

#ifndef SCHEDULER_SCHEDULER_H
#define SCHEDULER_SCHEDULER_H

#include <vector>
#include <queue>
#include "ITask.h"
using std::vector;
class Scheduler {
public:
    void schedule();

    void addTask(Task* task){m_tasks.push(task);};
private:
    std::priority_queue<Task*,  std::vector<Task*>, std::greater<Task*> > m_tasks;

};
inline void Scheduler::schedule()
{
    unsigned long start = 0;

    while(!m_tasks.empty())
    {
        struct timeval now;  // save start time
        gettimeofday (&now, NULL);
        if(m_tasks.top()->getNextRunPeriod() <= (now.tv_sec*1000L))
        {
            Task* task = m_tasks.top();
            task->run();

            start = task->getNextRunPeriod();
            if(start)
            {
                gettimeofday (&now, NULL);
                task->setBeginTime(now.tv_sec+ start);
                addTask(task);
            }

            m_tasks.pop();
        }
        else
        {
            // Scheduler sleeps until the next tasks time
            gettimeofday (&now, NULL);
            usleep((m_tasks.top()->getBeginTime() - now.tv_sec));
        }
    }
}

#endif //SCHEDULER_SCHEDULER_H
