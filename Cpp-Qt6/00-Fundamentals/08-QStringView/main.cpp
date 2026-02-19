/*
 * QStringView
 *
 * Provides a unified view on UTF-16 strings with read-only.
 * References a contiguos portion of a UTF-16 string it does not own.
 * It acts as an interface type to all kinds of UTF-16 string, without
 * the need to construct a QString first.
 *
 * Its faster than copying a QString, and its read only!
 *
 */

#include <QCoreApplication>
#include <QDebug>

void readname1(QString name) // cria uma cópia - cópias são lentas!!
{
    name.insert(0, "Mr.");
    qInfo() << "Changed" << name; // altera somente a cópia
}

void readname2(QString &name) // endereço de é acesso de
{
    name.insert(0, "Mr.");
    qInfo() << "Changed" << name; // está modificamendo a string original!!
}

void readonly(QStringView name)
{
    qInfo() << "Name" << name.data() << name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString firstname = "Bryan";
    QString lastname = "Cairns";

    // Copy and modification issues
    readname1(firstname);
    qInfo() << "Original" << firstname;

    //readname2(firstname);
    //qInfo() << "Original" << firstname;

    // Read only, no copy
    qInfo() << "Name" << firstname.data() << firstname;
    readonly(firstname);

    // Basic Parsing

    QString fullname = firstname + " " + lastname;
    foreach(QStringView part, QStringView(fullname).split(QChar(' '))) { // uma lista de view-only strings
                                                                        // separadas nos QChar de espaço
        qInfo() << "Parte:" << part;

        // Data types can get a bit annoying
        if (part.startsWith(QStringView(firstname), Qt::CaseInsensitive)) { // não dá pra fazer part.startsWith(firstname) diretamentew
            qInfo() << "~Primeiro nome detectado~";
            readonly(QStringView(firstname).mid(1,3)); // não dá pra fazer readonly(firstname) diretamente)
        }
    } // Apesar disso, é extremamente simples, intuitivo e seguro de usar. Não dá espaço nenhum para erro no código

    return a.exec();
}
