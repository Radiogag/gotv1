#ifndef THRONELAND_H
#define THRONELAND_H
#include "land.h"

class throneLand : public land
{
public:
    throneLand(QString nname, QPoint np, int nnum, int nfood, int ncrowns, int ncastles, int nfortresses, std::set<int> nborders)
        : land(nname, np, nnum, nfood, ncrowns, ncastles, nfortresses, nborders){};
};

#endif // THRONELAND_H
