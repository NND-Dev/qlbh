#include "person.h"


Person::Person(QObject *parent) : QObject(parent)
{
    m_name = "";
    m_age = "";
    m_salary = "";
}


Person::Person(const QString &name, const QString &age, const QString &salary, QObject *parent) : QObject{parent}, m_name(name),
    m_age(age), m_salary(salary)
{

}

void Person::setName(const QString &name)
{
    if(m_name != name)
    {
        m_name = name;
        emit nameChanged();
    }
}

void Person::setAge(const QString &age)
{
    if(m_age != age)
    {
        m_age = age;
        emit ageChanged();
    }
}

void Person::setSalary(const QString &salary)
{
    if(m_salary != salary)
    {
        m_salary = salary;
        emit salaryChanged();
    }
}

QString Person::name() const
{
    return m_name;
}

QString Person::salary() const
{
    return m_salary;
}

QString Person::age() const
{
    return m_age;
}
