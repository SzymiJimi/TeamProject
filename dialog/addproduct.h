#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QDialog>

#include <model/product.h>

namespace Ui {
class AddProduct;
}

class AddProduct : public QDialog
{
    Q_OBJECT

public:
    explicit AddProduct(QWidget *parent = 0);
    ~AddProduct();
    Product* getProductFromFrom();
    void setFormForEdit(Product product);

private slots:

private:
    Ui::AddProduct *ui;
};

#endif // ADDPRODUCT_H
