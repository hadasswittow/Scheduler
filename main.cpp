#include <iostream>
#include "Scheduler.h"
#include "PrinterTask.h"
#include "WordDocumentTask.h"
int main() {
    Scheduler scheduler;
    PrinterTask p;
    WordDocumentTask wd;
    scheduler.addTask(&p);
    scheduler.addTask(&wd);
    scheduler.schedule();
    return 0;
}