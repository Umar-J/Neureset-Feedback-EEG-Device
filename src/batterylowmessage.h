#ifndef BATTERYLOWMESSAGE_H
#define BATTERYLOWMESSAGE_H

#include <QDialog>

namespace Ui {
class BatteryLowMessage;
}

class BatteryLowMessage : public QDialog
{
    Q_OBJECT

public:
    explicit BatteryLowMessage(QWidget *parent = nullptr);
    ~BatteryLowMessage();

private:
    Ui::BatteryLowMessage *ui;
};

#endif // BATTERYLOWMESSAGE_H
