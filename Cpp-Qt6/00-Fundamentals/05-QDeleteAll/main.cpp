/*
 * Qt Memory Management
 * qDeleteAll
 *
 */

#include <QCoreApplication>
#include "qobject_test.h"

// Pega uma lista de ponteiros
typedef QList<QObject_test*> testList;

testList getList()
{
    testList list;
    for (unsigned char i = 0; i < 5; i++) {
        list.append(new QObject_test());
        list.last()->setObjectName("Test" + QString::number(i));
    }
    return list;
}

// Exibe uma lista de ponteiros
void display(testList list)
{
    foreach(QObject_test *item, list) {
        qInfo() << item;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testList list = getList();
    display(list);

    qInfo() << "Deletando...";

    // Os objetos não foram destruídos automaticamente
    //qDeleteAll(list); // Libera a memória da lista inteira
    qDeleteAll(list.begin(),list.end()); // Permite deletar apenas um pedaço específico da lista
    list.clear(); // Limpa os endereços de memória

    display(list);

    return a.exec();
}
