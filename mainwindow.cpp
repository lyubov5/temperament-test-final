#include "mainwindow.h"

#include <QVBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Тест на определение темперамента");
    setWindowIcon(QIcon(":/new/prefix1/photo.jpg"));
    resize(600, 400);

    titleLabel = new QLabel("Тест на определение темперамента");
    titleLabel->setAlignment(Qt::AlignCenter);

    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);

    infoLabel = new QLabel(
        "Ответьте на 20 вопросов.\n\n"
        "Тест поможет определить, какой тип темперамента у вас преобладает:\n"
        "сангвиник, холерик, флегматик или меланхолик.\n\n"
        "Здесь нет правильных или неправильных ответов.");
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setWordWrap(true);

    startButton = new QPushButton("Начать тест");
    startButton->setMinimumHeight(45);

    testWindow = new TestWindow();
    resultWindow = new ResultWindow();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(25);

    layout->addWidget(titleLabel);
    layout->addWidget(infoLabel);
    layout->addWidget(startButton);

    connect(startButton, &QPushButton::clicked,
            this, &MainWindow::openTestWindow);

    connect(testWindow, &TestWindow::testFinished,
            this, &MainWindow::openResultWindow);

    connect(resultWindow, &ResultWindow::restartTest,
            this, &MainWindow::openTestWindow);
}

void MainWindow::openTestWindow()
{
    resultWindow->hide();
    testWindow->show();
    this->hide();
}

void MainWindow::openResultWindow(int resultType)
{
    resultWindow->showResult(resultType);
    resultWindow->show();
    testWindow->hide();
}
