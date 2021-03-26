#ifndef UNIT_H
#define UNIT_H
#include "QGraphicsPixmapItem"
#include "QFile"

class unit
{
public:
    unit(int ntype, int nhouse);
    const int type;
    const int house;
    QGraphicsPixmapItem* pic;
};

#endif // UNIT_H
