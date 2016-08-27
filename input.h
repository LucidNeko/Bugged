#ifndef INPUT_H
#define INPUT_H

#include <QObject>
#include <QSet>

class Input : public QObject
{
    Q_OBJECT

public:
    static void create();

    static Input* instance() { return _instance; }

    static bool isKeyDown(Qt::Key key);

public:
    bool eventFilter(QObject* object, QEvent* event) override;

private:
    Input() { }
    ~Input();

private:
    static Input* _instance;

    static QSet<Qt::Key> _pressedKeys;
};

#endif // INPUT_H
