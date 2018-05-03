#ifndef PDFCREATOR_H
#define PDFCREATOR_H
#include <QtWidgets>
#include <QPrinter>
#include <model/sale.h>
#include <model/productsales.h>


class PDFCreator
{
public:
    PDFCreator();
    static void printReceipt(QString content);
    static void printInvoice(QString clientInfo, QString content, QString price);
    static QString prepareListOfProducts(int saleId);
};

#endif // PDFCREATOR_H
