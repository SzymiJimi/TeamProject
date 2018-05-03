#ifndef INVOICEDIALOG_H
#define INVOICEDIALOG_H

#include <QDialog>
#include "model/client.h"
#include "services/savefile.h"

namespace Ui {
class InvoiceDialog;
}

class InvoiceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InvoiceDialog(QWidget *parent = 0);
    void addClientsFromFileToTable();
    int getSelectedRow();
    int getIdFromTable(int row);
    ~InvoiceDialog();

private:
    Ui::InvoiceDialog *ui;
};

#endif // INVOICEDIALOG_H
