/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *denasWidget;
    QListWidget *mainMenuListView;
    QLabel *menuLabel;
    QWidget *programViewWidget;
    QGraphicsView *treatmentView;
    QLabel *powerLevelLabel;
    QLabel *frequencyLabel;
    QFrame *statusBarQFrame;
    QLabel *electrodeLabel;
    QGraphicsView *powerOffView;
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *okButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *powerButton;
    QPushButton *menuButton;
    QProgressBar *batteryLevelBar;
    QPushButton *stopButton;
    QPushButton *applyToSkinButton;
    QTextBrowser *textBrowser;
    QPushButton *applyToSkinButton_4;
    QPushButton *applyToSkinButton_5;
    QPushButton *applyToSkinButton_6;
    QPushButton *applyToSkinButton_7;
    QPushButton *applyToSkinButton_8;
    QPushButton *applyToSkinButton_9;
    QPushButton *applyToSkinButton_10;
    QPushButton *applyToSkinButton_11;
    QPushButton *applyToSkinButton_12;
    QPushButton *applyToSkinButton_13;
    QPushButton *applyToSkinButton_14;
    QPushButton *applyToSkinButton_15;
    QPushButton *applyToSkinButton_16;
    QPushButton *applyToSkinButton_17;
    QPushButton *applyToSkinButton_18;
    QPushButton *applyToSkinButton_19;
    QPushButton *applyToSkinButton_20;
    QPushButton *applyToSkinButton_21;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(958, 600);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        denasWidget = new QWidget(centralwidget);
        denasWidget->setObjectName(QString::fromUtf8("denasWidget"));
        denasWidget->setGeometry(QRect(20, 110, 311, 331));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(denasWidget->sizePolicy().hasHeightForWidth());
        denasWidget->setSizePolicy(sizePolicy);
        denasWidget->setLayoutDirection(Qt::LeftToRight);
        denasWidget->setAutoFillBackground(false);
        denasWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        mainMenuListView = new QListWidget(denasWidget);
        mainMenuListView->setObjectName(QString::fromUtf8("mainMenuListView"));
        mainMenuListView->setGeometry(QRect(24, 102, 138, 102));
        mainMenuListView->setStyleSheet(QString::fromUtf8("border-bottom-right-radius: 12px;\n"
"border-bottom-left-radius: 12px;\n"
"background-color: rgb(243, 243, 243);\n"
"color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(122, 0, 0)"));
        mainMenuListView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mainMenuListView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mainMenuListView->setUniformItemSizes(false);
        mainMenuListView->setWordWrap(true);
        mainMenuListView->setSelectionRectVisible(false);
        menuLabel = new QLabel(denasWidget);
        menuLabel->setObjectName(QString::fromUtf8("menuLabel"));
        menuLabel->setGeometry(QRect(24, 90, 138, 12));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        menuLabel->setFont(font);
        menuLabel->setLayoutDirection(Qt::LeftToRight);
        menuLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 101, 164);\n"
"color: rgb(255, 255, 255);"));
        menuLabel->setScaledContents(false);
        menuLabel->setAlignment(Qt::AlignCenter);
        programViewWidget = new QWidget(denasWidget);
        programViewWidget->setObjectName(QString::fromUtf8("programViewWidget"));
        programViewWidget->setGeometry(QRect(24, 102, 138, 102));
        programViewWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 101, 164);\n"
"color: rgb(255, 255, 255);"));
        treatmentView = new QGraphicsView(programViewWidget);
        treatmentView->setObjectName(QString::fromUtf8("treatmentView"));
        treatmentView->setGeometry(QRect(0, 0, 138, 90));
        QFont font1;
        font1.setPointSize(10);
        treatmentView->setFont(font1);
        treatmentView->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        powerLevelLabel = new QLabel(programViewWidget);
        powerLevelLabel->setObjectName(QString::fromUtf8("powerLevelLabel"));
        powerLevelLabel->setGeometry(QRect(0, 90, 83, 12));
        QFont font2;
        font2.setPointSize(8);
        powerLevelLabel->setFont(font2);
        powerLevelLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 101, 164);\n"
"color: rgb(255, 255, 255);"));
        powerLevelLabel->setIndent(6);
        frequencyLabel = new QLabel(programViewWidget);
        frequencyLabel->setObjectName(QString::fromUtf8("frequencyLabel"));
        frequencyLabel->setEnabled(true);
        frequencyLabel->setGeometry(QRect(83, 90, 55, 12));
        frequencyLabel->setFont(font2);
        frequencyLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 101, 164);\n"
"color: rgb(255, 255, 255);"));
        frequencyLabel->setScaledContents(false);
        frequencyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frequencyLabel->setIndent(6);
        statusBarQFrame = new QFrame(denasWidget);
        statusBarQFrame->setObjectName(QString::fromUtf8("statusBarQFrame"));
        statusBarQFrame->setGeometry(QRect(24, 78, 138, 12));
        statusBarQFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        statusBarQFrame->setFrameShape(QFrame::StyledPanel);
        statusBarQFrame->setFrameShadow(QFrame::Raised);
        electrodeLabel = new QLabel(statusBarQFrame);
        electrodeLabel->setObjectName(QString::fromUtf8("electrodeLabel"));
        electrodeLabel->setGeometry(QRect(6, 1, 8, 10));
        electrodeLabel->setStyleSheet(QString::fromUtf8(""));
        electrodeLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/electrodeOff.svg")));
        electrodeLabel->setScaledContents(true);
        powerOffView = new QGraphicsView(denasWidget);
        powerOffView->setObjectName(QString::fromUtf8("powerOffView"));
        powerOffView->setGeometry(QRect(24, 78, 138, 126));
        powerOffView->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        upButton = new QPushButton(denasWidget);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setGeometry(QRect(180, 80, 40, 40));
        upButton->setMinimumSize(QSize(40, 40));
        upButton->setMaximumSize(QSize(40, 40));
        upButton->setBaseSize(QSize(40, 40));
        upButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/upButton.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        upButton->setAutoRepeat(true);
        upButton->setAutoRepeatDelay(600);
        upButton->setAutoRepeatInterval(200);
        downButton = new QPushButton(denasWidget);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        downButton->setGeometry(QRect(180, 180, 40, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(40);
        sizePolicy1.setVerticalStretch(40);
        sizePolicy1.setHeightForWidth(downButton->sizePolicy().hasHeightForWidth());
        downButton->setSizePolicy(sizePolicy1);
        downButton->setMinimumSize(QSize(40, 40));
        downButton->setMaximumSize(QSize(40, 40));
        downButton->setBaseSize(QSize(40, 40));
        downButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/downButton.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        downButton->setAutoRepeat(true);
        downButton->setAutoRepeatDelay(600);
        downButton->setAutoRepeatInterval(200);
        okButton = new QPushButton(denasWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setEnabled(true);
        okButton->setGeometry(QRect(180, 130, 40, 40));
        okButton->setMinimumSize(QSize(40, 40));
        okButton->setMaximumSize(QSize(40, 40));
        okButton->setBaseSize(QSize(40, 40));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/okButton.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        playButton = new QPushButton(denasWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(30, 220, 40, 40));
        playButton->setMinimumSize(QSize(40, 40));
        playButton->setMaximumSize(QSize(40, 40));
        playButton->setBaseSize(QSize(40, 40));
        playButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/playButton.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        playButton->setCheckable(false);
        playButton->setAutoRepeat(true);
        playButton->setAutoRepeatDelay(600);
        playButton->setAutoRepeatInterval(150);
        pauseButton = new QPushButton(denasWidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setGeometry(QRect(80, 220, 40, 40));
        pauseButton->setMinimumSize(QSize(40, 40));
        pauseButton->setMaximumSize(QSize(40, 40));
        pauseButton->setBaseSize(QSize(40, 40));
        pauseButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/pauseButton.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        pauseButton->setAutoRepeat(true);
        pauseButton->setAutoRepeatDelay(600);
        pauseButton->setAutoRepeatInterval(150);
        powerButton = new QPushButton(denasWidget);
        powerButton->setObjectName(QString::fromUtf8("powerButton"));
        powerButton->setGeometry(QRect(260, 10, 40, 40));
        powerButton->setMinimumSize(QSize(40, 40));
        powerButton->setMaximumSize(QSize(40, 40));
        powerButton->setBaseSize(QSize(40, 40));
        powerButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/powerButton.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        menuButton = new QPushButton(denasWidget);
        menuButton->setObjectName(QString::fromUtf8("menuButton"));
        menuButton->setGeometry(QRect(20, 30, 40, 40));
        menuButton->setMinimumSize(QSize(40, 40));
        menuButton->setMaximumSize(QSize(40, 40));
        menuButton->setBaseSize(QSize(40, 40));
        menuButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/menuButton.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        batteryLevelBar = new QProgressBar(denasWidget);
        batteryLevelBar->setObjectName(QString::fromUtf8("batteryLevelBar"));
        batteryLevelBar->setGeometry(QRect(230, 290, 71, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font3.setPointSize(7);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        font3.setKerning(true);
        batteryLevelBar->setFont(font3);
        batteryLevelBar->setAutoFillBackground(false);
        batteryLevelBar->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(164, 0, 0);\n"
"background-color: rgb(0, 0, 0);"));
        batteryLevelBar->setMinimum(0);
        batteryLevelBar->setValue(79);
        batteryLevelBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        batteryLevelBar->setTextVisible(true);
        batteryLevelBar->setOrientation(Qt::Horizontal);
        batteryLevelBar->setInvertedAppearance(false);
        stopButton = new QPushButton(denasWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(130, 220, 40, 40));
        stopButton->setMinimumSize(QSize(40, 40));
        stopButton->setMaximumSize(QSize(40, 40));
        stopButton->setBaseSize(QSize(40, 40));
        stopButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/buttons/stopButton.svg);\n"
"background-color: #ffffff;\n"
"border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        powerOffView->raise();
        statusBarQFrame->raise();
        menuLabel->raise();
        mainMenuListView->raise();
        programViewWidget->raise();
        upButton->raise();
        downButton->raise();
        okButton->raise();
        playButton->raise();
        pauseButton->raise();
        powerButton->raise();
        menuButton->raise();
        batteryLevelBar->raise();
        stopButton->raise();
        applyToSkinButton = new QPushButton(centralwidget);
        applyToSkinButton->setObjectName(QString::fromUtf8("applyToSkinButton"));
        applyToSkinButton->setGeometry(QRect(790, 110, 41, 31));
        applyToSkinButton->setAutoFillBackground(false);
        applyToSkinButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton->setCheckable(true);
        applyToSkinButton->setFlat(false);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(360, 110, 351, 331));
        applyToSkinButton_4 = new QPushButton(centralwidget);
        applyToSkinButton_4->setObjectName(QString::fromUtf8("applyToSkinButton_4"));
        applyToSkinButton_4->setGeometry(QRect(790, 190, 41, 31));
        applyToSkinButton_4->setAutoFillBackground(false);
        applyToSkinButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_4->setCheckable(true);
        applyToSkinButton_4->setFlat(false);
        applyToSkinButton_5 = new QPushButton(centralwidget);
        applyToSkinButton_5->setObjectName(QString::fromUtf8("applyToSkinButton_5"));
        applyToSkinButton_5->setGeometry(QRect(790, 150, 41, 31));
        applyToSkinButton_5->setAutoFillBackground(false);
        applyToSkinButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_5->setCheckable(true);
        applyToSkinButton_5->setFlat(false);
        applyToSkinButton_6 = new QPushButton(centralwidget);
        applyToSkinButton_6->setObjectName(QString::fromUtf8("applyToSkinButton_6"));
        applyToSkinButton_6->setGeometry(QRect(790, 230, 41, 31));
        applyToSkinButton_6->setAutoFillBackground(false);
        applyToSkinButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_6->setCheckable(true);
        applyToSkinButton_6->setFlat(false);
        applyToSkinButton_7 = new QPushButton(centralwidget);
        applyToSkinButton_7->setObjectName(QString::fromUtf8("applyToSkinButton_7"));
        applyToSkinButton_7->setGeometry(QRect(790, 270, 41, 31));
        applyToSkinButton_7->setAutoFillBackground(false);
        applyToSkinButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_7->setCheckable(true);
        applyToSkinButton_7->setFlat(false);
        applyToSkinButton_8 = new QPushButton(centralwidget);
        applyToSkinButton_8->setObjectName(QString::fromUtf8("applyToSkinButton_8"));
        applyToSkinButton_8->setGeometry(QRect(850, 160, 41, 31));
        applyToSkinButton_8->setAutoFillBackground(false);
        applyToSkinButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_8->setCheckable(true);
        applyToSkinButton_8->setFlat(false);
        applyToSkinButton_9 = new QPushButton(centralwidget);
        applyToSkinButton_9->setObjectName(QString::fromUtf8("applyToSkinButton_9"));
        applyToSkinButton_9->setGeometry(QRect(850, 120, 41, 31));
        applyToSkinButton_9->setAutoFillBackground(false);
        applyToSkinButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_9->setCheckable(true);
        applyToSkinButton_9->setFlat(false);
        applyToSkinButton_10 = new QPushButton(centralwidget);
        applyToSkinButton_10->setObjectName(QString::fromUtf8("applyToSkinButton_10"));
        applyToSkinButton_10->setGeometry(QRect(850, 200, 41, 31));
        applyToSkinButton_10->setAutoFillBackground(false);
        applyToSkinButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_10->setCheckable(true);
        applyToSkinButton_10->setFlat(false);
        applyToSkinButton_11 = new QPushButton(centralwidget);
        applyToSkinButton_11->setObjectName(QString::fromUtf8("applyToSkinButton_11"));
        applyToSkinButton_11->setGeometry(QRect(850, 280, 41, 31));
        applyToSkinButton_11->setAutoFillBackground(false);
        applyToSkinButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_11->setCheckable(true);
        applyToSkinButton_11->setFlat(false);
        applyToSkinButton_12 = new QPushButton(centralwidget);
        applyToSkinButton_12->setObjectName(QString::fromUtf8("applyToSkinButton_12"));
        applyToSkinButton_12->setGeometry(QRect(850, 240, 41, 31));
        applyToSkinButton_12->setAutoFillBackground(false);
        applyToSkinButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_12->setCheckable(true);
        applyToSkinButton_12->setFlat(false);
        applyToSkinButton_13 = new QPushButton(centralwidget);
        applyToSkinButton_13->setObjectName(QString::fromUtf8("applyToSkinButton_13"));
        applyToSkinButton_13->setGeometry(QRect(790, 310, 41, 31));
        applyToSkinButton_13->setAutoFillBackground(false);
        applyToSkinButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_13->setCheckable(true);
        applyToSkinButton_13->setFlat(false);
        applyToSkinButton_14 = new QPushButton(centralwidget);
        applyToSkinButton_14->setObjectName(QString::fromUtf8("applyToSkinButton_14"));
        applyToSkinButton_14->setGeometry(QRect(790, 360, 41, 31));
        applyToSkinButton_14->setAutoFillBackground(false);
        applyToSkinButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_14->setCheckable(true);
        applyToSkinButton_14->setFlat(false);
        applyToSkinButton_15 = new QPushButton(centralwidget);
        applyToSkinButton_15->setObjectName(QString::fromUtf8("applyToSkinButton_15"));
        applyToSkinButton_15->setGeometry(QRect(790, 410, 41, 31));
        applyToSkinButton_15->setAutoFillBackground(false);
        applyToSkinButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_15->setCheckable(true);
        applyToSkinButton_15->setFlat(false);
        applyToSkinButton_16 = new QPushButton(centralwidget);
        applyToSkinButton_16->setObjectName(QString::fromUtf8("applyToSkinButton_16"));
        applyToSkinButton_16->setGeometry(QRect(850, 320, 41, 31));
        applyToSkinButton_16->setAutoFillBackground(false);
        applyToSkinButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_16->setCheckable(true);
        applyToSkinButton_16->setFlat(false);
        applyToSkinButton_17 = new QPushButton(centralwidget);
        applyToSkinButton_17->setObjectName(QString::fromUtf8("applyToSkinButton_17"));
        applyToSkinButton_17->setGeometry(QRect(850, 360, 41, 31));
        applyToSkinButton_17->setAutoFillBackground(false);
        applyToSkinButton_17->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_17->setCheckable(true);
        applyToSkinButton_17->setFlat(false);
        applyToSkinButton_18 = new QPushButton(centralwidget);
        applyToSkinButton_18->setObjectName(QString::fromUtf8("applyToSkinButton_18"));
        applyToSkinButton_18->setGeometry(QRect(900, 220, 41, 31));
        applyToSkinButton_18->setAutoFillBackground(false);
        applyToSkinButton_18->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_18->setCheckable(true);
        applyToSkinButton_18->setFlat(false);
        applyToSkinButton_19 = new QPushButton(centralwidget);
        applyToSkinButton_19->setObjectName(QString::fromUtf8("applyToSkinButton_19"));
        applyToSkinButton_19->setGeometry(QRect(900, 170, 41, 31));
        applyToSkinButton_19->setAutoFillBackground(false);
        applyToSkinButton_19->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_19->setCheckable(true);
        applyToSkinButton_19->setFlat(false);
        applyToSkinButton_20 = new QPushButton(centralwidget);
        applyToSkinButton_20->setObjectName(QString::fromUtf8("applyToSkinButton_20"));
        applyToSkinButton_20->setGeometry(QRect(900, 270, 41, 31));
        applyToSkinButton_20->setAutoFillBackground(false);
        applyToSkinButton_20->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_20->setCheckable(true);
        applyToSkinButton_20->setFlat(false);
        applyToSkinButton_21 = new QPushButton(centralwidget);
        applyToSkinButton_21->setObjectName(QString::fromUtf8("applyToSkinButton_21"));
        applyToSkinButton_21->setGeometry(QRect(900, 310, 41, 31));
        applyToSkinButton_21->setAutoFillBackground(false);
        applyToSkinButton_21->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #ffd300;\n"
"}"));
        applyToSkinButton_21->setCheckable(true);
        applyToSkinButton_21->setFlat(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 80, 62, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 958, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        mainMenuListView->setCurrentRow(-1);
        applyToSkinButton->setDefault(true);
        applyToSkinButton_4->setDefault(true);
        applyToSkinButton_5->setDefault(true);
        applyToSkinButton_6->setDefault(true);
        applyToSkinButton_7->setDefault(true);
        applyToSkinButton_8->setDefault(true);
        applyToSkinButton_9->setDefault(true);
        applyToSkinButton_10->setDefault(true);
        applyToSkinButton_11->setDefault(true);
        applyToSkinButton_12->setDefault(true);
        applyToSkinButton_13->setDefault(true);
        applyToSkinButton_14->setDefault(true);
        applyToSkinButton_15->setDefault(true);
        applyToSkinButton_16->setDefault(true);
        applyToSkinButton_17->setDefault(true);
        applyToSkinButton_18->setDefault(true);
        applyToSkinButton_19->setDefault(true);
        applyToSkinButton_20->setDefault(true);
        applyToSkinButton_21->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        menuLabel->setText(QCoreApplication::translate("MainWindow", "MAIN MENU", nullptr));
        powerLevelLabel->setText(QString());
        frequencyLabel->setText(QString());
        electrodeLabel->setText(QString());
        upButton->setText(QString());
        downButton->setText(QString());
        okButton->setText(QString());
        playButton->setText(QString());
        pauseButton->setText(QString());
        powerButton->setText(QString());
        menuButton->setText(QString());
        batteryLevelBar->setFormat(QCoreApplication::translate("MainWindow", "%p%", nullptr));
        stopButton->setText(QString());
        applyToSkinButton->setText(QString());
        applyToSkinButton_4->setText(QString());
        applyToSkinButton_5->setText(QString());
        applyToSkinButton_6->setText(QString());
        applyToSkinButton_7->setText(QString());
        applyToSkinButton_8->setText(QString());
        applyToSkinButton_9->setText(QString());
        applyToSkinButton_10->setText(QString());
        applyToSkinButton_11->setText(QString());
        applyToSkinButton_12->setText(QString());
        applyToSkinButton_13->setText(QString());
        applyToSkinButton_14->setText(QString());
        applyToSkinButton_15->setText(QString());
        applyToSkinButton_16->setText(QString());
        applyToSkinButton_17->setText(QString());
        applyToSkinButton_18->setText(QString());
        applyToSkinButton_19->setText(QString());
        applyToSkinButton_20->setText(QString());
        applyToSkinButton_21->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "PC:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
