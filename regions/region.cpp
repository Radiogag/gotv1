#include "region.h"

template <class Xunit> std::shared_ptr<unit> region::makeAUnit(int type, int house) {//создание юнита заданного подвида
    return std::make_shared<Xunit>(type, house);
}

void region::createUnit(int type, int house)//создание юнита
{
    std::shared_ptr<unit> unitmakers[] = {makeAUnit<catapult>(type, house), makeAUnit<infantry>(type, house),
                                          makeAUnit<cavalry>(type, house), makeAUnit<ship>(type, house)};
    std::shared_ptr<unit> u = unitmakers[type];
    units.insert(u->type,u);
    units.value(u->type)->pic->setPos(p.x() + units.size()*30, p.y());
}
