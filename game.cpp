#include "game.h"

game::game(int num) : numOfPlayers(num) //фон, запуск
{
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("./resources/Map61.png")));
    scene.addItem(item);
    Graphics_view_zoom* z = new Graphics_view_zoom(&v, this);
    z->set_modifiers(Qt::NoModifier);
    createLands();//создание структур территорий
    createUnits();//добавление юнитов
    createScales();//создание треков и их заполнение
    v.setScene(&scene);
    v.fitInView(QRect(0,0,2400,1800));
    v.showFullScreen();
}

void game::createLands(){ //создание структур данных карты
    QFile file("./resources/listofregions2.txt");//описание карты
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QStringList list = in.readLine().split(";");
        std::set<int> v;
        QStringList lb = list.at(3).split(","); //список смежных территорий
        for (const auto &i : qAsConst(lb))
            v.insert(i.toInt());
        std::shared_ptr<region> regionmakers[] = {makeALandRegion<throneLand>(list,v), makeALandRegion<land>(list,v),
                                                  makeASeaRegion<sea>(list,v), makeASeaRegion<port>(list,v)};
        listofregions[list.at(0).toInt()] = regionmakers[list.at(1).toInt()];
        scene.addItem(listofregions[list.at(0).toInt()]->rect); //белые квадраты
    }
    file.close();
}

void game::createUnits(){ //начальная расстановка юнитов игроков (как указано на ширмах)

    for (int i = 1; i < numOfPlayers + 1; i++){
        QFile file("./resources/rasstanov/" + QString::number(i) + ".csv");
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning("Cannot open file for reading");
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            QStringList list = in.readLine().split(";");
            for (int j = 0; j < list.at(2).toInt(); j++){
                listofregions[list.at(0).toInt()]->createUnit(list.at(1).toInt(),i);
                scene.addItem(listofregions[list.at(0).toInt()]->units.value(list.at(1).toInt())->pic);//добавляем изображение юнита
            }
        }
    }
}

std::shared_ptr<scale> game::chooseAScale(int n, QVector<int> &v){
    switch (n) {
    case 0 : {return std::make_shared<multiscale>(v, numOfPlayers);}
    case 1 : {return std::make_shared<incremental>(v, numOfPlayers);}
    case 2 : {return std::make_shared<singletoken>(v, numOfPlayers);}
    case 3 : {return std::make_shared<ravenscale>(v, numOfPlayers);}
    case 4 : {return std::make_shared<influence>(v, numOfPlayers);}
    default: {return nullptr;}
    }
}

void game::createScales(){//инициализация шкал
    QFile file("./resources/tokenscales.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QStringList list = in.readLine().split(";");
        QVector<int> v;
        for (const auto &n : qAsConst(list))
            v.push_back(n.toInt());
        listofscales.insert(v.at(5),chooseAScale(v.at(0),v));
    }
    for (int i = 1; i < 4; i++){
        std::static_pointer_cast<influence>(listofscales.value(i))->slideTokensToTheLeft();
    }
    createScaleCover();
    for (const auto &l : qAsConst(listofscales))
        for (const auto &t : qAsConst(l->tokens))
            scene.addItem(t->pic);
    file.close();
}

void game::createScaleCover(){//добавляем накладку на шкалу королевского ворона (если < 5 игроков) и записываем количество звезд
    QVector<int> vec;
    QFile file;
    if (numOfPlayers < 5){
        file.setFileName("./resources/stars2.txt");
        QString f = "./resources/cover2.jpg";
        QFile picfile(f);
        if (!picfile.open(QIODevice::ReadOnly)) {
            qWarning("Cannot open file for reading");
        }
        QGraphicsPixmapItem* pic = new QGraphicsPixmapItem(QPixmap::fromImage(QImage(f)));
        pic->setPos(1695,320);
        scene.addItem(pic);
    }
    else {
        file.setFileName("./resources/stars1.txt");
    }
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
    }
    QTextStream in(&file);
    QStringList list = in.readLine().split(";");
    for (const auto &n : qAsConst(list))
        vec.push_back(n.toInt());
    std::static_pointer_cast<ravenscale>(listofscales.value(3))->setStars(vec);
    file.close();
}
//сделать dynamic_pointer_cast
