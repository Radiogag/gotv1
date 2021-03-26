#ifndef RAVENSCALE_H
#define RAVENSCALE_H
#include "influence.h"


class ravenscale : public influence
{
public:
    ravenscale(QVector<int> &v, int nplayers);
    void setStars(QVector<int> &arr);
    int getStar(int pos);
private:
    QVector<int> stars;
};

#endif // RAVENSCALE_H
