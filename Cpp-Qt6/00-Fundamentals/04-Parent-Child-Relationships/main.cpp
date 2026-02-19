/*
 * Qt Memory Management
 * Parent Child Relationship
 */

#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

#include "teste.h"

// Configurando no contrutor
Teste* getTeste(QObject* parent)
{
    return new Teste(parent);
    // Cria um novo objeto em memória, filho de 'parent'
}

// Configurando depois do construtor
Teste* getTeste()
{
    return new Teste(); // Sem classe pai
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer;
    timer.singleShot(3000, &a, &QCoreApplication::quit);
    // 3 segundos de pausa, endereço da aplicação, método de slot (encaixe, callback da interrupção)

    // Configurando no construtor
    Teste *dog = getTeste(&a);
    dog->setObjectName("Bob");

    // Configurando depois do construtor
    Teste *cat = getTeste();
    cat->setObjectName("Gato");
    cat->setParent(dog);

    int valor = a.exec(); // Loop
    qInfo() << "Codigo de saida:" << valor;
    return valor;
}
