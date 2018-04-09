#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"\


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

private:
    Ui::MainWindow *ui;

public:
    void addClientToTable(Client* client);
};



#endif // MAINWINDOW_H
