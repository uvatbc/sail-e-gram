#include "MainWindow.h"
#include <sailfishapp.h>
#include "telegram.h"

MainWindow::MainWindow(QObject *parent)
: QObject(parent)
, m_view(SailfishApp::createView())
, m_telegram(NULL)
{
    m_view->setSource(SailfishApp::pathTo("qml/sail-e-gram.qml"));

    QTimer::singleShot(1, this, SLOT(init()));
}//MainWindow::MainWindow

MainWindow::~MainWindow()
{
    if (NULL != m_telegram) {
        delete m_telegram;
        m_telegram = NULL;
    }
}//MainWindow::~MainWindow

void
MainWindow::init()
{
    m_configDir = QDir::homePath() + "/.config/sail-e-gram";
    if (!QFileInfo(m_configDir).exists()) {
        qDebug("Had to make the config directory");

        QDir cfg(QDir::homePath() + "/.config");
        if (!cfg.exists()) {
            qWarning() << ".config dir does not exist!!";
            qApp->quit();
            return;
        }

        if (!cfg.mkdir("sail-e-gram")) {
            qWarning() << "Failed to created sail-e-gram";
            qApp->quit();
            return;
        }
    }

    m_view->rootContext()->setContextProperty("g_mainwindow", this);
    m_view->show();
}//MainWindow::init

void
MainWindow::userLoginWithPhoneNumber(const QString &number)
{
    if (!QFileInfo(":/tg.key").exists()) {
        qWarning("No tg.key?");
        qApp->quit();
        return;
    }

    QString tg = m_configDir + "/tg.key";
    QFile::copy(":/tg.key", tg);
    m_telegram = new Telegram(number, m_configDir, tg);
    QFile::remove(tg);
}//MainWindow::userLoginWithPhoneNumber
