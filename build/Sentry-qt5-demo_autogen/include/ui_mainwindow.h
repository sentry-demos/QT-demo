/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *nativeCrashButton;
    QPushButton *sentryCrashButton;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(249, 251);
        MainWindow->setStyleSheet(QString::fromUtf8("border-image: url(\":/new/images/assets/sentry-pattern.png\") 0 0 0 0 stretch;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        nativeCrashButton = new QPushButton(centralwidget);
        nativeCrashButton->setObjectName(QString::fromUtf8("nativeCrashButton"));
        nativeCrashButton->setGeometry(QRect(80, 90, 101, 32));
        QFont font;
        font.setFamily(QString::fromUtf8("Avenir"));
        nativeCrashButton->setFont(font);
        nativeCrashButton->setStyleSheet(QString::fromUtf8("background-color: rgb(108, 95, 199);\n"
"color: #fff;"));
        sentryCrashButton = new QPushButton(centralwidget);
        sentryCrashButton->setObjectName(QString::fromUtf8("sentryCrashButton"));
        sentryCrashButton->setGeometry(QRect(80, 130, 101, 31));
        sentryCrashButton->setFont(font);
        sentryCrashButton->setStyleSheet(QString::fromUtf8("background-color: rgb(108, 95, 199);\n"
"color: #fff;"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 91, 61));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/images/assets/sentry-glyph-black.png")));
        label->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        nativeCrashButton->setText(QApplication::translate("MainWindow", "Native Crash", nullptr));
        sentryCrashButton->setText(QApplication::translate("MainWindow", "Sentry Event", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
