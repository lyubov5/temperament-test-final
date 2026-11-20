#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QWidget>

class QLabel;
class QPushButton;

class ResultWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = nullptr);

public slots:
    void showResult(int resultType);

signals:
    void restartTest();

private:
    QLabel *titleLabel;
    QLabel *resultLabel;
    QLabel *imageLabel;
    QLabel *descriptionLabel;
    QPushButton *restartButton;
};

#endif
