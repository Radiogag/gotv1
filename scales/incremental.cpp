#include "incremental.h"

incremental::incremental(QVector<int> &nv, int nplayers) : scale(nv,nplayers){
    tokens.insert(0,std::make_shared<token>(7,0,"clock"));
    tokens.value(0)->pic->setPos(s);
}

void incremental::increment(){pos++;}

