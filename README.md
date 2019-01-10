# ShellCommand
```c++
class ShellCommand
{
public:
    static bool execute(const QString &cmd, const QStringList &arguments = QStringList());

    static QString readOutput(const QString &cmd, const QStringList &arguments = QStringList());

    static QStringList readOutputLines(const QString &cmd, const QStringList &arguments = QStringList());
};
```
