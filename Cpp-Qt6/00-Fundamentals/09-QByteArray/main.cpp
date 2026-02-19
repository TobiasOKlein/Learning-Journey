/*
 * QByteArray
 * Uma implementação de array melhor que a C++ Padrão
 *
 * "The Best Array Ever" - Bryan Cairns
 *
 */

#include <QCoreApplication>
#include <QDebug>

void stats(QByteArray &data) // não é QObject, pode ser copiado, mas cópias são lentas
{
    qInfo() << "Length" << data.length() << "Capacity" << data.capacity();
    // data.length retorna a quantidade de bytes em um array
    // data.capacity retorna a quantidade máxima de bytes que podem ser armazenado sem forçar realocação
    qInfo() << data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Criando um array
    QByteArray stuff;
    qInfo() << stuff; // Trata como uma String, e possui encoding.

    QByteArray data("Hello"); // 7 construtores diferentes
    qInfo() << data;

    QByteArray buffer(10,'\t'); // Tab escrito em ByteArray
    qInfo() << buffer;

    QByteArray person(QString("Bryan").toLocal8Bit()); // Construindo um Byte Array a partir de uma String
                                                      // Note que a string precisou ser convertida para 8 bits
    qInfo() << person;

    // Mensurando o array
    data.reserve(25); // Tenta alocar memória para pelo menos n bytes.
    stats(data);

    data.resize(10); // Tenta aumentar o tamanho em uso se possível para n bytes, preenchendo com zeros.
                    // Sempre aumenta a capacidade se necessário, nunca diminui.
    stats(data);

    data.truncate(8); // Corta o tamanho em uso para n bytes e não altera a capacidade
    stats(data);

    data.clear(); // Limpa toda a memória alocada, zerando a capacidade
    stats(data);

    // Modificando o dado
    data.resize(5);
    data.fill('\x02'); // Preenche o array com o caractere ASCII.
    stats(data);      // Também aumenta a capacidade de memória dinamicamente;
                     // Isso pode ser um problema, mas há como ser lidado de modo mais avançado.

    data.replace(0, 1, QByteArray("Sweet")); // 6 Construtores
    // Neste caso, deveria, do endereço 0 ao 1, alocar o array desejado
    stats(data); // É possível ver que ele sobrepôs a posição
    data.replace(0, 99, QByteArray("Sweet"));
    stats(data); // Aqui percebemos que ele, de tal posição até a posição máxima, substituiu pela string desejada,
                // eliminando todo o resto dos dados.

    data.fill('*');
    data.insert(3, QByteArray("Hello World")); // 6 Construtores
    stats(data); // Preenchemos com asteriscos, e na 3ª posição inserimos a string
                // Altera ambos o tamanho e a capacidade, aumentando automaticamente nossa alocação

    data.append('!'); // 6 Construtores
    stats(data); // Adiciona o caractere ao fim da string, aumenta o tamanho, não a capacidade

    data.remove(0, 3);
    stats(data); // Os 3 primeiros caracteres foram removidos, diminuindo o tamanho mas não a capacidade

    // Lendo dados
    int first = data.indexOf('*');
    int last = data.lastIndexOf('*');
    qInfo() << "Start" << first << "End" << last;

    if (first > -1 && last > -1)
        qInfo() << data.mid(first, (last - first) + 1);

    data.clear();
    data.append("Tobias Ocean");

    for (unsigned char i = 0; i < data.length(); i++)
        qInfo() << "At" << data.at(i) << "or" << data[i]; // data.at() faz validação do range

    foreach (char c, data)
        qInfo() << "Char" << c;

    foreach (auto item, data.split(' ')) // faz a separação no caractere
        qInfo() << "Item" << item;

    // Encoding/Codificando/Formatando os dados
    qInfo() << "Normal" << data;
    qInfo() << "Repeat" << data.repeated(2);

    data.append(QByteArray("\t\r\n")); // Espaço em branco
    data.insert(0, QByteArray("   \t\t")); // Espaço em branco usuário

    qInfo() << "Actual" << data; // Nada normal, não foram formatados para Ascii;
    qInfo() << "Trimmed" << data.trimmed(); // Formatou corretamente

    data = data.trimmed();

    QByteArray hex = data.toHex();
    qInfo() << "Hex" << hex;
    QByteArray fromHex = QByteArray::fromHex(hex);
    qInfo() << "From Hex" << fromHex;

    QByteArray base64 = data.toBase64();
    qInfo() << "Base 64" << base64;
    QByteArray fromBase64 = QByteArray::fromBase64(base64);
    qInfo() << "From Base 64" << fromBase64;

    return a.exec();
}
