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

    void message(QString value = "");
    // QString armazena uma string de caracteres Unicode 16bits (UTF-16)

signals:

};

#endif // QOBJECT_TEST_H
