QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    $$files(units/*.cpp) \
    $$files(regions/*.cpp) \
    $$files(scales/*.cpp) \
    $$files(houses/*.cpp) \
    $$files(orders/*.cpp) \
    game.cpp \
    graphics_view_zoom.cpp \
    main.cpp \
    player.cpp \
    token.cpp

HEADERS += \
    $$files(units/*.h) \
    $$files(regions/*.h) \
    $$files(scales/*.h) \
    $$files(houses/*.h) \
    $$files(orders/*.h) \
    game.h \
    graphics_view_zoom.h \
    player.h \
    token.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
