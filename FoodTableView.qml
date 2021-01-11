import QtQuick 2.0
import QtQuick.Controls 1.4 as C1


C1.TableView{
    model: foods
    C1.TableViewColumn{
        role: "description"
        title: "Description"
        width: 100
    }
    C1.TableViewColumn{
        role: "price"
        title: "Price"
        width: 100
    }
    C1.TableViewColumn{
        role: "code"
        title: "Code"
        width: 100
    }
}
