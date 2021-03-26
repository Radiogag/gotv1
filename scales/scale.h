#ifndef SCALE_H
#define SCALE_H
#include "QPoint"
#include "QString"
#include "QMap"
#include "memory"
#include "token.h"
#include "QFile"
#include "QTextStream"

class scale
{
public:
    scale(QVector<int> &v, int nplayers) : n(v.at(1)), s(v.at(2),v.at(3)), offset(v.at(4)), index(v.at(5)), players(nplayers){}
    const int n; //количество делений
    const QPoint s; //координаты начальной точки
    const int offset; //расстояние между делениями
    const int index; //индекс шкалы в файле
    QMultiMap<int, std::shared_ptr<token>> tokens; //жетоны
protected:
    const int players;
};

#endif // SCALE_H
