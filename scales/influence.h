#ifndef INFLUENCE_H
#define INFLUENCE_H
#include "scale.h"

class influence : public scale
{
public:
    influence(QVector<int> &nv, int nplayers);
    QMap<int, int> positions; //возврат индекса дома по его позиции
    void slideTokensToTheLeft();
};

#endif // INFLUENCE_H
