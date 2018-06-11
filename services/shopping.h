#ifndef SHOPPING_H
#define SHOPPING_H
#include <QTableWidget>
#include <mainwindow.h>

class Shopping
{
public:
    Shopping();
    void buyProducts( Ui::MainWindow * window);
    static bool checkQuantityWithListOfProducts(Ui::MainWindow * window, int productId, double amount);
};

#endif // SHOPPING_H
