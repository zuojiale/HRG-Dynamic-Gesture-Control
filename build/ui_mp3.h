/********************************************************************************
** Form generated from reading UI file 'mp3.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MP3_H
#define UI_MP3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Mp3
{
public:
    QListWidget *songsList;
    QPushButton *playButton;
    QPushButton *stopButton;
    QSlider *volumeSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *iconLabel;

    void setupUi(QDialog *Mp3)
    {
        if (Mp3->objectName().isEmpty())
            Mp3->setObjectName(QStringLiteral("Mp3"));
        Mp3->resize(559, 303);
        songsList = new QListWidget(Mp3);
        songsList->setObjectName(QStringLiteral("songsList"));
        songsList->setGeometry(QRect(380, 30, 171, 261));
        playButton = new QPushButton(Mp3);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(40, 270, 89, 25));
        stopButton = new QPushButton(Mp3);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(180, 270, 89, 25));
        volumeSlider = new QSlider(Mp3);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(340, 30, 20, 231));
        volumeSlider->setOrientation(Qt::Vertical);
        label = new QLabel(Mp3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 6, 91, 17));
        label_2 = new QLabel(Mp3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(308, 267, 67, 20));
        label_2->setAlignment(Qt::AlignCenter);
        iconLabel = new QLabel(Mp3);
        iconLabel->setObjectName(QStringLiteral("iconLabel"));
        iconLabel->setGeometry(QRect(10, 20, 311, 241));

        retranslateUi(Mp3);

        QMetaObject::connectSlotsByName(Mp3);
    } // setupUi

    void retranslateUi(QDialog *Mp3)
    {
        Mp3->setWindowTitle(QApplication::translate("Mp3", "Dialog", Q_NULLPTR));
        playButton->setText(QApplication::translate("Mp3", "Play", Q_NULLPTR));
        stopButton->setText(QApplication::translate("Mp3", "Stop", Q_NULLPTR));
        label->setText(QApplication::translate("Mp3", "Songs List:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Mp3", "Volume", Q_NULLPTR));
        iconLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Mp3: public Ui_Mp3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MP3_H
