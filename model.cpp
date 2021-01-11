#include "model.h"


Model::Model(QObject *parent) : QSqlQueryModel(parent)
{
    mItems.append({0,"01","Vitamin C",5,25000,125000,nullptr});
    mItems.append({0,"01","Vitamin D",5,25000,125000,nullptr});
    mItems.append({0,"01","Vitamin A",5,25000,125000,nullptr});
    mItems.append({0,"01","Vitamin E",5,25000,125000,nullptr});
    mItems.append({0,"01","Vitamin K",5,25000,125000,nullptr});
}

int Model::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mItems.size();
}

int Model::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return roleNames().size();
}

QVariant Model::data(const QModelIndex &item, int role) const
{

}

