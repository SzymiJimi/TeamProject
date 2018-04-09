#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>
#include "qabstractbutton.h"
#include "client.h"

namespace Ui {
class AddClient;
}

class AddClient : public QDialog
{
    Q_OBJECT

public:
    explicit AddClient(QWidget *parent = 0);
    Client* getValues();
    ~AddClient();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::AddClient *ui;
};

#endif // ADDCLIENT_H
