
#include <QApplication>
#include <iostream>
#include "stock.h"
#include "dialog.h"
#include "pathselect.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    /*获取文件路径*/
    PathSelect path;
    path.show();
    return app.exec();
}
