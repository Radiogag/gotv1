#ifndef PLAYER_H
#define PLAYER_H
#include "QString"

class player
{
public:
    player();
    QString getName(){return name;}
    void setName(QString newName){name = newName;}
private:
    int power = 5;
    QString name;
};
#endif // PLAYER_H
