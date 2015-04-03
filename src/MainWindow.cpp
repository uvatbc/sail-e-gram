#include "MainWindow.h"
#include <sailfishapp.h>

MainWindow::MainWindow(QObject *parent)
: QObject(parent)
, m_view(SailfishApp::createView())
{
    m_view->setSource(SailfishApp::pathTo("qml/sail-e-gram.qml"));
}//MainWindow::MainWindow

void
MainWindow::init()
{
    m_view->show();
}//MainWindow::init
