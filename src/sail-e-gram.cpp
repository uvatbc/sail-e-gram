#include <sailfishapp.h>
#include <QtQuick>

int
main(int argc, char *argv[])
{
    QGuiApplication *app = SailfishApp::application(argc, argv);
    QQuickView *view = SailfishApp::createView();
    view->setSource(SailfishApp::pathTo("qml/sail-e-gram.qml"));
    view->show();

    return app->exec();
}
