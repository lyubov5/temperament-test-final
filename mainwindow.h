#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "testwindow.h"
#include "resultwindow.h"

class QLabel;
class QPushButton;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void openTestWindow();
    void openResultWindow(int resultType);

private:
    QLabel *titleLabel;
    QLabel *infoLabel;
    QPushButton *startButton;

    TestWindow *testWindow;
    ResultWindow *resultWindow;
};

#endif
