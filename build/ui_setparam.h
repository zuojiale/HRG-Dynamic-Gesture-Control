/********************************************************************************
** Form generated from reading UI file 'setparam.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPARAM_H
#define UI_SETPARAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_setparam
{
public:
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QLineEdit *lineIP;
    QLabel *label;
    QLineEdit *linePort;
    QLabel *label_2;
    QGroupBox *groupBox;
    QRadioButton *radioUSB;
    QRadioButton *radioNET;

    void setupUi(QDialog *setparam)
    {
        if (setparam->objectName().isEmpty())
            setparam->setObjectName(QStringLiteral("setparam"));
        setparam->resize(273, 198);
        buttonOk = new QPushButton(setparam);
        buttonOk->setObjectName(QStringLiteral("buttonOk"));
        buttonOk->setGeometry(QRect(10, 157, 80, 25));
        buttonCancel = new QPushButton(setparam);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(183, 157, 80, 25));
        lineIP = new QLineEdit(setparam);
        lineIP->setObjectName(QStringLiteral("lineIP"));
        lineIP->setGeometry(QRect(83, 67, 181, 25));
        label = new QLabel(setparam);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 69, 67, 17));
        linePort = new QLineEdit(setparam);
        linePort->setObjectName(QStringLiteral("linePort"));
        linePort->setGeometry(QRect(83, 112, 181, 25));
        label_2 = new QLabel(setparam);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 115, 67, 17));
        groupBox = new QGroupBox(setparam);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 5, 251, 51));
        radioUSB = new QRadioButton(groupBox);
        radioUSB->setObjectName(QStringLiteral("radioUSB"));
        radioUSB->setGeometry(QRect(20, 26, 112, 20));
        radioNET = new QRadioButton(groupBox);
        radioNET->setObjectName(QStringLiteral("radioNET"));
        radioNET->setGeometry(QRect(170, 25, 112, 23));

        retranslateUi(setparam);

        QMetaObject::connectSlotsByName(setparam);
    } // setupUi

    void retranslateUi(QDialog *setparam)
    {
        setparam->setWindowTitle(QApplication::translate("setparam", "Dialog", Q_NULLPTR));
        buttonOk->setText(QApplication::translate("setparam", "ok", Q_NULLPTR));
        buttonCancel->setText(QApplication::translate("setparam", "cancel", Q_NULLPTR));
        lineIP->setText(QApplication::translate("setparam", "192.168.1.6", Q_NULLPTR));
        label->setText(QApplication::translate("setparam", "IP:", Q_NULLPTR));
        linePort->setText(QApplication::translate("setparam", "8567", Q_NULLPTR));
        label_2->setText(QApplication::translate("setparam", "Port:", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("setparam", "Connecting Ways:", Q_NULLPTR));
        radioUSB->setText(QApplication::translate("setparam", "USB", Q_NULLPTR));
        radioNET->setText(QApplication::translate("setparam", "NET", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class setparam: public Ui_setparam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPARAM_H
