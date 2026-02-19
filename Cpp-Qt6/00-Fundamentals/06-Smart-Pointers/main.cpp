/*
 * Qt Memory Management
 *
 * (Qt Smart Pointers)
 * QScopedPointer - ponteiro deletado automaticamente assim que saindo do escopo em que foi declarado
 * QSharedPointer - ponteiro compartilhado usado em mais de um local deletado ao fim da execução
 *
 * Basicamente cria um sistema de automatic garbage collection, algo extrínseco ao C++,
 * mas inerente a outras linguagens como GO.
 *
 *  https://wiki.qt.io/Smart_Pointers
 *
 */

#include <QCoreApplication>
#include <QScopedPointer>

#include "qobject_test.h"

void testScope() {
    QScopedPointer<QObject_test> ptr(new QObject_test());
    ptr->message("Hello");
    // Aqui sai do escopo e deleta o ponteiro automaticamente
}

void finish(QSharedPointer<QObject_test> ptr)
{
    ptr->message("Finished");
}

void work(QSharedPointer<QObject_test> ptr)
{
    ptr->message("Working");
}

void step(QSharedPointer<QObject_test> ptr)
{
    ptr->message("Stepping");
    for (unsigned char i = 0; i < 3; i++) {
        work(ptr);
    }
    finish(ptr);
}

void testShared(QObject_test *test) {
    QSharedPointer<QObject_test> ptr(test);
    ptr->message("Starting");
    step(ptr);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testScope();

    qInfo() << "Deletado diretamente ao fim do escopo\n";

    testShared(new QObject_test());

    qInfo() << "Deletado diretamente apos o termino da ultima funcao\nThread-safe";

    return a.exec();
}
