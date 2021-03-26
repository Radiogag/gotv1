#include "ravenscale.h"

ravenscale::ravenscale(QVector<int>&nv, int nplayers) : influence(nv,nplayers)
{

}

void ravenscale::setStars(QVector<int> &arr)
{
    stars = arr;
}

int ravenscale::getStar(int pos)
{
    return stars.at(pos);
}

