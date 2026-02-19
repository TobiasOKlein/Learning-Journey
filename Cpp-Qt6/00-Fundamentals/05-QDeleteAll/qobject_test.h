#ifndef QOBJECT_TEST_H
#define QOBJECT_TEST_H

#include <QObject>
#include <QDebug>

class QObject_test : public QObject
{
    Q_OBJECT

public:
    explicit QObject_test(QObject *parent = nullptr);
    ~QObject_test();

signals:

};

#endif // QOBJECT_TEST_H
