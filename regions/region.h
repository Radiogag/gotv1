#ifndef REGION_H
#define REGION_H
#include "QString"
#include "QPoint"
#include "set"
#include "QGraphicsRectItem"
#include "QBrush"
#include "QMultiMap"
#include "units/infantry.h"
#include "units/cavalry.h"
#include "units/ship.h"
#include "units/catapult.h"

class region
{
public:
    region(QString &nname, QPoint &np, int nnum, std::set<int> nborders)
        : name(nname), p(np), num(nnum), borders(nborders){
        rect->setRect(p.x(),p.y(),150,150); //рисование квадратов на поле
        rect->setBrush(QBrush(Qt::white));
        rect->setOpacity(0.3);
    };
    void createUnit(int type, int house);
    const QString name;
    const QPoint p; //white square position
    const int num;
    const std::set<int> borders;
    QGraphicsRectItem* rect = new QGraphicsRectItem;
    QMultiMap<int, std::shared_ptr<unit>> units;
private:
    template<class Xunit>
    std::shared_ptr<unit> makeAUnit(int type, int house);
};

#endif // REGION_H
