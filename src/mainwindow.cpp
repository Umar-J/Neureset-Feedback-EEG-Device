#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
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
            return false;
        }
    }
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
            qInfo("change time function goes here");
            goBack();
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
            qInfo("change Date function goes here");
            goBack();
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

}

void MainWindow::applyElectrode(int i){
    isConnected[i] = !isConnected[i]; // flip on click
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
}
void MainWindow::goBack(){
    qInfo("go Back Called");
    masterMenu = masterMenu->getParent();
    updateMenu(masterMenu->getName(), masterMenu->getMenuItems());
}

