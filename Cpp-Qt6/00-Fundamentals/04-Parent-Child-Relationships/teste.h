#ifndef TESTE_H
#define TESTE_H

#include <QObject>
#include <QDebug>

class Teste : public QObject
{
    Q_OBJECT
public:
    explicit Teste(QObject *parent = nullptr);
    ~Teste();

signals:
};

#endif // TESTE_H
