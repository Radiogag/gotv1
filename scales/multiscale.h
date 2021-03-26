#ifndef MULTISCALE_H
#define MULTISCALE_H

#include "scale.h"

class multiscale : public scale
{
public:
    multiscale(QVector<int> &v, int nplayers);
    QMultiMap<int,int> yoffset;
};

#endif // MULTISCALE_H
