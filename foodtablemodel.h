#ifndef FOODTABLEMODEL_H
#define FOODTABLEMODEL_H

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QHash>
#include <QList>

struct Food
{
    QString description;
    QString price;
    QString code;
};

class FoodTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:

    enum RoleName{
        DESCRIPTION = 0,
        PRICE = 1,
        CODE
    };
    FoodTableModel(QObject *parent = nullptr);

    Q_INVOKABLE  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE  int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE QHash<int,QByteArray> roleNames() const override;

private:
    QList <Food> m_foods;
};

#endif // FOODTABLEMODEL_H
