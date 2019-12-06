//
// Created by hadasswittow on 12/5/19.
//

#ifndef SCHEDULER_TIME_H
#define SCHEDULER_TIME_H


class Time {

public:
    void now(); // change the time to now

};
inline bool operator<=(Time& t1,Time& t2 ){

}
bool operator<(Time& t1,Time& t2);
bool operator>=(Time& t1,Time& t2);
bool operator>(Time& t1,Time& t2);
Time operator+(Time& t1,Time& t2);

#endif //SCHEDULER_TIME_H
