#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include <QTextStream>
//forward reference
void* updateTime(void*);
void* updateDate(void*);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
        //initialize the current time and date
        currentTime = QTime::currentTime();
        currentDate = QDate::currentDate();

        masterMenu = new Menu("MAIN MENU", {"New Session","Session Log","Time & Date"}, nullptr);
        mainMenu = masterMenu;
        initializeMainMenu(masterMenu);

        // Initialize the main menu view
        activeQListWidget = ui->mainMenuListView;
        activeQListWidget->addItems(masterMenu->getMenuItems());
        activeQListWidget->setCurrentRow(0);
        ui->menuLabel->setText(masterMenu->getName());

        powerStatus = false;
        changePowerStatus();
        connect(ui->downButton, &QPushButton::pressed, this, &MainWindow::navigateDownMenu);
        connect(ui->upButton, &QPushButton::pressed, this, &MainWindow::navigateUpMenu);
        connect(ui->okButton, &QPushButton::pressed, this, &MainWindow::navigateSubMenu);
        connect(ui->menuButton, &QPushButton::pressed, this, &MainWindow::navigateToMainMenu);
        connect(ui->powerButton, &QPushButton::released, this, &MainWindow::powerButtonHandler);
        connect(ui->timeEdit, &QTimeEdit::timeChanged, this, &MainWindow::setTime);
        pthread_t timeThread;
        pthread_create(&timeThread, nullptr, updateTime, &currentTime);
        connect(ui->dateEdit, &QDateEdit::dateChanged, this, &MainWindow::setDate);
        pthread_t dateThread;
        pthread_create(&dateThread, nullptr, updateDate, &currentDate);

        //visibility of main time and date widget and battery
        setVisibility(powerStatus);

        //Time and Date Widgets (use for updating time and date)
        ui->timeEdit->setVisible(false);
        ui->dateEdit->setVisible(false);


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeMainMenu(Menu * m){

    QStringList frequenciesList;
    QStringList programsList;
    // assume newsession and session log have no submenus
    Menu* newSession = new Menu("New Session", {}, m);
    Menu* sessionLog = new Menu("Session Log", {}, m);
    Menu* timeDate = new Menu("Time & Date", {"Change Time","Change Date"}, m); //maybe show time here?
    //newSession->addChildMenu(new Menu("Session Started",{},newSession));
    //sessionLog->addChildMenu(new Menu("Showing Logs",{},newSession));

    m->addChildMenu(newSession);
    m->addChildMenu(sessionLog);
    m->addChildMenu(timeDate);


    Menu* viewHistory = new Menu("Change Time",{"YES","NO"}, timeDate);
    Menu* clearHistory = new Menu("Change Date", {"YES","NO"}, timeDate);
    timeDate->addChildMenu(viewHistory);
    timeDate->addChildMenu(clearHistory);

    //initialize the timer for the device
    timer = new QTimer(this);
    timer->setInterval(60000); // every minute

    //initialize the timer for time
    timerForTime = new QTimer(this);
    connect(timerForTime, &QTimer::timeout, this, &MainWindow::displayCurrentDateAndTime);

}

void MainWindow::changePowerStatus(){
        activeQListWidget->setVisible(powerStatus);
        ui->menuLabel->setVisible(powerStatus);
        ui->statusBarQFrame->setVisible(powerStatus);
        ui->treatmentView->setVisible(powerStatus);
        ui->frequencyLabel->setVisible(powerStatus);
        ui->programViewWidget->setVisible(powerStatus);
        ui->upButton->setEnabled(powerStatus);
        ui->downButton->setEnabled(powerStatus);
        ui->menuButton->setEnabled(powerStatus);
        ui->okButton->setEnabled(powerStatus);
        ui->pauseButton->setEnabled(powerStatus);
        ui->playButton->setEnabled(powerStatus);
        ui->stopButton->setEnabled(powerStatus);
        if (powerStatus){
            navigateToMainMenu();
            //disconnect nodes
        }

}

void MainWindow::contactLedHandler(){
    ui->contactLed->setStyleSheet("background-color:  blue");

}

void MainWindow::treatmentLedHandler(){
    ui->treatmentLed->setStyleSheet("background-color:  green");

}
void MainWindow::lostLedHandler(){
    ui->lostLed->setStyleSheet("background-color:  red");

}

void MainWindow::navigateDownMenu(){
    int nextIndex = activeQListWidget->currentRow() + 1;

    if (nextIndex > activeQListWidget->count() - 1) {
        nextIndex = 0;
    }

    activeQListWidget->setCurrentRow(nextIndex);
}

void MainWindow::navigateUpMenu(){

    int nextIndex = activeQListWidget->currentRow() - 1;

    if (nextIndex < 0) {
        nextIndex = activeQListWidget->count() - 1;
    }

    activeQListWidget->setCurrentRow(nextIndex);
}

void MainWindow::navigateSubMenu(){
    //get menu pos
    int index = activeQListWidget->currentRow();
    // prevent crash
    if (index < 0) return;
    //change time
    if (masterMenu->getName() == "Change Time") {
        if (masterMenu->getMenuItems()[index] == "YES") {
            ui->timeEdit->setVisible(true);
            //goBack();
            return;
        }
        else {
            goBack();
            return;
        }
    }
    //change Date
    if (masterMenu->getName() == "Change Date") {
        if (masterMenu->getMenuItems()[index] == "YES") {
            ui->dateEdit->setVisible(true);
            //goBack();
            return;
        }
        else {
            goBack();
            return;
        }
    }
    // if it has submenus
    if (masterMenu->get(index)->getMenuItems().length() > 0) {
        masterMenu = masterMenu->get(index);
        MainWindow::updateMenu(masterMenu->getName(), masterMenu->getMenuItems());
    }
    //no submenus
    else if(masterMenu->get(index)->getMenuItems().length() == 0 && (masterMenu->getName() == "MAIN MENU")) {
        if (index ==0){
            updateMenu("New Session", {});
            qInfo("New Session Function Goes Here");
        }
        else if (index ==1){
            updateMenu("Logs", {});
            qInfo("Showing Logs function goes here");
        }
    }
}

void MainWindow::powerButtonHandler(){
    //can use this function for 0 battery aswell
    powerStatus = !powerStatus;
    changePowerStatus();
    setVisibility(powerStatus); //timeDate and battery widgets
    //check if power is on
    if (powerStatus){
        //start the timer
        connect(timer, SIGNAL(timeout()), this, SLOT(drainBattery()));
        timer->start();
        timerForTime->start(10000); //every minute
    }else{
        //stop timer as power is off
        timer->stop();
        //Time and Date Widgets (use for updating time and date)
        ui->timeEdit->setVisible(false);
        ui->dateEdit->setVisible(false);
    }

}

void MainWindow::updateMenu(const QString selectedMenuItem, const QStringList menuItems) {

    activeQListWidget->clear();
    activeQListWidget->addItems(menuItems);
    activeQListWidget->setCurrentRow(0);

    ui->menuLabel->setText(selectedMenuItem);
}

void MainWindow::navigateToMainMenu(){
    //check for ongoing therapy
    while (masterMenu->getName() != "MAIN MENU") {
        masterMenu = masterMenu->getParent();
    }

    updateMenu(masterMenu->getName(), masterMenu->getMenuItems());
    //Time and Date Widgets (use for updating time and date)
    ui->timeEdit->setVisible(false);
    ui->dateEdit->setVisible(false);
}
void MainWindow::goBack(){
    qInfo("go Back Called");
    masterMenu = masterMenu->getParent();
    updateMenu(masterMenu->getName(), masterMenu->getMenuItems());
    //Time and Date Widgets (use for updating time and date)
    ui->timeEdit->setVisible(false);
    ui->dateEdit->setVisible(false);
}

void MainWindow::drainBattery(){
    //check if device is on
    if (powerStatus){
        //Check for low battery
        if (ui->batteryLevelBar->value() < 20 && !lowBatteryMessage){
            qInfo("Low Battery");
            lowBatteryMessage = true; // display the message only once
        }
        //check if battery level is not 0
        if (ui->batteryLevelBar->value() != 0){
            //decrease by 1
            ui->batteryLevelBar->setValue(ui->batteryLevelBar->value() - 1);
        }else{
            //turn off the device
            qInfo("Power Off");
            powerStatus = false;
            changePowerStatus();
            timer->stop();
        }
    }
}

void MainWindow::setVisibility(bool powerStatus){
    //check if power is on to make it visible
    if (powerStatus){
        ui->dateTimeEdit->setVisible(true);
        ui->batteryLevelBar->setVisible(true);
    }else{
        ui->dateTimeEdit->setVisible(false);
        ui->batteryLevelBar->setVisible(false);
    }

}

void MainWindow::displayCurrentDateAndTime(){

    ui->dateTimeEdit->setTime(currentTime);
    ui->dateTimeEdit->setDate(currentDate);

}

void MainWindow::setTime(){

    currentTime = ui->timeEdit->time();
    ui->dateTimeEdit->setTime(currentTime);
}

void MainWindow::setDate(){

    currentDate = ui->dateEdit->date();
    ui->dateEdit->setDate(currentDate);
}

void* updateTime(void* arg){
    QTime* currentTime = reinterpret_cast<QTime*>(arg);
    while (true) {
        //qDebug() << "Updating timer...";
        sleep(60); // Sleep for 60 seconds
        *currentTime = currentTime->addSecs(60); // add 1 minute
        //qDebug() << "Current Time:" << currentTime->toString("hh:mm:ss");
    }
    return nullptr;

}

void* updateDate(void* arg){
    QDate* currentDate = reinterpret_cast<QDate*>(arg);
    while (true) {
        //qDebug() << "Updating date...";
        sleep(86400000); // Sleep for 1 day
        *currentDate = currentDate->addDays(1) ;// Increment by 1 day
        //qDebug() << "Current Date:" << currentDate->toString("yyyy/MM/dd");
    }
    return nullptr;

}




