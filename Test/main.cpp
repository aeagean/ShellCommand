#include <QCoreApplication>
#include <QDebug>

#include "ShellCommand.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString cmd = "ls MyShellCommand";

    qDebug()<<ShellCommand::readOutput(cmd);
    return a.exec();
}
