/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QSlider *horizonFPS;
    QLabel *labelView;
    QLabel *labelFPS;
    QPushButton *buttonConnect;
    QTextEdit *textInfo;
    QLabel *labelInformation;
    QPushButton *buttonDisconnect;
    QPushButton *buttonSave;
    QLCDNumber *lcdPredict;
    QPushButton *buttonTrain;
    QLabel *labelDepth;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(849, 478);
        horizonFPS = new QSlider(Widget);
        horizonFPS->setObjectName(QStringLiteral("horizonFPS"));
        horizonFPS->setGeometry(QRect(270, 447, 281, 21));
        horizonFPS->setOrientation(Qt::Horizontal);
        labelView = new QLabel(Widget);
        labelView->setObjectName(QStringLiteral("labelView"));
        labelView->setGeometry(QRect(10, 10, 541, 421));
        QFont font;
        font.setPointSize(11);
        labelView->setFont(font);
        labelFPS = new QLabel(Widget);
        labelFPS->setObjectName(QStringLiteral("labelFPS"));
        labelFPS->setGeometry(QRect(140, 448, 121, 17));
        labelFPS->setAlignment(Qt::AlignCenter);
        buttonConnect = new QPushButton(Widget);
        buttonConnect->setObjectName(QStringLiteral("buttonConnect"));
        buttonConnect->setGeometry(QRect(560, 440, 121, 31));
        textInfo = new QTextEdit(Widget);
        textInfo->setObjectName(QStringLiteral("textInfo"));
        textInfo->setGeometry(QRect(560, 310, 281, 121));
        textInfo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textInfo->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        labelInformation = new QLabel(Widget);
        labelInformation->setObjectName(QStringLiteral("labelInformation"));
        labelInformation->setGeometry(QRect(560, 280, 131, 31));
        labelInformation->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        buttonDisconnect = new QPushButton(Widget);
        buttonDisconnect->setObjectName(QStringLiteral("buttonDisconnect"));
        buttonDisconnect->setGeometry(QRect(690, 440, 151, 31));
        buttonSave = new QPushButton(Widget);
        buttonSave->setObjectName(QStringLiteral("buttonSave"));
        buttonSave->setGeometry(QRect(10, 445, 111, 25));
        lcdPredict = new QLCDNumber(Widget);
        lcdPredict->setObjectName(QStringLiteral("lcdPredict"));
        lcdPredict->setGeometry(QRect(710, 249, 121, 51));
        QFont font1;
        font1.setPointSize(33);
        lcdPredict->setFont(font1);
        lcdPredict->setLineWidth(1);
        lcdPredict->setMidLineWidth(0);
        lcdPredict->setProperty("intValue", QVariant(0));
        buttonTrain = new QPushButton(Widget);
        buttonTrain->setObjectName(QStringLiteral("buttonTrain"));
        buttonTrain->setGeometry(QRect(560, 250, 141, 25));
        labelDepth = new QLabel(Widget);
        labelDepth->setObjectName(QStringLiteral("labelDepth"));
        labelDepth->setGeometry(QRect(560, 10, 280, 231));
        labelDepth->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        labelView->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">NO HRG_TOF CAMERA DETECTED!</span></p></body></html>", Q_NULLPTR));
        labelFPS->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:12pt;\">Updateing Time</span></p></body></html>", Q_NULLPTR));
        buttonConnect->setText(QApplication::translate("Widget", "Connect To HRG", Q_NULLPTR));
        labelInformation->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:14pt;\">Information:</span></p></body></html>", Q_NULLPTR));
        buttonDisconnect->setText(QApplication::translate("Widget", "Disconnect From HRG", Q_NULLPTR));
        buttonSave->setText(QApplication::translate("Widget", "Save Image", Q_NULLPTR));
        buttonTrain->setText(QApplication::translate("Widget", "Train New Gesture", Q_NULLPTR));
        labelDepth->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">Depth</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
