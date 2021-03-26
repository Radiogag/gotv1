#include "multiscale.h"

multiscale::multiscale(QVector<int> &nv, int nplayers) : scale(nv,nplayers)
{
    QString tok;//добавляется в название файла изображения для чтения
    if (nv.at(5) == 4)
        tok = "barrel";
    else if (nv.at(5) == 5)
        tok = "fortress";
    for (int i = 1; i < players + 1; i++){
        tokens.insert(i,std::make_shared<token>(i,nv.at(5 + i),tok));
        yoffset.insert(tokens.value(i)->pos,i);
        tokens.value(i)->pic->setPos(s.x() + (tokens.value(i)->pos - 1)*offset, s.y() - (yoffset.values(tokens.value(i)->pos).length() - 1)*offset/4);
    }
}

