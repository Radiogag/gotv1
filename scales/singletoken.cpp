#include "singletoken.h"

singletoken::singletoken(QVector<int> &nv, int nplayers) : scale(nv,nplayers)
{
    tokens.insert(0,std::make_shared<token>(8,1,"beast"));
    tokens.value(0)->pic->setPos(s.x() + offset*tokens.value(0)->pos, s.y());
}
