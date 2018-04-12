#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "dialog/addclient.h"
#include "model/client.h"
#include <QDebug>
#include "services/savefile.h"
#include <list>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_pushButton_clicked();

    void on_label_linkActivated(const QString &link);

    void on_pushButton_2_clicked();

    void on_showClientsButton_clicked();

    void on_addClientButton_clicked();

    void addClientsFromFileToTable();

private:
    std::list<Client> clients;
    Ui::MainWindow *ui;

public:
    void addClientToTable(Client* client);
};



#endif // MAINWINDOW_H
