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

void PDFCreator::printInvoice(QString clientInfo, QString content, QString price)
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QString cont="	<center><h3>Faktura</h3></center>"
                    "<br>"
                    "<div id='shop' style='width: 50%; height: 200px ;float:left; text-align:left;'>"
            "<b>Dane Sprzedawcy:</b><br>"
            "Sklep<br>Kielce, ul. al. 1000-lecia PP 7<br>25-314 Kielce<br>NIP:111-11-11-111<br>Telefon: 41 333-33-33"
            "</div>"


            "<div id='client' style='width: 50%; height: 200px ;float:left; text-align: right;'>"
            "<b>Dane Klienta:</b><br>" + clientInfo +
            "</div>"
            "<br><br>"
            "<table BORDER = '1' style='width:100%'>"
          "<tr><th>L.p.</th><th>ID towaru</th><th>Nazwa towaru</th><th>JM</th><th>Cena netto</th><th>Stawka VAT</th><th>Cena brutto</th><th>Ilość</th><th>Łącznie netto</th><th>Łącznie brutto</th></tr>"
        +content + "<td>" +
         price +"PLN"
         "</td>"
          "</tr>"
        "</table>";
    QTextDocument doc;


    doc.setHtml(cont);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}

QString PDFCreator::prepareListOfProducts(int idSale)
{
    Sale sale=Sale::findSaleById(idSale);
    idSale=sale.getId();
    std::list<ProductSales> concreteSales=ProductSales::findProductSalesBySaleId(idSale);

    std::list<ProductSales>::iterator it=concreteSales.begin();

    QString content="";
    QString idQString;
    QString numberOfProduct;
    QString quantityString;
    int counter=1;
    float addNetto=0;
    Product product;
    for (; it != concreteSales.end(); it++){
        product=product.findProductById(it->getProductId());
        idQString = QString::number(product.getId());
        numberOfProduct = QString::number(counter);
        quantityString = QString::number(it->roundQuantityTo2DecimalPlaces());

        content+="<tr><td>"+numberOfProduct+"</td>"
                "<td>"+idQString+"</td>"
                "<td>"+product.getName()+"</td>"
                "<td>"+product.getUnit()+"</td>"
                "<td>"+QString::number(product.getNettoPrice(), 'f', 2)+" PLN</td>"
                "<td>"+product.getVAT()+"</td>"
                "<td>"+QString::number(product.getPrice(), 'f', 2) + " PLN</td>"
                "<td>"+quantityString+"</td>"
                "<td>"+QString::number(product.getNettoPrice()*it->getQuantity(), 'f', 2) +" PLN</td>"
                "<td>"+QString::number(product.getPrice()*it->getQuantity(), 'f',2)+" PLN</td></tr>";
        counter++;
        addNetto+=product.getNettoPrice()*it->getQuantity();

    }
    content+="</table>"
             "<br><br>"
             "<table BORDER = '1' style='width:20%; float:right'>"
               "<tr><th>Razem brutto</th><th>Razem netto</th></tr>"
               "<tr>"
                 "<td>" + QString::number(addNetto, 'f', 2) +" PLN</td>";
    return content;
}