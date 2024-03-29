#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "Session.h"
#include "menu.h"
#include "EEG.h"
#include <QListWidget>
#include <QPushButton>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
// this class will act as the control class of the application
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //vector<bool> isConnected;
    bool isConnected [21];
    QVector<QPushButton*> electrodes;
    Menu* masterMenu;
    Menu* mainMenu;
    void initializeMainMenu(Menu*);
    QVector<Session*> sessionsLog;
    QVector<EEG*> eegList;
    QListWidget *activeQListWidget;
    void changePowerStatus();
    bool powerStatus;
    void contactLedHandler();
    void treatmentLedHandler();
    void lostLedHandler();
    bool electrodeConnectionCheck();

// *** TODO: Implement these before un-commenting
//    bool checkAverageBaseline();
//    void sendLogstoPC();
//    void setDateTime();
//    bool checkConnection(QVector<EEG*>);
//    int calculateAverageBaseline();
//    void shutdown();
//    void deliverTreatment();
//    void handleContactLoss();
//    void drainBattery();
    void updateMenu(const QString selectedMenuItem, const QStringList menuItems);
    void navigateToMainMenu();
    void goBack();

private slots:
//    void pauseSession();
//    void stopSession();
//    void continueSession();
    void navigateDownMenu();
    void navigateUpMenu();
    void navigateSubMenu();
    void powerButtonHandler();
    void applyElectrode(int);
//    void applyEEG(int);

};
#endif // MAINWINDOW_H
