/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Nov 29 00:26:56 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *HideData;
    QLabel *EnterCoverImage;
    QPushButton *Browse1;
    QLabel *EnterSecretFile;
    QPushButton *Browse2;
    QPushButton *ViewImage;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QLabel *EnterKey;
    QPushButton *DoIt;
    QPushButton *Exit1;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *RecoverData;
    QLabel *EnterStegoImage;
    QPushButton *Browse3;
    QPushButton *ViewImage2;
    QLabel *Enterkey2;
    QLineEdit *lineEdit_2;
    QPushButton *DoIt2;
    QLabel *label;
    QPushButton *Exit2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(456, 341);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../image/input/blocks.ppm"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 421, 291));
        HideData = new QWidget();
        HideData->setObjectName(QString::fromUtf8("HideData"));
        EnterCoverImage = new QLabel(HideData);
        EnterCoverImage->setObjectName(QString::fromUtf8("EnterCoverImage"));
        EnterCoverImage->setGeometry(QRect(20, 30, 131, 17));
        Browse1 = new QPushButton(HideData);
        Browse1->setObjectName(QString::fromUtf8("Browse1"));
        Browse1->setGeometry(QRect(150, 30, 71, 27));
        EnterSecretFile = new QLabel(HideData);
        EnterSecretFile->setObjectName(QString::fromUtf8("EnterSecretFile"));
        EnterSecretFile->setGeometry(QRect(20, 70, 111, 20));
        Browse2 = new QPushButton(HideData);
        Browse2->setObjectName(QString::fromUtf8("Browse2"));
        Browse2->setGeometry(QRect(150, 70, 71, 27));
        ViewImage = new QPushButton(HideData);
        ViewImage->setObjectName(QString::fromUtf8("ViewImage"));
        ViewImage->setGeometry(QRect(260, 30, 81, 27));
        checkBox = new QCheckBox(HideData);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(60, 110, 181, 22));
        checkBox->setChecked(true);
        lineEdit = new QLineEdit(HideData);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 140, 113, 27));
        lineEdit->setEchoMode(QLineEdit::Password);
        EnterKey = new QLabel(HideData);
        EnterKey->setObjectName(QString::fromUtf8("EnterKey"));
        EnterKey->setGeometry(QRect(60, 140, 67, 17));
        DoIt = new QPushButton(HideData);
        DoIt->setObjectName(QString::fromUtf8("DoIt"));
        DoIt->setGeometry(QRect(130, 170, 97, 27));
        Exit1 = new QPushButton(HideData);
        Exit1->setObjectName(QString::fromUtf8("Exit1"));
        Exit1->setGeometry(QRect(320, 210, 61, 27));
        pushButton = new QPushButton(HideData);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 210, 121, 27));
        pushButton_2 = new QPushButton(HideData);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 210, 131, 27));
        tabWidget->addTab(HideData, QString());
        RecoverData = new QWidget();
        RecoverData->setObjectName(QString::fromUtf8("RecoverData"));
        EnterStegoImage = new QLabel(RecoverData);
        EnterStegoImage->setObjectName(QString::fromUtf8("EnterStegoImage"));
        EnterStegoImage->setGeometry(QRect(20, 30, 131, 17));
        Browse3 = new QPushButton(RecoverData);
        Browse3->setObjectName(QString::fromUtf8("Browse3"));
        Browse3->setGeometry(QRect(150, 30, 71, 27));
        ViewImage2 = new QPushButton(RecoverData);
        ViewImage2->setObjectName(QString::fromUtf8("ViewImage2"));
        ViewImage2->setGeometry(QRect(260, 30, 81, 27));
        Enterkey2 = new QLabel(RecoverData);
        Enterkey2->setObjectName(QString::fromUtf8("Enterkey2"));
        Enterkey2->setEnabled(false);
        Enterkey2->setGeometry(QRect(100, 80, 171, 17));
        lineEdit_2 = new QLineEdit(RecoverData);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(130, 110, 131, 27));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        DoIt2 = new QPushButton(RecoverData);
        DoIt2->setObjectName(QString::fromUtf8("DoIt2"));
        DoIt2->setGeometry(QRect(130, 170, 97, 27));
        label = new QLabel(RecoverData);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(50, 110, 67, 17));
        Exit2 = new QPushButton(RecoverData);
        Exit2->setObjectName(QString::fromUtf8("Exit2"));
        Exit2->setGeometry(QRect(280, 170, 61, 27));
        tabWidget->addTab(RecoverData, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 456, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(checkBox, SIGNAL(toggled(bool)), EnterKey, SLOT(setEnabled(bool)));
        QObject::connect(checkBox, SIGNAL(toggled(bool)), lineEdit, SLOT(setEnabled(bool)));
        QObject::connect(Browse1, SIGNAL(clicked(bool)), MainWindow, SLOT(GetCoverImageName()));
        QObject::connect(Browse2, SIGNAL(clicked(bool)), MainWindow, SLOT(GetSecretFileName()));
        QObject::connect(ViewImage, SIGNAL(clicked(bool)), MainWindow, SLOT(ViewCoverImage()));
        QObject::connect(DoIt, SIGNAL(clicked(bool)), MainWindow, SLOT(Stegn()));
        QObject::connect(Browse3, SIGNAL(clicked(bool)), MainWindow, SLOT(GetStegoFileName()));
        QObject::connect(DoIt2, SIGNAL(clicked(bool)), MainWindow, SLOT(Invstegn()));
        QObject::connect(ViewImage2, SIGNAL(clicked(bool)), MainWindow, SLOT(ViewStegoImage()));
        QObject::connect(Exit1, SIGNAL(clicked(bool)), MainWindow, SLOT(close()));
        QObject::connect(Exit2, SIGNAL(clicked(bool)), MainWindow, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked(bool)), MainWindow, SLOT(ViewPreviousFile()));
        QObject::connect(pushButton_2, SIGNAL(clicked(bool)), MainWindow, SLOT(ViewOriginalImage()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Image Steganography", 0, QApplication::UnicodeUTF8));
        EnterCoverImage->setText(QApplication::translate("MainWindow", "Enter cover image", 0, QApplication::UnicodeUTF8));
        Browse1->setText(QApplication::translate("MainWindow", "Browse...", 0, QApplication::UnicodeUTF8));
        EnterSecretFile->setText(QApplication::translate("MainWindow", "Enter secret file", 0, QApplication::UnicodeUTF8));
        Browse2->setText(QApplication::translate("MainWindow", "Browse...", 0, QApplication::UnicodeUTF8));
        ViewImage->setText(QApplication::translate("MainWindow", "View image", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Encrypt using AES-128", 0, QApplication::UnicodeUTF8));
        EnterKey->setText(QApplication::translate("MainWindow", "Enter key", 0, QApplication::UnicodeUTF8));
        DoIt->setText(QApplication::translate("MainWindow", "Do It!!", 0, QApplication::UnicodeUTF8));
        Exit1->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "View stego image", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "View Orignal image", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(HideData), QApplication::translate("MainWindow", "Hide Data", 0, QApplication::UnicodeUTF8));
        EnterStegoImage->setText(QApplication::translate("MainWindow", "Enter stego image", 0, QApplication::UnicodeUTF8));
        Browse3->setText(QApplication::translate("MainWindow", "Browse...", 0, QApplication::UnicodeUTF8));
        ViewImage2->setText(QApplication::translate("MainWindow", "View image", 0, QApplication::UnicodeUTF8));
        Enterkey2->setText(QApplication::translate("MainWindow", "This data requires a key", 0, QApplication::UnicodeUTF8));
        DoIt2->setText(QApplication::translate("MainWindow", "Do It!!", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Enter key", 0, QApplication::UnicodeUTF8));
        Exit2->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(RecoverData), QApplication::translate("MainWindow", "Recover Data", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
