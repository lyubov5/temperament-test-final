#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>
#include <QStringList>

class QLabel;
class QPushButton;
class QRadioButton;
class QButtonGroup;
class QProgressBar;

class TestWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = nullptr);

signals:
    void testFinished(int resultType);

private slots:
    void nextQuestion();
    void previousQuestion();
    void finishTest();

private:
    void showQuestion(int number);
    void saveAnswer();

    QStringList questions;
    QStringList answersA;
    QStringList answersB;
    QStringList answersC;
    QStringList answersD;

    int currentQuestion;
    int answers[20];
    int resultScores[4];

    QLabel *questionLabel;
    QLabel *progressLabel;
    QProgressBar *progressBar;

    QRadioButton *answerA;
    QRadioButton *answerB;
    QRadioButton *answerC;
    QRadioButton *answerD;
    QButtonGroup *answerGroup;

    QPushButton *backButton;
    QPushButton *nextButton;
    QPushButton *finishButton;
};

#endif
