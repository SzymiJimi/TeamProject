#include "savefile.h"
#include "model/client.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>
#include <QFileInfo>
#include <list>
#include <QTextCodec>

SaveFile::SaveFile(QObject *parent) : QObject(parent)
{

}


std::list<Client> SaveFile::loadClientsFromFile()
{
    QFileInfo check_file("G://clients.txt");
    if(check_file.exists()&&check_file.isFile())
    {
        qDebug()<<"File exist...";
    }else
    {
        qDebug()<<"File not exist...";
    }

     QFile in("G://clients.txt");
     in.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream inFile(&in);
     inFile.setCodec(QTextCodec::codecForName("UTF-8"));

     std::list<Client> clients;
     Client client;

     while(!inFile.atEnd())
     {
         int position;
         QString id=inFile.readLine();
         position=id.lastIndexOf(QChar('\n'));
         id=id.left(position);

         QString name=inFile.readLine();
         position=name.lastIndexOf(QChar('\n'));
         name=name.left(position);

         QString surname=inFile.readLine();
         position=surname.lastIndexOf(QChar('\n'));
         surname=surname.left(position);

         QString pesel=inFile.readLine();
         position=pesel.lastIndexOf(QChar('\n'));
         pesel=pesel.left(position);

         QString nip=inFile.readLine();
         position=nip.lastIndexOf(QChar('\n'));
         nip=nip.left(position);

         QString street=inFile.readLine();
         position=street.lastIndexOf(QChar('\n'));
         street=street.left(position);

         QString houseNr=inFile.readLine();
         position=houseNr.lastIndexOf(QChar('\n'));
         houseNr=houseNr.left(position);

         QString postalCode=inFile.readLine();
         position=postalCode.lastIndexOf(QChar('\n'));
         postalCode=postalCode.left(position);

         QString city=inFile.readLine();
         position=city.lastIndexOf(QChar('\n'));

         if(!(position==-1&&city.size()>0)){
            city=city.left(position);
         }

         client.setId(id.toInt());
         client.setName(name);
         client.setSurname(surname);
         client.setPesel(pesel);
         client.setNip(nip);
         client.setStreet(street);
         client.setHouseNr(houseNr);
         client.setPostalCode(postalCode);
         client.setCity(city);
         clients.push_back(client);
     }
     in.close();
     return clients;
}

void SaveFile::saveClientsToFile(std::list<Client> clients){
    QFile caFile("G://clients.txt");
    caFile.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!caFile.isOpen()){
        qDebug() << "- Error, unable to open" << "outputFilename" << "for output";
    }
    QTextStream outStream(&caFile);
    std::list<Client>::iterator i;
    for(i=clients.begin(); i!=clients.end();i++){
        outStream <<QString::number(i->getId()).toUtf8()<<endl;
        outStream <<i->getName().toUtf8()<<endl;
        outStream <<i->getSurname().toUtf8()<<endl;
        outStream <<i->getPesel().toUtf8()<<endl;
        outStream <<i->getNip().toUtf8()<<endl;
        outStream <<i->getStreet().toUtf8()<<endl;
        outStream <<i->getHouseNr().toUtf8()<<endl;
        outStream <<i->getPostalCode().toUtf8()<<endl;
        outStream <<i->getCity().toUtf8()<<endl;
    }

    caFile.close();
}


void SaveFile::saveToFile(){
////    Client* client = new Client();



//    QFile inFile("G://input.txt");



//    qDebug()<<"1";
//        inFile.open(QIODevice::ReadOnly | QIODevice::Text);
//        while(!inFile.atEnd())
//        {
//            QString line = inFile.readLine();
//            qDebug()<<line;
//        }

//        QByteArray inputData="ciiiiiiiiiiiiiiiiiiiiiiiiiii";
////                = inFile.readAll();
////        qDebug()<<inputData;
//        QFile caFile("G://output.txt");
//        caFile.open(QIODevice::WriteOnly | QIODevice::Text);

//        if(!caFile.isOpen()){
//            qDebug() << "- Error, unable to open" << "outputFilename" << "for output";
//        }
//        QTextStream outStream(&caFile);
//        outStream << inputData;
//        qDebug()<<"4";
//        caFile.close();


//    //    std::list<Client>::iterator i;
//    ////    fstream binary_file("c:\\test.dat",ios::out|ios::binary|ios::app);
//    //    std::ofstream myFile ("data.bin", std::ios::in | std::ios::binary);
//    //    for ( i=lista.begin(); i!=lista.end();++i)
//    //    {
//    //        myFile.write(i->name, i->name.length());
//    //    }
}
