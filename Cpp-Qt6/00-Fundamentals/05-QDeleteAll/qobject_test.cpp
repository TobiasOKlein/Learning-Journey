#include "qobject_test.h"

QObject_test::QObject_test(QObject *parent) : QObject(parent)
{
    qInfo() << parent << "construindo" << this;
}

QObject_test::~QObject_test()
{
    qInfo() << parent() << "destruindo" << this;
}
