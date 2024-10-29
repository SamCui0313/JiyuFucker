#ifndef FUCKKEYBOARDLOCK_H
#define FUCKKEYBOARDLOCK_H

#include <QThread>
class FuckKeyboardLock:public QThread
{
public:
    FuckKeyboardLock();
    void run();
};

#endif // FUCKKEYBOARDLOCK_H
