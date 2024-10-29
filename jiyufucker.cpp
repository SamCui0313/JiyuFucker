#include "jiyufucker.h"
#include "./ui_jiyufucker.h"
#include "jiyufucker.h"
#include "./ui_jiyufucker.h"
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QWinEventNotifier>
#include <Windows.h>
#include <QDebug>
#include <QPushButton>
#include <QScreen>
#include <QRect>
#include "winuser.h"
#include "CommCtrl.h"
#include "fuckkeyboardlock.h"
bool JiyuFucker::isFuckingKeyboardLock=false;
JiyuFucker::JiyuFucker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JiyuFucker)
{

    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->setupUi(this);
    QRect screenSize = QGuiApplication::screens().at(0)->availableGeometry();
    this->setFixedSize(screenSize.width(),screenSize.height()-5);
    SetWindowLongA((HWND)this->winId(), -20, GetWindowLongA((HWND)this->winId(),-20)|524288);
    MakeWindowTop();


    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &JiyuFucker::MakeWindowTop);
    timer->start(100); // 每秒强制置顶

    QPushButton* FuckLockScreenButton = ui->unlockFullScreenButton;
    FuckLockScreenButton->setParent(this);
    FuckLockScreenButton->raise();
    connect(FuckLockScreenButton,&QPushButton::clicked,this,&JiyuFucker::FuckLockScreen);

    QPushButton* FuckKeyboardLockButton = ui->FuckKeyboardLockButton;
    FuckKeyboardLockButton->setParent(this);
    FuckKeyboardLockButton->raise();
    connect(FuckKeyboardLockButton,&QPushButton::clicked,this,&JiyuFucker::FuckKeyboardLockFunction);
}

JiyuFucker::~JiyuFucker()
{
    delete ui;
}
HWND JiyuFucker::FindJiyuWindow() {
    HWND hwnd = FindWindowW(NULL,L"屏幕广播");
    qDebug() << hwnd;
    return hwnd;
}

void JiyuFucker::FuckLockScreen() {
    HWND hwnd=FindJiyuWindow();
    if(hwnd){
        //模拟点击解除全屏按钮
        PostMessage(hwnd, WM_COMMAND, WPARAM((BM_CLICK << 16) | 1004), NULL);
    }
}
void JiyuFucker::MakeWindowTop(){
    SetWindowPos((HWND)this->winId(),HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_DRAWFRAME | SWP_NOSIZE);
}
void JiyuFucker::FuckKeyboardLockFunction(){
    FuckKeyboardLock* keythread = new FuckKeyboardLock();
    keythread->start();
    if(this->isFuckingKeyboardLock){
        isFuckingKeyboardLock=false;
        ui->FuckKeyboardLockButton->setText("解除键盘锁");
    } else {
        isFuckingKeyboardLock=true;
        ui->FuckKeyboardLockButton->setText("打开键盘锁");
    }
}
