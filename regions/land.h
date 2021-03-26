#ifndef LAND_H
#define LAND_H
#include "region.h"


class land : public region
{
public:
    land(QString nname, QPoint np, int nnum, int nfood, int ncrowns, int ncastles, int nfortresses, std::set<int> nborders)
        : region(nname, np, nnum, nborders), food(nfood),crowns(ncrowns),castles(ncastles),fortresses(nfortresses){};
    const int food;
    const int crowns;
    const int castles;
    const int fortresses;
private:
    int neutralDefense;
};

#endif // LAND_H
