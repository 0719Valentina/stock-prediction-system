QT       += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    child1.cpp \
    child2.cpp \
    dialog.cpp \
    main.cpp \
    minheap.cpp \
    pathselect.cpp \
    predict.cpp \
    qcustomplot.cpp \
    stock.cpp

HEADERS += \
    child1.h \
    child2.h \
    dialog.h \
    minheap.h \
    minnode.h \
    pathselect.h \
    predict.h \
    qcustomplot.h \
    stock.h

FORMS += \
    child1.ui \
    child2.ui \
    dialog.ui \
    pathselect.ui \
    predict.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QMAKE_CXXFLAGS += -Wa,-mbig-obj
QMAKE_CXXFLAGS_RELEASE += -mavx

LIBS+="C:\Program Files (x86)\dlib\lib\libdlib.a"
INCLUDEPATH+="C:\Program Files (x86)\dlib\include"

RESOURCES += \
    ../Pics/new.qrc
