#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtQuick>

class Telegram;
class TelegramEvents;

class MainWindow : public QObject
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = 0);
    virtual ~MainWindow();

private slots:
    void init();

public slots:
    void userLoginWithMSISDN(const QString &msisdn);

private:
    QQuickView     *m_view;
    QString         m_configDir;
    Telegram       *m_telegram;
    TelegramEvents *m_tgEvents;
};

#endif // MAINWINDOW_H
