#ifndef PORT_H
#define PORT_H
#include "region.h"

class port : public region
{
public:
    port(QString nname, QPoint np, int nnum, std::set<int> nborders)
        : region(nname, np, nnum, nborders){};
};

#endif // PORT_H
