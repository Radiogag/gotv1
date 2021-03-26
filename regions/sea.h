#ifndef SEA_H
#define SEA_H
#include "region.h"


class sea : public region
{
public:
    sea(QString nname, QPoint np, int nnum, std::set<int> nborders)
        : region(nname, np, nnum, nborders){};
};

#endif // SEA_H
