#ifndef GAME_H
#define GAME_H
#include "QWidget"
#include "qgraphicsview.h"
#include "QGraphicsItem"
#include "QGraphicsRectItem"
#include "QGraphicsPixmapItem"
#include "graphics_view_zoom.h"
#include "QTextStream"
#include "QFile"
#include "QMap"
#include "QStringList"
#include "QTextCodec"
#include "QVector"
#include "regions/land.h"
#include "regions/sea.h"
#include "regions/throneland.h"
#include "regions/port.h"
#include "scales/incremental.h"
#include "scales/multiscale.h"
#include "scales/singletoken.h"
#include "scales/ravenscale.h"
#include "scales/influence.h"

class game : public QWidget
{
public:
    game(int num);
    QMap<int, std::shared_ptr<region>> listofregions;
    QMap<int, std::shared_ptr<scale>> listofscales;
    const int numOfPlayers;
private:
    void createUnits();
    void createLands();
    void createTokens();
    void createScales();
    void createScaleCover();
    std::shared_ptr<scale> chooseAScale(int n, QVector<int> &v);
    template<class Xregion>
    std::shared_ptr<region> makeALandRegion(QStringList &list, std::set<int> &v){//создание сухопутного региона
        return std::make_shared<Xregion>(list.at(2),QPoint(list.at(8).toInt(),list.at(9).toInt()),
                                         list.at(0).toInt(),list.at(4).toInt(),list.at(5).toInt(),
                                         list.at(6).toInt(),list.at(7).toInt(), v);
    }
    template<class Xregion>
    std::shared_ptr<region> makeASeaRegion(QStringList &list, std::set<int> &v){//создание морского региона
        return std::make_shared<Xregion>(list.at(2),QPoint(list.at(8).toInt(),list.at(9).toInt()), list.at(0).toInt(), v);
    }
    QGraphicsScene scene;
    QGraphicsView v;
};

#endif // GAME_H
