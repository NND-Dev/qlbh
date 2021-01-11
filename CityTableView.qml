import QtQuick 2.0
import QtQuick.Controls 1.4 as C1

C1.TableView{
    model: ListModel{
        ListElement{
            name: "Nam Dinh"
            country: "Nam Dinh"
        }
        ListElement{
            name: "Truc Noi"
            country: "Nam Dinh"
        }
        ListElement{
            name: "Thanh Xuan"
            country: "Ha Noi"
        }

    }
    C1.TableViewColumn{
        role: "name"
        title: "Name"
        width: 100
    }
    C1.TableViewColumn{
        role: "country"
        title: "Country"
        width: 100
    }
}
