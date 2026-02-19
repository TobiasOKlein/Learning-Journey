#include "qobject_test.h"

QObject_Test::QObject_Test(QObject *parent)
    : QObject{parent}
{}

void QObject_Test::dostuff()
{
    qInfo() << "Interrupcao!";
    emit close(); // Emite a flag de close
}
