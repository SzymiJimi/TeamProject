#include "pdfcreator.h"

PDFCreator::PDFCreator()
{

}

void PDFCreator::printReceipt(QString content)
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QDateTime time = QDateTime::currentDateTime ();
    QString dateString = time.toString("yyyy-MM-dd  HH:mm");
    QTextDocument doc;
    QString line = "<br>- - - - - - - - - - - - - - - - - - - - - - -<br>";
    QString text = "Sklep<br>Kielce, ul. al. 1000-lecia PP 7<br>25-314 Kielce<br>"
                     "NIP:111-11-11-111"+line+dateString+line+"<b>PARAGON FISKALNY</b>"+
                      line+content+line+"Zapraszamy ponownie!";


    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);

}

void PDFCreator::printInvoice(QString content)
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;


    doc.setHtml(content);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}
