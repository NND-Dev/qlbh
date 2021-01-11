import QtQuick 2.0
import QtQuick.Controls 1.4 as C1


C1.TableView{
    model: People
    C1.TableViewColumn{
        role: "name"
        title: "Name"
        width: 100
    }
    C1.TableViewColumn{
        role: "age"
        title: "Age"
        width: 100
    }
    C1.TableViewColumn{
        role: "salary"
        title: "Salary"
        width: 100
    }
}
