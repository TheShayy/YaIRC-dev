#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QTranslator>

int main(int argc, char *argv[])
{
    #if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    #else
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    #endif

    QApplication a(argc, argv);
    QTranslator french;
    french.load(a.applicationDirPath() + "/translations/qt_fr.qm");
    a.installTranslator(&french);
    MainWindow w;
    w.show();

    return a.exec();
}
