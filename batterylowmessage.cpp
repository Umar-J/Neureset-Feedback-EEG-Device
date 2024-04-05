#include "batterylowmessage.h"
#include "ui_batterylowmessage.h"

BatteryLowMessage::BatteryLowMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BatteryLowMessage)
{
    ui->setupUi(this);
}

BatteryLowMessage::~BatteryLowMessage()
{
    delete ui;
}
