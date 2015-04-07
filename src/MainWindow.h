#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtQuick>

class Telegram;
class MainWindow : public QObject
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = 0);
    virtual ~MainWindow();

private slots:
    void init();

public slots:
    void userLoginWithPhoneNumber(const QString &number);

private:
    QQuickView *m_view;
    Telegram   *m_telegram;
    QString     m_configDir;
};

#endif // MAINWINDOW_H
