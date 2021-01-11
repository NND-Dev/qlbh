#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlQuery>
#include <QtSql>
#include <QSqlDatabase>
#include <QFile>
#include <QSqlError>

#define DATABASE_NAME "qlbh"
#define DATABASE_HOSTNAME "localhost"

class DataBase : public QObject
{
    Q_OBJECT
public:
    DataBase(QObject *parent = nullptr);
    void connectDatabase();
    bool openDatabase();
    bool restoreDatabase();
    void closeDatabase();
    bool createTable();
QSqlQuery query;
public slots:
    bool insertIntoTable(const QVariantList &data);
    bool removeRecord(const int id);

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
