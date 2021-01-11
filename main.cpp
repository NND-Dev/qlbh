#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "person.h"
#include "foodtablemodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QObjectList People;
    People.append(new Person("Nguyen Nhat Duy", "23","90000000"));
    People.append(new Person("Nguyen Thi Thu Phuong", "23","50000000"));
    People.append(new Person("Nguyen Nhat Duy", "23","50000000"));
    People.append(new Person("Nguyen Thi Thu Phuong", "23","50000000"));

    engine.rootContext()->setContextProperty("People", QVariant::fromValue(People));

    FoodTableModel *foods = new FoodTableModel;
    engine.rootContext()->setContextProperty("foods", foods);


    const QUrl url("qrc:/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
