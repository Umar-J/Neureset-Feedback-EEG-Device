#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    powerStatus = true;
    ui->setupUi(this);
    masterMenu = new Menu("MAIN MENU", {"New Session","Session Log","Time & Date"}, nullptr);
        mainMenu = masterMenu;
        initializeMainMenu(masterMenu);

        // Initialize the main menu view
        activeQListWidget = ui->mainMenuListView;
        activeQListWidget->addItems(masterMenu->getMenuItems());
        activeQListWidget->setCurrentRow(0);
        ui->menuLabel->setText(masterMenu->getName());
        changePowerStatus();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeMainMenu(Menu * m){

    QStringList frequenciesList;
    QStringList programsList;

    Menu* newSession = new Menu("New Session", {}, m);
    Menu* sessionLog = new Menu("Session Log", {}, m);
    Menu* timeDate = new Menu("Time & Date", {"Change Time","Change Date"}, m); //maybe show time here?

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
}

