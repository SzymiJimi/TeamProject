#ifndef PRODUCTTOSALEDIALOG_H
#define PRODUCTTOSALEDIALOG_H

#include <QDialog>
#include <model/product.h>

namespace Ui {
class ProductToSaleDialog;
}

class ProductToSaleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProductToSaleDialog(QWidget *parent = 0);
    void addProductsToTable();
    int getSelectedRow();
    QString getIdQStringFromTable(int row);
    ~ProductToSaleDialog();

private:
    Ui::ProductToSaleDialog *ui;
};

#endif // PRODUCTTOSALEDIALOG_H
