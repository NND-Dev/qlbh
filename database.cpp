#include "database.h"


DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

void DataBase::connectDatabase()
{
    if(QFile("D:/SHOP/" DATABASE_NAME).exists())
    {
        this->restoreDatabase();
    }
    else{
        this->openDatabase();
    }
}

bool DataBase::openDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("D:/SHOP/" DATABASE_NAME);
    if(!db.open())
    {
        return false;
    }
    return true;
}

bool DataBase::restoreDatabase()
{
    if(this->openDatabase())
    {
        return (this->createTable() ? true : false);
    }
    else {
        return false;
    }
}

void DataBase::closeDatabase()
{
    db.close();
}

bool DataBase::createTable()
{
    QSqlQuery query;
    QString sQuery("CREATE TABLE TABLE ("
                   "ID INT PRIMARY KEY AUTOINCREMENT,"
                   "MaHangHoa VARCHAR(50) NOT NULL,"
                   "TenHangHoa VARCHAR(50) NOT NULL,"
                   "SoLuong INT NOT NULL,"
                   "DonGia VARCHAR(50) NOT NULL,"
                   "ThanhTien INT NOT NULL,"
                   "GhiChu TEXT");
    if(!query.exec(sQuery))
    {
        qDebug() << "Database can not create: " << query.lastError().text();
        return false;
    }
    else{
        return true;
    }
    return true;
}

bool DataBase::insertIntoTable(const QVariantList &data)
{

}

bool DataBase::removeRecord(const int id)
{

}
