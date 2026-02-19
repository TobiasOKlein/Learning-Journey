#include <QCoreApplication>

#include <iostream>
#include <string>

#include <QTextStream>
#include <QDebug>

void do_cpp() {
    std::string name;
    std::cout << "Please enter your name: ";
    std::getline(std::cin,name);
    std::cout << "Hello " << name << "\n";
}

void do_qt() {
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout << "Please enter your name: ";
    qout.flush();
    QString name = qin.readLine();
    qout << "Hello " << name;
    qout.flush();
}

void do_mixed() {
    QTextStream qin(stdin);
    qInfo() << "Please enter your name:";
    QString name = qin.readLine();
    qInfo() << "Hello" << name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    //do_cpp();
    //do_qt();
    do_mixed();

    return a.exec();
}
