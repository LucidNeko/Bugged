#ifndef PLAYER_H
#define PLAYER_H

#include <QVector2D>

#include "time.h"

class Player
{
public:
    Player();
    ~Player();

    void update(const Time& time);
    void render(const Time& time);

private:
    QVector2D _position;
    QVector2D _movespeed;
};

#endif // PLAYER_H
