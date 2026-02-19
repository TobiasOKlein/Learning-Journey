/*
 * QString - Classe Qt String
 * Relacionado a QChar
 *
 */


#include <QCoreApplication>
#include <QDebug>
#include <iostream>

void test(QString data)
{
    qInfo() << "Copia da QString:" << data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Criando
    QString line("Hello World"); // 12 opções de parametrização da construção
    qInfo() << line;

    QString name;
    name = "Tobias Klein";
    qInfo() << name;

    int pos = 416;
    int max = 505;
    QString status = QString("Processanto arquivo %1 de %2").arg(pos).arg(max); // Substituindo os argumentos em cadeia
    qInfo() << status;


    // Lendo cada caractere
    for(unsigned char i = 0; i < line.length(); i++) { // Tudo bem intuitivo em Qt
        QChar c = line.at(i);
        qInfo() << c;
    }

    // QString é impresso em aspas duplas
    // QChar é impresso em aspas simples

    // Comparando e Procurando
    qInfo() << "Compare" << line.compare("hello world", Qt::CaseSensitivity::CaseSensitive);
    qInfo() << "Starts" << line.startsWith("hello", Qt::CaseInsensitive);

    // Insensibilidade ignora maiúsculas e minúsculas

    qInfo() << "Ends" << line.endsWith("world", Qt::CaseInsensitive);
    qInfo() << "Contains" << line.contains("world");
    qInfo() << "Where is \"World\" ?" << line.indexOf("World");

    // Modificando e separando
    line.append("\r\nHow are you?");
    qInfo() << "Escape" << line;

    line.append("\r\n<i>This</i>is HTML <br>");
    qInfo() << "Html" << line.toHtmlEscaped();

    line.replace("?", "!");
    qInfo() << "Replaced" << line;

    qInfo() << "Upper" << line.toUpper();
    qInfo() << "Lower" << line.toLower();
    qInfo() << "Mid" << line.mid(3,5);

    // Cria uma lista de QStrings com quebra no caractere desejado
    QStringList list = line.split("\n");
    foreach(QString item, list) {
        qInfo() << "item" << item.trimmed(); // trimmed remove caracteres sem forma
    }

    // Conversão
    std::cout << "std " << line.toStdString() << std::endl; // std::cout não sabe o que é QString, precisa usar o método de converter

    qInfo() << "UTF8" << line.toUtf8(); // transforma em QByteArray
    qInfo() << "Base64" << line.toUtf8().toBase64();
    qInfo() << "Hex" << line.toUtf8().toHex();

    // Não é um objeto

    test(line);

    return a.exec();
}
