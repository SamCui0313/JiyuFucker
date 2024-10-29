#include "fuckkeyboardlock.h"
#include "jiyufucker.h"
#include <windows.h>
#include <QDebug>
FuckKeyboardLock::FuckKeyboardLock() {

}

LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam){
    return FALSE;
}

void FuckKeyboardLock::run() {
    HHOOK kbdHook;
    while(1){
        if(JiyuFucker::isFuckingKeyboardLock){
            kbdHook = (HHOOK)SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)HookProc, GetModuleHandle(NULL), 0);
            Sleep(25);
            UnhookWindowsHookEx(kbdHook);
            qDebug() << "thread is running";
        } else {
            //如果不解锁时不添加sleep，cpu占用率会很高
            Sleep(25);
        }
    }
}
