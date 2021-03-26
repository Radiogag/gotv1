#include "unit.h"

unit::unit(int ntype, int nhouse) : type(ntype), house(nhouse) //создание юнита нужного типа и цвета
{
    QString f = "./resources/unitpics/" + QString::number(type) + "/" + QString::number(house) + ".png";
    QFile file(f);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open unit pic file for reading");
    }
    pic = new QGraphicsPixmapItem(QPixmap::fromImage(QImage(f)));
    file.close();
}
