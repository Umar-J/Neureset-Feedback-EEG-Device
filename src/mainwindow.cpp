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


        //fill(isConnected.begin(), isConnected.end(), false); //set electrode connection to false
        fill_n(isConnected, 21, false);

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


        for(int i = 0; i <= 20; i++) {
            QPushButton *button = findChild<QPushButton*>(QString("electrode_%1").arg(i));
            //can put connect here
            connect(button, &QPushButton::clicked, this, [this, i]() { applyElectrode(i); });
            if(button) {
                electrodes.append(button);
            }
        }

        //electrodes.at(0)->setStyleSheet("background-color:  red");
        //electrodes.at(20)->setStyleSheet("background-color:  red");

        //Creates all 21 EEG objects
        for(int i = 0; i < 21; i++){
            EEG* eeg = new EEG(i);
            eegList.append(eeg);
        }

        //initilizes currentSession to null
        currentSession = nullptr;

        connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::startSession);
        connect(ui->pauseButton, &QPushButton::clicked, this, &MainWindow::pauseSession);
        connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopSession);

}
MainWindow::~MainWindow()
{
    for(int i = 0; i < eegList.size(); i++){
        delete eegList[i];
    }

    delete ui;
}

void MainWindow::initializeMainMenu(Menu * m){

    QStringList frequenciesList;
    QStringList programsList;
    // assume newsession and session log have no submenus
    Menu* newSession = new Menu("New Session", {}, m);
    Menu* sessionLog = new Menu("Session Log", {"Upload To Pc","Preview Logs"}, m);
    Menu* timeDate = new Menu("Time & Date", {"Change Time","Change Date"}, m); //maybe show time here?
    //newSession->addChildMenu(new Menu("Session Started",{},newSession));
    //sessionLog->addChildMenu(new Menu("Showing Logs",{},newSession));

    m->addChildMenu(newSession);
    m->addChildMenu(sessionLog);
    m->addChildMenu(timeDate);

    Menu* uploadLogsMenu = new Menu("Upload To Pc", {"YES", "NO"}, sessionLog);
    Menu* previewLogs = new Menu("Preview Logs", {"YES", "NO"}, sessionLog);
    sessionLog->addChildMenu(uploadLogsMenu);
    sessionLog->addChildMenu(previewLogs);

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

bool MainWindow::electrodeConnectionCheck(){
    for (bool x: isConnected){
        if (x==false){
            qInfo("all nodes not connected");
            return false;
        }
    }
    qInfo("all nodes connected!!!!!!!!");
    return true;
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

    //uploading to Pc
    if (masterMenu->getName() == "Upload To Pc"){
        if (masterMenu->getMenuItems() [index] == "YES"){
            sendLogstoPC();
            return;
        }
        else {
            ui->textBrowser->clear();
            goBack();
            return;
        }
    }
    //preview logs
    if (masterMenu->getName() == "Preview Logs"){
        if (masterMenu->getMenuItems() [index] == "YES"){

            if(!sessionsLog.isEmpty()){

                QStringList sessionList;

                const int numSessions = sessionsLog.size();

                for (int i = 0; i < numSessions; ++i) {
                    //need to add time and date to this preview:
                    sessionList.append(QString("%1 ").arg(sessionsLog.at(i)->getName()));
                }

                activeQListWidget->clear();
                ui->menuLabel->setText("Preview Logs");
                activeQListWidget->addItems(sessionList);
                activeQListWidget->setCurrentRow(0);
                ui->menuLabel->setText("Preview Logs");

            }else{
                qInfo("Session logs is empty");
            }
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

            if(currentSession == nullptr){
                currentSession = startSession();
            }
            else{
                //display currentSession
            }

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

void MainWindow::applyElectrode(int i){
    isConnected[i] = !isConnected[i]; // flip on click
    if (isConnected[i]){
        electrodes.at(i)->setStyleSheet("	background-color: rgb(87, 227, 137); border-style: solid;border-color: black;border-width: 2px;border-radius: 8px;");
        qInfo("eeg at %d is connected", i);
        qInfo("%d", isConnected[i]);
        electrodeConnectionCheck();
    }else{
        electrodes.at(i)->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 white, stop: 1 grey);border-style: solid;border-color: black;border-width: 2px;border-radius: 8px;");
        qInfo("eeg at %d is disconected", i);
        qInfo("%d", isConnected[i]);

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

//uploading the logs to the pc
void MainWindow::sendLogstoPC(){


    if(!sessionsLog.isEmpty()){
        ui->textBrowser->setText("Printing out Session Logs:\n");

        for(int sessionIndex = 0; sessionIndex < sessionsLog.size(); sessionIndex++){

            //need to add time and date to this
            //ui->textBrowser->append(QString("%1 took place at %2 \n").arg(sessionsLog[sessionIndex]->getName()).arg(sessionsLog[sessionIndex]->getStartTime()));

            ui->textBrowser->append(QString("%1 Dominant Average Freqeuncies Before Treatment: \n").arg(sessionsLog[sessionIndex]->getName()));
            QVector<int> beforeAverages = sessionsLog[sessionIndex]->getStartAverages();
            for(int i = 0; i < beforeAverages.size(); i++){
                ui->textBrowser->append(QString("%1 ").arg(QString::number(beforeAverages[i])));
            }

            ui->textBrowser->append(QString("%1 Dominant Average Freqeuncies After Treatment: \n").arg(sessionsLog[sessionIndex]->getName()));
            QVector<int> endAverages = sessionsLog[sessionIndex]->getEndAverages();
            for(int k = 0; k < endAverages.size(); k++){
                ui->textBrowser->append(QString("%1 ").arg(QString::number(endAverages[k])));
            }

        }

    }else{
        ui->textBrowser->setText("No Sessions have taken place, Session logs is currently empty \n");
    }
}




Session* MainWindow::startSession(){
    //If all nodes connected and has atleast 10% battery
    //Idea Suggestion: Drain battery 10% each session?
    if(electrodeConnectionCheck() && ui->batteryLevelBar->value() >= 10){
        Session* session = new Session();

        session->startSession(eegList);

        return session;
    }

    return nullptr;
}

void MainWindow::playSession() {
    if(currentSession == nullptr){
        return;
    }

    currentSession->playSession();

}

void MainWindow::pauseSession() {
    if(currentSession == nullptr){
        return;
    }

    currentSession->pauseSession();
}

void MainWindow::stopSession() {
    if(currentSession == nullptr){
        return;
    }

    currentSession->stopSession();

    qInfo("Add Current Session to sessionsLog Here!");

}
