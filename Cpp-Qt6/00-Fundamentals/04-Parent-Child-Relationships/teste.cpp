#include "teste.h"

Teste::Teste(QObject *parent) : QObject{parent}
{
    qInfo() << parent << "Constructed" << this;
}

Teste::~Teste()
{
    foreach(QObject *child, children()) {
        qInfo() << this << " have the child " << child;
    }

    qInfo() << parent() << "Deconstructed" << this;
    // Tem que usar como função para pegar o ponteiro para o objeto
}
