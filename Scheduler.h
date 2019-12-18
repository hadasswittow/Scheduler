//
// Created by hadasswittow on 12/5/19.
//

#ifndef SCHEDULER_SCHEDULER_H
#define SCHEDULER_SCHEDULER_H

#include <vector>
#include <queue>
#include "ITask.h"

using std::vector;
using std::pair;
using std::queue;
#define CREATE_TIMED_TASK(task) std::make_pair(Time((task)->getNextRunPeriod()),(task))
typedef pair<Time, Task *> TimedTask;



class Scheduler {
public:
    void schedule();

    void addTask(Task *task) { m_tasks.push(CREATE_TIMED_TASK(task)); };
private:
    queue<TimedTask> m_tasks;
    Time m_timer;

    void waitUntilNextTask();

    void executeNextTask();

    bool shouldRun();

};

inline void Scheduler::schedule() {
    unsigned long start = 0;

    while (shouldRun()) {
        // sleep if needed
        waitUntilNextTask();

        executeNextTask();
    }
}

inline void Scheduler::waitUntilNextTask() {
    m_timer.now();
    Time next_time = m_tasks.front().first;

    if (m_timer < next_time) {

        unsigned long sleep_time = next_time - m_timer.getTimeInMill();

        cout << "Scheduler next run is in :    " << next_time.getTimeInMill() << "ms, current time is " <<m_timer.getTimeInMill() << " sleeping for "<<sleep_time<<" ms.\n";

        usleep(sleep_time * 1000);
    }
}

inline void Scheduler::executeNextTask() {

    Task *task = m_tasks.front().second;
    m_tasks.pop();
    task->run();

    unsigned long next_time = task->getNextRunPeriod();
    if (next_time) {
        m_tasks.push(std::make_pair(next_time,task));
    }
    else{
        cout<<" *** task ended ***\n";
    }

}

inline bool Scheduler::shouldRun() {
    return !m_tasks.empty();
}

#endif //SCHEDULER_SCHEDULER_H
