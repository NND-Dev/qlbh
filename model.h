#ifndef MODEL_H
#define MODEL_H
#include <QSqlQueryModel>
#include <QString>
#include <QObject>
#include <QList>

struct QLBH
{
    int id;
    QString maSanPham;
    QString tenSanPham;
    int soLuong;
    int donGia;
    int thanhTien;
    QString ghiChu;
};

class Model : public QSqlQueryModel{
    Q_OBJECT
public:
    Model(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

private:
    QList<QLBH> mItems;
};

#endif // MODEL_H
