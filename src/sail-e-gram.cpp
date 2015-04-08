#include <sailfishapp.h>
#include "MainWindow.h"

#include <iostream>
using namespace std;

void
myQt5MessageOutput(QtMsgType type, const QMessageLogContext &ctx,
                   const QString &msg)
{
    int level = -1;
    switch (type) {
    case QtDebugMsg:
        level = 3;
        break;
    case QtWarningMsg:
        level = 2;
        break;
    case QtCriticalMsg:
        level = 1;
        break;
    case QtFatalMsg:
        level = 0;
        break;
    }

    QDateTime dt = QDateTime::currentDateTime ();
    QString m = QString("%1 : %2 : %3(%4): %5")
                    .arg(dt.toString ("yyyy-MM-dd hh:mm:ss.zzz"))
                    .arg(level)
                    .arg(ctx.function).arg(ctx.line).arg(msg);
    cout << m.toLatin1().constData() << endl;
}//myQt5MessageOutput

int
main(int argc, char *argv[])
{
    QGuiApplication *app = SailfishApp::application(argc, argv);

    qInstallMessageHandler(myQt5MessageOutput);

    MainWindow *win = new MainWindow(app);
    Q_UNUSED(win);

    int rv = app->exec();
    delete win;
    return rv;
}
