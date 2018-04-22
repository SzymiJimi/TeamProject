#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include "model/product.h"

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = 0);
    Product findProductById();
    int getProductId();
    ~FindDialog();

private slots:
    void on_findButton_clicked();


private:
    Ui::FindDialog *ui;
};

#endif // FINDDIALOG_H
