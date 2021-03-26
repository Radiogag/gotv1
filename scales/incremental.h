#ifndef INCREMENTAL_H
#define INCREMENTAL_H

#include "scale.h"

class incremental : public scale
{
public:
    incremental(QVector<int> &v, int nplayers);
    void increment();
    QGraphicsPixmapItem pic;
private:
    int pos = 0;
};

#endif // INCREMENTAL_H
