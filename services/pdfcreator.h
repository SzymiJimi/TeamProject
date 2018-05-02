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
    static void printInvoice(QString content);
};

#endif // PDFCREATOR_H
