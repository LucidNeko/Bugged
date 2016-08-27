#include "input.h"

#include <QKeyEvent>

Input* Input::_instance = nullptr;

QSet<Qt::Key> Input::_pressedKeys;

void Input::create()
{
    delete _instance;
    _instance = new Input();
}

bool Input::isKeyDown(Qt::Key key)
{
    return _pressedKeys.contains(key);
}

bool Input::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        Qt::Key key = static_cast<Qt::Key>(keyEvent->key());
        _pressedKeys.insert(key);
    }
    else if(event->type() == QEvent::KeyRelease)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        Qt::Key key = static_cast<Qt::Key>(keyEvent->key());
        _pressedKeys.remove(key);
    }
}

Input::~Input()
{
    delete _instance; // Might have to uninstall event filter before deleting.
}
