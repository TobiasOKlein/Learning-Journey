#ifndef QOBJECT_TEST_H
#define QOBJECT_TEST_H

#include <QObject>
#include <QDebug>

class QObject_Test : public QObject
{
    Q_OBJECT // Meta Object Compiler - identifica no Pré-processamento que a classe
    // precisa ser convertida para um objeto Qt

    /*
     * Source Code -> Preprocessor    Compiler -> Linker
     *                     |             ^
     *                     v             |
     *                    MOC -----------
     *
     */

public:
    explicit QObject_Test(QObject *parent = nullptr);

signals: // sinal/flag de interrupção
    void close();

public slots: // chamada de interrupção
    void dostuff(); // precisa ser implementado
};

#endif // QOBJECT_TEST_H
