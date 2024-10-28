#ifndef JIYUFUCKER_H
#define JIYUFUCKER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class JiyuFucker;
    }
    QT_END_NAMESPACE

    class JiyuFucker : public QMainWindow
    {
        Q_OBJECT

    public:
        JiyuFucker(QWidget *parent = nullptr);
        ~JiyuFucker();

    private:
        Ui::JiyuFucker *ui;
    private slots:
        HWND FindJiyuWindow();
        void FuckLockScreen();
        void MakeWindowTop();
};
#endif // JIYUFUCKER_H
