#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <QObject>
#include <list>
#include <model/client.h>

class SaveFile : public QObject
{
    Q_OBJECT
public:
    explicit SaveFile(QObject *parent = nullptr);
    void saveToFile();
    std::list<Client> loadClientsFromFile();
    void saveClientsToFile(std::list<Client> clients);


signals:

public slots:
};

#endif // SAVEFILE_H
