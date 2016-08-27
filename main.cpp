#include <QApplication>
#include <QSurfaceFormat>

#include "gamewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setMajorVersion(4);
    format.setMinorVersion(3);
    QSurfaceFormat::setDefaultFormat(format);

    GameWidget w;
    w.show();

    return a.exec();
}
