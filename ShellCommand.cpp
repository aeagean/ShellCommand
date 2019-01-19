/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/

#include "ShellCommand.h"

#include <QFile>

bool ShellCommand::execute(const QString &cmd, const QStringList &arguments)
{
    QString result = "";
    return execute(cmd, arguments, result);
}

QString ShellCommand::readOutput(const QString &cmd, const QStringList &arguments)
{
    QString result = "";
    execute(cmd, arguments, result);

    return result;
}

QStringList ShellCommand::readOutputLines(const QString &cmd, const QStringList &arguments)
{
    QStringList results;
    results = readOutput(cmd, arguments).trimmed().split("\n");

    return results;
}

bool ShellCommand::execute(const QString &cmd, const QStringList &arguments, QString &result)
{
    QString newCmd;
    newCmd.append(cmd);
    if (! arguments.isEmpty())
        newCmd.append(" " + arguments.join(" "));

    FILE *fp = popen(qPrintable(newCmd), "r");
    if (fp == NULL)
        return false;

    QFile file;
    if (! file.open(fp, QIODevice::ReadOnly)) {
        pclose(fp);
        return "";
    }

    result = QString(file.readAll()).trimmed();

    file.close();

    int status = pclose(fp);
    fp = NULL;

    if (status == -1 ||
        !WIFEXITED(status) ||
        WEXITSTATUS(status) != 0) {
        return false;
    }

    return true;
}
