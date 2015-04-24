# sail-e-gram
Telegram for Sailfish

I got tired of waiting for a reasonable native Telegram client for Sailfish and started writing one myself.
Lets see how far this goes.

To compile:
1. bzr branch lp:libqtelegram
2. Open sail-e-gram.pro in qtcreator-sailfish
3. Begin the compile!


To compile libqtelegram: Start from ubuntu:14.10
apt-get update ; apt-get upgrade --assume-yes ; apt-get install --assume-yes bzr cppcheck dh-exec cmake libphonon4qt5-dev qtmultimedia5-dev libthumbnailer-dev libssl-dev qtdeclarative5-dev-tools qtdeclarative5-private-dev pkg-config libmediainfo-dev libsqlite3-dev ; apt-get build-dep qtcreator
rm -rf libqtelegram ; bzr branch lp:libqtelegram
cd libqtelegram ; rm -rf bld ; mkdir bld ; cd bld
cmake -DCMAKE_INSTALL_PREFIX=./usr -DCMAKE_INSTALL_LIBDIR=lib/x86_64-linux-gnu/ ..
