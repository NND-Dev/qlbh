#include "foodtablemodel.h"


FoodTableModel::FoodTableModel(QObject *parent) : QAbstractTableModel(parent)
{
    m_foods.append({"Pizza", "50000", "01"});
    m_foods.append({"Hotdog", "20000", "02"});
    m_foods.append({"Xuc Xich", "30000", "03"});
}

int FoodTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_foods.size();
}

int FoodTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return roleNames().size();
}

QVariant FoodTableModel::data(const QModelIndex &index, int role) const
{
    QVariant variant;
    const int row = index.row();
    const int col = role;
    switch (col)
    {
    case DESCRIPTION:
    {
        variant = m_foods.at(row).description;
        break;
    }
    case PRICE:
    {
        variant = m_foods.at(row).price;
        break;
    }
    case CODE:
    {
        variant = m_foods.at(row).code;
        break;
    }
    default:break;
    }
    return variant;
}

QHash<int, QByteArray> FoodTableModel::roleNames() const
{
    QHash <int, QByteArray> roles;
    roles.insert(DESCRIPTION, "description");
    roles.insert(PRICE, "price");
    roles.insert(CODE, "code");
    return roles;
}
