#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtQuick>

class MainWindow : public QObject
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = 0);
    void init();

signals:

public slots:

private:
    QQuickView *m_view;
};

#endif // MAINWINDOW_H
