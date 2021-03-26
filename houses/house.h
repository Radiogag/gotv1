#ifndef HOUSE_H
#define HOUSE_H

#include "QString"

class house
{
public:
    house();
    QString getName(){return name;}
protected:
    QString name;
    int money = 5;
};

#endif // HOUSE_H
