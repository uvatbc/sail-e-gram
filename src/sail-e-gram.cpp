#include <sailfishapp.h>
#include "MainWindow.h"

int
main(int argc, char *argv[])
{
    QGuiApplication *app = SailfishApp::application(argc, argv);

    MainWindow *win = new MainWindow(app);
    win->init();

    return app->exec();
}
