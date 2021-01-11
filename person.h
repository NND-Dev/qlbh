#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QVariant>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString salary READ salary WRITE setSalary NOTIFY salaryChanged)
public:
    Person(QObject *parent = nullptr);
    Person(const QString &name, const QString &age, const QString &salary, QObject *parent = nullptr);
    void setName(const QString &name);
    void setAge(const QString &age);
    void setSalary(const QString &salary);

    QString name() const;
    QString salary() const;
    QString age() const;
signals:
    void nameChanged();
    void ageChanged();
    void salaryChanged();
private:
    QString m_name;
    QString m_age;
    QString m_salary;

};

#endif // PERSON_H
