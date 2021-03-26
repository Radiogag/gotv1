#include "influence.h"

influence::influence(QVector<int> &nv, int nplayers) : scale(nv,nplayers)
{
    for (int i = 1; i < players + 1; i++){
        tokens.insert(i,std::make_shared<token>(i,nv.at(5 + i),"token"));
        tokens.value(i)->pic->setPos(s.x() + (tokens.value(i)->pos - 1)*offset, s.y());
        positions.insert(nv.at(5 + i), i);
    }
}

void influence::slideTokensToTheLeft()
{
    for (int k = 0; k < 6; k++){
        for (int i = 1; i < 7; i++){
            if (!positions.value(i))
                for (int j = i; j < 6; j++){
                    positions.insert(j,positions.value(j + 1));
                    positions.remove(j + 1);
                }
        }
    }
    for (const auto &t : qAsConst(tokens)){
        t->pos = positions.key(t->house);
        t->pic->setPos(s.x() + (t->pos - 1)*offset, s.y());
    }
}
