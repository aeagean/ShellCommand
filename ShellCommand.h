/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/

#ifndef SHELLCOMMAND_H
#define SHELLCOMMAND_H

#include <QStringList>

class ShellCommand
{
public:
    static bool execute(const QString &cmd, const QStringList &arguments = QStringList());

    static QString readOutput(const QString &cmd, const QStringList &arguments = QStringList());

    static QStringList readOutputLines(const QString &cmd, const QStringList &arguments = QStringList());
};

#endif // SHELLCOMMAND_H
