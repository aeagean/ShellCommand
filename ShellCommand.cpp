/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/

#include "ShellCommand.h"

#include <QFile>

bool ShellCommand::execute(const QString &cmd, const QStringList &arguments)
{
    QString newCmd;
    newCmd.append(cmd);
    if (! arguments.isEmpty())
        newCmd.append(" " + arguments.join(" "));

    FILE *fp = popen(qPrintable(newCmd), "r");
    if (fp == NULL)
        return false;

    int status = pclose(fp);
    if (status == -1)
        return false;

    if (! WIFEXITED(status)) {
        return false;
    }

    // 141 == SIGPIPE
    if (WEXITSTATUS(status) != 141) {
        return false;
    }

    return true;
}

QString ShellCommand::readOutput(const QString &cmd, const QStringList &arguments)
{
    QString newCmd;
    newCmd.append(cmd);
    if (! arguments.isEmpty())
        newCmd.append(" " + arguments.join(" "));

    FILE *fp = popen(qPrintable(newCmd), "r");
    if (fp == NULL)
        return "";

    QFile file;
    if (! file.open(fp, QIODevice::ReadOnly)) {
        pclose(fp);
        return "";
    }

    QString result = QString(file.readAll()).trimmed();

    pclose(fp);

    return result;
}

QStringList ShellCommand::readOutputLines(const QString &cmd, const QStringList &arguments)
{
    return readOutput(cmd, arguments).split("\n");
}
