#include "testwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QProgressBar>
#include <QMessageBox>
#include <QFont>

TestWindow::TestWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Прохождение теста");
    resize(650, 550);

    questions = {
        "Как вы обычно ведёте себя в новой компании?",
        "Как вы реагируете на неожиданную проблему?",
        "Какой у вас темп работы?",
        "Как вы реагируете на критику?",
        "Как вы принимаете решения?",
        "Как вы ведёте себя во время конфликта?",
        "Как вы переносите перемены?",
        "Как вы проявляете эмоции?",
        "Как вы обычно отдыхаете?",
        "Как вы относитесь к новым знакомствам?",
        "Что вы делаете, если что-то не получается?",
        "Как вы относитесь к многозадачности?",
        "Как вы обычно реагируете на похвалу?",
        "Как вы ведёте себя в стрессовой ситуации?",
        "Насколько вы терпеливы?",
        "Как вы относитесь к лидерству?",
        "Как быстро меняется ваше настроение?",
        "Как вы относитесь к незавершённым делам?",
        "Как вы реагируете на неудачи?",
        "Какое описание вам ближе всего?"
    };

    answersA = {
        "Быстро включаюсь в общение и знакомлюсь",
        "Сохраняю оптимизм и ищу решение",
        "Активный, особенно если задача интересная",
        "Отношусь легко, стараюсь не принимать близко к сердцу",
        "Легко, часто полагаясь на интуицию",
        "Стараюсь разрядить обстановку",
        "Воспринимаю их с интересом",
        "Эмоционально, легко и непринуждённо",
        "Люблю встречи, компании и развлечения",
        "Обожаю знакомиться и общаться",
        "Пробую другой способ и не унываю",
        "Легко переключаюсь между задачами",
        "Радуюсь и охотно делюсь эмоциями",
        "Стараюсь сохранять позитивный настрой",
        "Обычно терпелив, но быстро теряю интерес",
        "Мне нравится объединять и вдохновлять людей",
        "Быстро, но обычно в положительную сторону",
        "Могу переключиться на что-то более интересное",
        "Стараюсь не зацикливаться",
        "Жизнерадостный, общительный, оптимистичный"
    };
    answersB = {
        "Стараюсь быть в центре внимания и проявлять инициативу",
        "Быстро действую, иногда не раздумывая",
        "Быстрый, люблю динамику",
        "Могу резко ответить",
        "Быстро и решительно",
        "Активно отстаиваю свою позицию",
        "Люблю перемены, если могу действовать",
        "Ярко, бурно и открыто",
        "Предпочитаю активный отдых",
        "Легко знакомлюсь, если есть интерес",
        "Злюсь, но продолжаю добиваться результата",
        "Люблю много дел и быстро переключаюсь",
        "Принимаю с уверенностью и энтузиазмом",
        "Становлюсь активнее и пытаюсь всё контролировать",
        "Могу быть нетерпеливым, если всё идёт медленно",
        "Люблю руководить и принимать решения",
        "Быстро, иногда очень резко",
        "Раздражаюсь и хочу скорее всё закончить",
        "Быстро мобилизуюсь и иду дальше",
        "Решительный, энергичный, вспыльчивый"
    };

    answersC = {
        "Сначала присматриваюсь и наблюдаю",
        "Спокойно анализирую ситуацию",
        "Размеренный и стабильный",
        "Спокойно выслушиваю",
        "Обдуманно и без спешки",
        "Избегаю конфликта и сохраняю спокойствие",
        "Предпочитаю привычный порядок",
        "Сдержанно и спокойно",
        "Выбираю спокойный отдых",
        "Не стремлюсь к большому количеству знакомств",
        "Продолжаю спокойно и последовательно",
        "Предпочитаю выполнять дела по очереди",
        "Отношусь спокойно",
        "Сохраняю внешнее спокойствие",
        "Очень терпелив и выдержан",
        "Могу руководить, если это необходимо",
        "Медленно, настроение достаточно стабильное",
        "Предпочитаю спокойно довести всё до конца",
        "Принимаю ситуацию и постепенно исправляю ошибки",
        "Спокойный, надёжный, последовательный"
    };
    answersD = {
        "Чувствую скованность и долго привыкаю",
        "Переживаю и долго обдумываю последствия",
        "Неспешный, предпочитаю всё тщательно проверять",
        "Сильно переживаю и анализирую сказанное",
        "Долго взвешиваю все варианты",
        "Принимаю всё близко к сердцу",
        "Перемены вызывают у меня тревогу",
        "Глубоко, но не всегда показываю окружающим",
        "Люблю уединение и занятия для души",
        "Сложно первым начать разговор",
        "Расстраиваюсь и могу потерять уверенность",
        "Мне сложно переключаться, если я сосредоточен на одном",
        "Смущаюсь, но долго помню приятные слова",
        "Сильно волнуюсь и эмоционально реагирую",
        "Терпелив, но склонен долго переживать",
        "Предпочитаю работать самостоятельно или в небольшой группе",
        "Могу долго находиться под влиянием переживаний",
        "Переживаю, если что-то осталось незавершённым",
        "Долго анализирую и эмоционально переживаю",
        "Чувствительный, внимательный, склонный к размышлениям"
    };

    currentQuestion = 0;

    for (int i = 0; i < 20; i++) {
        answers[i] = -1;
    }

    for (int i = 0; i < 4; i++) {
        resultScores[i] = 0;
    }

    questionLabel = new QLabel();
    questionLabel->setWordWrap(true);

    QFont questionFont = questionLabel->font();
    questionFont.setPointSize(13);
    questionFont.setBold(true);
    questionLabel->setFont(questionFont);

    progressLabel = new QLabel();
    progressLabel->setAlignment(Qt::AlignCenter);

    progressBar = new QProgressBar();
    progressBar->setRange(0, 20);
    progressBar->setValue(0);

    answerA = new QRadioButton();
    answerB = new QRadioButton();
    answerC = new QRadioButton();
    answerD = new QRadioButton();
    answerGroup = new QButtonGroup(this);

    answerGroup->addButton(answerA, 0);
    answerGroup->addButton(answerB, 1);
    answerGroup->addButton(answerC, 2);
    answerGroup->addButton(answerD, 3);

    backButton = new QPushButton("Назад");
    nextButton = new QPushButton("Далее");
    finishButton = new QPushButton("Узнать мой темперамент");
    finishButton->setMinimumHeight(45);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(30, 30, 30, 30);
    mainLayout->setSpacing(20);

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(backButton);
    buttonsLayout->addWidget(nextButton);

    mainLayout->addWidget(progressLabel);
    mainLayout->addWidget(progressBar);
    mainLayout->addWidget(questionLabel);
    mainLayout->addWidget(answerA);
    mainLayout->addWidget(answerB);
    mainLayout->addWidget(answerC);
    mainLayout->addWidget(answerD);
    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(finishButton);

    connect(backButton, &QPushButton::clicked,
            this, &TestWindow::previousQuestion);

    connect(nextButton, &QPushButton::clicked,
            this, &TestWindow::nextQuestion);

    connect(finishButton, &QPushButton::clicked,
            this, &TestWindow::finishTest);

    showQuestion(0);
}

void TestWindow::showQuestion(int number)
{
    currentQuestion = number;

    questionLabel->setText(
        "Вопрос " + QString::number(number + 1) + " из 20\n\n" +
        questions.at(number));

    progressLabel->setText(
        "Прогресс: " + QString::number(number + 1) + " из 20");

    progressBar->setValue(number + 1);

    answerA->setText("А. " + answersA.at(number));
    answerB->setText("Б. " + answersB.at(number));
    answerC->setText("В. " + answersC.at(number));
    answerD->setText("Г. " + answersD.at(number));

    answerGroup->setExclusive(false);

    answerA->setChecked(false);
    answerB->setChecked(false);
    answerC->setChecked(false);
    answerD->setChecked(false);

    answerGroup->setExclusive(true);
    if (answers[number] == 0) {
        answerA->setChecked(true);
    }
    else if (answers[number] == 1) {
        answerB->setChecked(true);
    }
    else if (answers[number] == 2) {
        answerC->setChecked(true);
    }
    else if (answers[number] == 3) {
        answerD->setChecked(true);
    }

    backButton->setEnabled(number > 0);
    nextButton->setEnabled(number < 19);
    finishButton->setEnabled(number == 19);
}

void TestWindow::saveAnswer()
{
    if (answerA->isChecked()) {
        answers[currentQuestion] = 0;
    }
    else if (answerB->isChecked()) {
        answers[currentQuestion] = 1;
    }
    else if (answerC->isChecked()) {
        answers[currentQuestion] = 2;
    }
    else if (answerD->isChecked()) {
        answers[currentQuestion] = 3;
    }
    else {
        answers[currentQuestion] = -1;
    }
}

void TestWindow::nextQuestion()
{
    saveAnswer();

    if (answers[currentQuestion] == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите один вариант ответа.");
        return;
    }

    if (currentQuestion < 19) {
        showQuestion(currentQuestion + 1);
    }
}

void TestWindow::previousQuestion()
{
    saveAnswer();

    if (currentQuestion > 0) {
        showQuestion(currentQuestion - 1);
    }
}

void TestWindow::finishTest()
{
    saveAnswer();

    if (answers[currentQuestion] == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите один вариант ответа.");
        return;
    }

    for (int i = 0; i < 4; i++) {
        resultScores[i] = 0;
    }

    for (int i = 0; i < 20; i++) {
        if (answers[i] != -1) {
            resultScores[answers[i]]++;
        }
    }

    int maxScore = resultScores[0];
    int resultType = 0;

    for (int i = 1; i < 4; i++) {
        if (resultScores[i] > maxScore) {
            maxScore = resultScores[i];
            resultType = i;
        }
    }

    emit testFinished(resultType);
}
