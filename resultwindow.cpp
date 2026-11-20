#include "resultwindow.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QFont>

ResultWindow::ResultWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Результат теста");
    resize(650, 600);

    titleLabel = new QLabel("Ваш результат");
    titleLabel->setAlignment(Qt::AlignCenter);

    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);

    resultLabel = new QLabel();
    resultLabel->setAlignment(Qt::AlignCenter);

    QFont resultFont = resultLabel->font();
    resultFont.setPointSize(15);
    resultFont.setBold(true);
    resultLabel->setFont(resultFont);

    imageLabel = new QLabel();
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setFixedSize(220, 220);

    descriptionLabel = new QLabel();
    descriptionLabel->setWordWrap(true);
    descriptionLabel->setAlignment(Qt::AlignTop);

    restartButton = new QPushButton("Пройти тест заново");
    restartButton->setMinimumHeight(45);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(30, 30, 30, 30);
    layout->setSpacing(20);

    layout->addWidget(titleLabel);
    layout->addWidget(resultLabel);
    layout->addWidget(imageLabel);
    layout->addWidget(descriptionLabel, 1);
    layout->addWidget(restartButton);

    connect(restartButton, &QPushButton::clicked,
            this, &ResultWindow::restartTest);
}

void ResultWindow::showResult(int resultType)
{
    QString typeName;
    QString imagePath;
    QString description;

    if (resultType == 0) {
        typeName = "Сангвиник";
        imagePath = ":/new/prefix1/sang.jpeg";

        description =
            "Ты — сангвиник: человек-солнце, который заряжает окружающих энергией "
            "и легко находит общий язык с кем угодно.\n\n"
            "Тебе подойдут питомцы, разделяющие твою активность и общительность: "
            "лабрадор, корги или бигль, попугай или социальная кошка вроде мейн-куна.\n\n"
            "Тебе подходят профессии, где нужно много общаться и быстро реагировать: "
            "менеджер по продажам, журналист, ведущий мероприятий, PR-специалист.\n\n"
            "Сильные стороны: коммуникабельность, стрессоустойчивость и быстрое принятие решений.\n"
            "Слабые стороны: непостоянство и поверхностность.\n\n"
            "Совет: учись концентрации и планированию.";
    }
    else if (resultType == 1) {
        typeName = "Холерик";
        imagePath = ":/new/prefix1/holer.jpeg";

        description =
            "Ты — холерик: страстный, целеустремлённый и вспыльчивый лидер по натуре.\n\n"
            "Тебе подойдут активные собаки: хаски, доберман или овчарка.\n\n"
            "Тебе подходят профессии, где нужны решительность и умение вести за собой: "
            "руководитель, предприниматель, спортсмен, хирург.\n\n"
            "Сильные стороны: инициативность, решительность и лидерство.\n"
            "Слабые стороны: нетерпеливость, резкость и вспыльчивость.\n\n"
            "Совет: работай над самоконтролем и учись слушать других.";
    }
    else if (resultType == 2) {
        typeName = "Флегматик";
        imagePath = ":/new/prefix1/fleg.jpeg";

        description =
            "Ты — флегматик: спокойный, уравновешенный и надёжный человек.\n\n"
            "Тебе подойдут питомцы, не требующие суеты: британская или персидская кошка, "
            "спокойная собака, аквариумные рыбки или черепаха.\n\n"
            "Тебе подходят профессии, где ценятся терпение и стабильность: бухгалтер, "
            "программист, инженер, аналитик, библиотекарь.\n\n"
            "Сильные стороны: терпение, надёжность, умение слушать и стабильность.\n"
            "Слабые стороны: медлительность, пассивность и трудность в принятии перемен.\n\n"
            "Совет: ставь себе дедлайны и пробуй новое.";
    }
    else {
        typeName = "Меланхолик";
        imagePath = ":/new/prefix1/melan.jpeg";

        description =
            "Ты — меланхолик: чувствительный, вдумчивый и творческий человек.\n\n"
            "Тебе подойдут привязчивые и тихие питомцы: сфинкс или рэгдолл, "
            "маленькая собака, кролик или хомяк.\n\n"
            "Тебе подходят профессии, где важны глубина и внимание к деталям: художник, "
            "писатель, психолог, дизайнер, музыкант, научный исследователь.\n\n"
            "Сильные стороны: глубина чувств, эмпатия, креативность и внимание к деталям.\n"
            "Слабые стороны: тревожность, обидчивость и склонность к самокопанию.\n\n"
            "Совет: учись выражать эмоции и не бояться ошибок.";
    }

    resultLabel->setText("Преобладающий темперамент: " + typeName);

    QPixmap pixmap(imagePath);

    if (!pixmap.isNull()) {
        imageLabel->setPixmap(
            pixmap.scaled(220, 220, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else {
        imageLabel->setText("Изображение не найдено");
    }

    descriptionLabel->setText(description);
}
