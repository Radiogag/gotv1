#ifndef TOKEN_H
#define TOKEN_H
#include "QGraphicsPixmapItem"
#include "QFile"


class token
{
public:
    token(int house, int npos, QString type);
    int pos;
    const int house;
    QGraphicsPixmapItem* pic;
};

#endif // TOKEN_H
