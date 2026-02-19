#include <QCoreApplication>
#include <QDebug>

#include "qobject_test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject_Test test;

    // Conecta o sinal e o slot
    //QObject::connect(&test, &QObject_Test::close, &a, &QCoreApplication::quit);
    //               transmissor, sinal/flag, recebedor, callback

    QObject::connect(&test, &QObject_Test::close, &a, &QCoreApplication::quit, Qt::QueuedConnection);
    // para trabalhar com QCoreApplication especificamente precisamos de um parametro extra para conectar

    // Quando nosso objeto chamar a flag do método close, queremos 'a' execute o método quit

    test.dostuff(); // metodo que emite a flag

    int saida = a.exec();

    qInfo() << "Valor de saida:" << saida;

    return saida;
}
