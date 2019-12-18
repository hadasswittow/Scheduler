#include <iostream>
#include "Scheduler.h"
#include "PrinterTask.h"
#include "WordDocumentTask.h"
int main() {
    Scheduler scheduler;

    scheduler.addTask(new PrinterTask);
    scheduler.addTask(new WordDocumentTask);

    scheduler.schedule();
    return 0;
}






//#include <cstdio>
//#include <ctime>
//#include <unistd.h>
//#include <chrono>
//#include <unistd.h>
//#include <iostream>
//int main ()
//{
//    std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
//    std::chrono::system_clock::time_point time1 = std::chrono::system_clock::now();
//
//    std::cout<< "equals:  "<<(time.operator+=+ + time1)<<std::endl;
//
//    return 0;
//}