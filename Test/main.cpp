#include <QCoreApplication>
#include <QDebug>

#include "ShellCommand.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString cmd = "ls";

    qDebug()<<ShellCommand::execute(cmd);
    return a.exec();
}
