#include "token.h"

token::token(int nhouse, int npos, QString type) : pos(npos), house(nhouse)
{
    QString f = "./resources/tokenpics/" + QString::number(house) + "/" + type + ".png";
    QFile file(f);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
    }
    pic = new QGraphicsPixmapItem(QPixmap::fromImage(QImage(f)));
    file.close();
}
